// pacman.cpp
// Minimal Pac-Man clone for macOS Terminal
// Compile: g++ -std=c++17 -O2 -Wall -o pacman pacman.cpp
// Run: ./pacman
//
// Controls: Arrow keys or WASD to move, q to quit.

#include <iostream>
#include <random>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <signal.h>

using namespace std;

// Terminal utilities
struct Term {
    termios orig{};
    bool active=false;
    void enableRaw() {
        if(active) return;
        if(tcgetattr(STDIN_FILENO, &orig) == -1) return;
        termios raw = orig;
        raw.c_lflag &= ~(ECHO | ICANON | ISIG);
        raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
        raw.c_oflag &= ~(OPOST);
        raw.c_cc[VMIN] = 0;
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
        active = true;
    }
    void restore() {
        if(!active) return;
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
        active = false;
    }
    ~Term(){ restore(); }
} term;

volatile sig_atomic_t got_sigint = 0;
void handle_sigint(int){ got_sigint = 1; }

// low-level write
void w(const string &s){ write(STDOUT_FILENO, s.c_str(), s.size()); }
void clearScreen(){ w("\x1b[2J"); }
void moveCursor(int r,int c){ char buf[64]; int n=snprintf(buf,sizeof(buf),"\x1b[%d;%dH", r, c); write(STDOUT_FILENO, buf, n); }
void hideCursor(){ w("\x1b[?25l"); }
void showCursor(){ w("\x1b[?25h"); }
int getRows(){ winsize ws; if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws)==-1) return 24; return ws.ws_row; }
int getCols(){ winsize ws; if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws)==-1) return 80; return ws.ws_col; }

// input (non-blocking, reads up to 8 bytes)
bool readInput(vector<unsigned char>& out, int timeout_ms){
    fd_set fds; FD_ZERO(&fds); FD_SET(STDIN_FILENO, &fds);
    timeval tv{timeout_ms/1000, (timeout_ms%1000)*1000};
    int rv = select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    if(rv <= 0) return false;
    unsigned char buf[16]; ssize_t n = read(STDIN_FILENO, buf, sizeof(buf));
    if(n <= 0) return false;
    out.assign(buf, buf + n);
    return true;
}

// Map legend
// '#' wall
// '.' pellet
// 'o' power pellet
// ' ' empty / path
// We will draw pacman as @, ghosts as letters, pellets with color.
vector<string> levelTemplate = {
    "####################",
    "#........##........#",
    "#.##.###.##.###.##.#",
    "#o##.###.##.###.##o#",
    "#..................#",
    "#.##.#.######.#.##.#",
    "#....#...##...#....#",
    "####.### ## ###.####",
    "   #.#       #.#    ",
    "####.# ##### #.####",
    "    .  #   #  .    ",
    "####.# ##### #.####",
    "   #.#       #.#    ",
    "####.# ##### #.####",
    "#........##........#",
    "#.##.###.##.###.##.#",
    "#o..#..........#..o#",
    "####################"
};

// Entities and game state
struct Pos { int r,c; bool operator==(Pos const& o) const { return r==o.r && c==o.c; } };

enum Dir { UP, DOWN, LEFT, RIGHT, NONE };
Pos dirDelta(Dir d){
    if(d==UP) return {-1,0};
    if(d==DOWN) return {1,0};
    if(d==LEFT) return {0,-1};
    if(d==RIGHT) return {0,1};
    return {0,0};
}
Dir opposite(Dir d){
    if(d==UP) return DOWN;
    if(d==DOWN) return UP;
    if(d==LEFT) return RIGHT;
    if(d==RIGHT) return LEFT;
    return NONE;
}

struct Ghost {
    Pos p;
    Dir dir = LEFT;
    char ch;
    bool frightened = false;
    bool eaten = false; // when eaten, returns to house
    Ghost(char c='G'): ch(c) {}
};

struct Game {
    vector<string> map;
    int rows, cols;
    Pos pac;
    Dir pacNext = NONE;
    Dir pacDir = NONE;
    vector<Ghost> ghosts;
    int score = 0;
    int pelletsRemaining = 0;
    int lives = 3;
    int level = 1;
    int tick = 0;
    int frightTicks = 0; // remaining ticks frightened
    mt19937 rng;
    Pos ghostHouse{9,10}; // respawn location
    Game(): rng((unsigned)time(NULL)) {
        loadLevel();
    }

    void loadLevel(){
        map = levelTemplate;
        rows = map.size();
        cols = map[0].size();
        // center pacman
        pac = {13,9};
        pacDir = LEFT; pacNext = LEFT;
        ghosts.clear();
        ghosts.emplace_back('B'); ghosts[0].p = {9,9}; // Blinky-like
        ghosts.emplace_back('P'); ghosts[1].p = {9,10}; // Pinky-like
        ghosts.emplace_back('I'); ghosts[2].p = {8,9}; // Inky-like
        ghosts.emplace_back('C'); ghosts[3].p = {8,10}; // Clyde-like
        frightTicks = 0;
        pelletsRemaining = 0;
        score = 0;
        for(int r=0;r<rows;r++) for(int c=0;c<cols;c++){
            if(map[r][c]=='.') pelletsRemaining++;
            if(map[r][c]=='o') pelletsRemaining++;
        }
    }

    bool inBounds(Pos p) const {
        return p.r >= 0 && p.r < rows && p.c >= 0 && p.c < cols;
    }
    bool isWall(Pos p) const {
        if(!inBounds(p)) return true;
        return map[p.r][p.c] == '#';
    }
    bool canEnter(Pos p) const {
        if(!inBounds(p)) return false;
        char ch = map[p.r][p.c];
        return ch != '#';
    }

    void draw() {
        clearScreen();
        moveCursor(1,1);
        string hdr = " Pac-Man (mini)  Score: " + to_string(score)
                   + "  Lives: " + to_string(lives)
                   + "  Level: " + to_string(level) + "\r\n";
        w(hdr);

        for (int r = 0; r < rows; r++) {
            moveCursor(r + 2, 1); // move to start of line explicitly
            for (int c = 0; c < cols; c++) {
                Pos cur{r, c};
                bool drawn = false;
                if (pac == cur) {
                    w("\x1b[33m@\x1b[0m"); drawn = true;
                } else {
                    for (auto &g : ghosts)
                        if (g.p == cur && !g.eaten) {
                            if (g.frightened) w("\x1b[34m?\x1b[0m");
                            else {
                                const char* col = "\x1b[31m";
                                if (g.ch=='P') col="\x1b[35m";
                                if (g.ch=='I') col="\x1b[36m";
                                if (g.ch=='C') col="\x1b[33m";
                                w(string(col) + g.ch + "\x1b[0m");
                            }
                            drawn = true; break;
                        }
                }
                if (drawn) continue;
                char m = map[r][c];
                if (m == '#') w("\x1b[37m#\x1b[0m");
                else if (m == '.') w("\x1b[90m.\x1b[0m");
                else if (m == 'o') w("\x1b[93mo\x1b[0m");
                else w(" ");
            }
        }
        moveCursor(rows + 3, 1);
        w(" Controls: Arrows/WASD to move, q to quit\r\n");
        fflush(stdout);
    }

    // process keyboard bytes to set pacNext / quit
    bool handleInput(const vector<unsigned char>& in){
        if(in.empty()) return true;
        // arrow keys are ESC [ A/B/C/D
        if(in[0]==27 && in.size()>=3 && in[1]==91){
            unsigned char k = in[2];
            if(k=='A') pacNext = UP;
            else if(k=='B') pacNext = DOWN;
            else if(k=='C') pacNext = RIGHT;
            else if(k=='D') pacNext = LEFT;
        } else {
            unsigned char k = in[0];
            if(k=='w' || k=='W') pacNext = UP;
            else if(k=='s' || k=='S') pacNext = DOWN;
            else if(k=='a' || k=='A') pacNext = LEFT;
            else if(k=='d' || k=='D') pacNext = RIGHT;
            else if(k=='q' || k=='Q') return false;
        }
        return true;
    }

    // try to change direction if next direction is valid (no wall)
    void tryApplyNextDir(){
        if(pacNext == NONE) return;
        Pos d = dirDelta(pacNext);
        Pos np{pac.r + d.r, pac.c + d.c};
        if(canEnter(np)) pacDir = pacNext;
    }

    void movePac(){
        tryApplyNextDir();
        if(pacDir == NONE) return;
        Pos d = dirDelta(pacDir);
        Pos np{pac.r + d.r, pac.c + d.c};
        if(canEnter(np)) pac = np;
        // wrap tunnel if we allow; in this small map edges are walls/no wrap
        // pellets
        char &cell = map[pac.r][pac.c];
        if(cell == '.'){ score += 10; cell = ' '; pelletsRemaining--; }
        else if(cell == 'o'){ score += 50; cell = ' '; pelletsRemaining--; startFright(); }
    }

    void startFright(){
        frightTicks = max(frightTicks, 60); // frightened duration (ticks)
        for(auto &g: ghosts) if(!g.eaten) g.frightened = true;
    }

    // ghost AI: choose a direction (not reverse unless no option), prefer move reducing manhattan distance to pac when not frightened; when frightened move away
    void moveGhosts(){
        for(auto &g: ghosts){
            if(g.eaten){
                // return to house
                if(g.p == ghostHouse){ g.eaten = false; g.frightened = false; g.dir = LEFT; continue; }
                // simple step towards house (BFS would be better)
                vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
                pair<int,int> best = {INT_MAX, 0}; Pos bestPos = g.p; Dir bestDir = g.dir;
                for(int di=0;di<4;di++){
                    Pos np{g.p.r + dirs[di].first, g.p.c + dirs[di].second};
                    if(!canEnter(np)) continue;
                    int dist = abs(np.r - ghostHouse.r) + abs(np.c - ghostHouse.c);
                    if(dist < best.first){ best.first = dist; bestPos = np; bestDir = static_cast<Dir>(di==0?UP:di==1?DOWN:di==2?LEFT:RIGHT); }
                }
                g.p = bestPos; g.dir = bestDir;
                continue;
            }
            // choose allowed directions
            vector<pair<Dir,Pos>> cand;
            for(Dir d : {UP,DOWN,LEFT,RIGHT}){
                Pos np{g.p.r + dirDelta(d).r, g.p.c + dirDelta(d).c};
                if(!canEnter(np)) continue;
                // prevent immediate reverse unless no other choice
                if(opposite(g.dir) == d){
                    // skip for now; but if no other choices then allow later
                    // store as lower priority
                    cand.push_back({d,np});
                } else {
                    // prefer non-reverse
                    cand.insert(cand.begin(), {d,np});
                }
            }
            if(cand.empty()) continue;
            // if frightened, move away from pac (maximize distance), else chase (minimize distance)
            auto scoreDist = [&](Pos p){ return abs(p.r - pac.r) + abs(p.c - pac.c); };
            sort(cand.begin(), cand.end(), [&](const pair<Dir,Pos>& a, const pair<Dir,Pos>& b){
                int da = scoreDist(a.second), db = scoreDist(b.second);
                if(g.frightened) return da > db; // maximize
                return da < db; // minimize
            });
            // with small randomness to avoid perfect lockstep
            int pick = 0;
            if(cand.size() >= 2 && (int)(rng()%5) == 0) pick = (int)(rng()%cand.size());
            Dir chosen = cand[pick].first;
            Pos chosenPos = cand[pick].second;
            g.dir = chosen;
            g.p = chosenPos;
        }
    }

    // collisions: if ghost collides with pac
    void handleCollisions(){
        for(auto &g: ghosts){
            if(g.eaten) continue;
            if(g.p == pac){
                if(g.frightened){
                    // eat ghost
                    g.eaten = true;
                    score += 200;
                    // send to house (we leave position; eaten ghosts will move to house automatically)
                } else {
                    // pacman dies
                    lives--;
                    if(lives <= 0){
                        // game over
                        draw();
                        moveCursor(rows+4,1);
                        w("\n\x1b[31mGAME OVER\x1b[0m\n");
                        showCursor(); term.restore();
                        exit(0);
                    } else {
                        // reset positions (brief)
                        pac = {13,9}; pacDir = LEFT; pacNext = LEFT;
                        ghosts[0].p = {9,9}; ghosts[1].p = {9,10}; ghosts[2].p = {8,9}; ghosts[3].p = {8,10};
                        for(auto &gg: ghosts){ gg.frightened = false; gg.eaten=false; gg.dir=LEFT; }
                        frightTicks = 0;
                    }
                }
            }
        }
    }

    void updateFright(){
        if(frightTicks > 0){
            frightTicks--;
            if(frightTicks == 0){
                for(auto &g: ghosts) g.frightened = false;
            }
        }
    }

    void step(){
        tick++;
        // move pac every tick
        movePac();
        // ghosts move slower; we move them every 2 ticks (adjustable with level)
        int ghostMoveInterval = max(1, 3 - min(2, level/3)); // faster as level increases
        if(tick % ghostMoveInterval == 0) moveGhosts();
        updateFright();
        handleCollisions();

        // level complete?
        if(pelletsRemaining <= 0){
            level++;
            // reload level and preserve lives/score
            loadLevel();
            // increase difficulty slightly: speed up by reducing ghostMoveInterval via level
        }
    }
};

// main
int main(){
    ios::sync_with_stdio(false);
    signal(SIGINT, handle_sigint);
    term.enableRaw();
    hideCursor();
    Game g;
    g.draw();

    const int frame_ms = 80; // tick time (adjust to taste)

    while(!got_sigint){
        vector<unsigned char> in;
        bool got = readInput(in, frame_ms);
        if(got){
            if(!g.handleInput(in)) break; // q to quit
        }
        g.step();
        g.draw();
    }

    // cleanup
    moveCursor(g.rows + 6, 1);
    showCursor();
    term.restore();
    w("\n");
    return 0;
}