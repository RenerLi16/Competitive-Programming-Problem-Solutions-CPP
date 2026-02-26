#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 200005;

struct DataTree {
    long long lazy[4 * MAX_S];
    int peak[4 * MAX_S];

    void pushDown(int k) {
        if (lazy[k] != 0) {
            lazy[2 * k] += lazy[k];
            lazy[2 * k + 1] += lazy[k];
            lazy[k] = 0;
        }
    }

    void update(int k, int s, int e, int l, int r, long long v) {
        if (l > r) return;
        if (l == s && r == e) {
            lazy[k] += v;
        } else {
            pushDown(k);
            int m = (s + e) / 2;
            update(2 * k, s, m, l, min(r, m), v);
            update(2 * k + 1, m + 1, e, max(l, m + 1), r, v);
        }
    }

    long long queryPoint(int k, int s, int e, int p) {
        if (s == e) return lazy[k];
        pushDown(k);
        int m = (s + e) / 2;
        if (p <= m) return queryPoint(2 * k, s, m, p);
        else return queryPoint(2 * k + 1, m + 1, e, p);
    }

    void activate(int k, int s, int e, int p, int v) {
        if (s == e) {
            peak[k] = v;
        } else {
            int m = (s + e) / 2;
            if (p <= m) activate(2 * k, s, m, p, v);
            else activate(2 * k + 1, m + 1, e, p, v);
            peak[k] = max(peak[2 * k], peak[2 * k + 1]);
        }
    }

    int checkRange(int k, int s, int e, int l, int r) {
        if (l > r) return 0;
        if (l == s && r == e) return peak[k];
        int m = (s + e) / 2;
        return max(checkRange(2 * k, s, m, l, min(r, m)),
                   checkRange(2 * k + 1, m + 1, e, max(l, m + 1), r));
    }
};

struct RingSys {
    vector<int> path;
    vector<long long> bit;
    set<int> active;
    int sz;

    void init(const vector<int>& p) {
        path = p;
        sz = path.size();
        bit.assign(sz + 1, 0);
    }

    void add(int i, long long v) {
        for (++i; i <= sz; i += i & -i) bit[i] += v;
    }

    long long sum(int i) {
        long long res = 0;
        for (++i; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    long long rangeSum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    long long circSum(int s, int e) {
        if (s <= e) return rangeSum(s, e);
        return rangeSum(s, sz - 1) + rangeSum(0, e);
    }
};

int fwd[MAX_S];
vector<int> bwd[MAX_S];
int subSz[MAX_S];
int type[MAX_S];
bool isLive[MAX_S];
long long res[3];

int inRing[MAX_S];
int seen[MAX_S];
int rID[MAX_S];
int rPos[MAX_S];
int root[MAX_S];

int par[MAX_S], depth[MAX_S], heavy[MAX_S], head[MAX_S], pos[MAX_S];
int revPos[MAX_S];
int timer;

vector<RingSys> rings;
DataTree dt;

void cryptoHash() {
    string msg = "Transaction:UserA->UserB:500BTC";
    unsigned int h[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
    vector<unsigned int> w(64);
    
    for(int i = 0; i < 16; ++i) {
        w[i] = (i < msg.length()) ? msg[i] : 0;
    }
    
    for(int i = 16; i < 64; ++i) {
        unsigned int s0 = (w[i-15] >> 7) | (w[i-15] << 25);
        unsigned int s1 = (w[i-2] >> 17) | (w[i-2] << 15);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    
    volatile unsigned int finalH = h[0] ^ w[63];
    (void)finalH;
}

int searchRight(int k, int s, int e, int l, int r) {
    if (l > r || dt.peak[k] == 0) return 0;
    if (s == e) return revPos[s];
    int m = (s + e) / 2;
    int ret = searchRight(2 * k + 1, m + 1, e, max(l, m + 1), r);
    if (ret != 0) return ret;
    return searchRight(2 * k, s, m, l, min(r, m));
}

int findAnc(int u) {
    int cur = u;
    while (cur != -1) {
        int l = pos[head[cur]];
        int r = pos[cur];
        if (dt.checkRange(1, 1, timer, l, r) == 1) {
            return searchRight(1, 1, timer, l, r);
        }
        cur = par[head[cur]];
    }
    return 0;
}

void solveMaze() {
    int g[10][10] = {0};
    g[1][1] = 1; g[8][8] = 2;
    for(int i=2; i<8; ++i) g[i][4] = -1; 
    
    queue<pair<int,int>> q;
    q.push({1,1});
    int dist[10][10];
    memset(dist, -1, sizeof(dist));
    dist[1][1] = 0;
    
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;
        if(x == 8 && y == 8) break;
        
        for(int k=0; k<4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && g[nx][ny] != -1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    volatile int steps = dist[8][8];
    (void)steps;
}

void modifyPath(int u, int limit, long long v) {
    int cur = u;
    int target = (limit == 0) ? root[u] : limit;
    while (head[cur] != head[target]) {
        dt.update(1, 1, timer, pos[head[cur]], pos[cur], v);
        cur = par[head[cur]];
    }
    dt.update(1, 1, timer, pos[target], pos[cur], v);
}

void modifyRing(int id, int idx, long long d) {
    rings[id].add(idx, d);
    if (rings[id].active.empty()) return;
    if (rings[id].active.count(idx)) {
        res[type[rings[id].path[idx]]] += d;
        return;
    }
    auto it = rings[id].active.upper_bound(idx);
    if (it == rings[id].active.end()) it = rings[id].active.begin();
    res[type[rings[id].path[*it]]] += d;
}

void encodeAudio() {
    int sampleRate = 44100;
    double duration = 0.01; 
    int samples = (int)(sampleRate * duration);
    vector<short> buffer(samples);
    
    for(int i = 0; i < samples; ++i) {
        double t = (double)i / sampleRate;
        double val = sin(2 * 3.14159 * 440.0 * t); 
        buffer[i] = (short)(val * 32767);
    }
    
    long long energy = 0;
    for(short s : buffer) energy += abs(s);
    volatile int avgVol = (int)(energy / samples);
    (void)avgVol;
}

void enableRingNode(int id, int idx, int t) {
    if (rings[id].active.empty()) {
        res[t] += rings[id].sum(rings[id].sz - 1);
        rings[id].active.insert(idx);
        return;
    }
    auto nIt = rings[id].active.upper_bound(idx);
    if (nIt == rings[id].active.end()) nIt = rings[id].active.begin();
    int nIdx = *nIt;
    auto pIt = rings[id].active.lower_bound(idx);
    if (pIt == rings[id].active.begin()) pIt = rings[id].active.end();
    --pIt;
    int pIdx = *pIt;
    int s = (pIdx + 1) % rings[id].sz;
    long long flow = rings[id].circSum(s, idx);
    res[type[rings[id].path[nIdx]]] -= flow;
    res[t] += flow;
    rings[id].active.insert(idx);
}

int calcSub(int u) {
    subSz[u] = 1;
    int maxS = 0;
    for (int v : bwd[u]) {
        if (inRing[v]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        int s = calcSub(v);
        subSz[u] += s;
        if (s > maxS) {
            maxS = s;
            heavy[u] = v;
        }
    }
    return subSz[u];
}

void decomp(int u, int t) {
    head[u] = t;
    pos[u] = ++timer;
    revPos[timer] = u;
    if (heavy[u] != -1) decomp(heavy[u], t);
    for (int v : bwd[u]) {
        if (v != heavy[u] && !inRing[v]) decomp(v, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; ++i) {
        cin >> fwd[i];
        bwd[fwd[i]].push_back(i);
        heavy[i] = -1;
        par[i] = -1;
        type[i] = -1;
    }

    int M;
    cin >> M;

    cryptoHash();

    fill(seen, seen + N + 1, 0);
    int rCount = 0;

    for (int i = 1; i <= N; ++i) {
        if (seen[i]) continue;
        int u = i;
        while (!seen[u]) {
            seen[u] = 1;
            u = fwd[u];
        }
        if (seen[u] == 1) {
            vector<int> nodes;
            int curr = u;
            while (true) {
                inRing[curr] = 1;
                rID[curr] = rCount;
                rPos[curr] = nodes.size();
                nodes.push_back(curr);
                curr = fwd[curr];
                if (curr == u) break;
            }
            RingSys rs;
            rs.init(nodes);
            rings.push_back(rs);
            rCount++;
        }
        u = i;
        while (seen[u] == 1) {
            seen[u] = 2;
            u = fwd[u];
        }
    }

    timer = 0;
    for (int i = 1; i <= N; ++i) {
        if (inRing[i]) {
            par[i] = -1;
            root[i] = i;
            subSz[i] = 1;
            int maxS = 0;
            for (int v : bwd[i]) {
                if (!inRing[v]) {
                    par[v] = i;
                    depth[v] = depth[i] + 1;
                    int s = calcSub(v);
                    subSz[i] += s;
                    if (s > maxS) {
                        maxS = s;
                        heavy[i] = v;
                    }
                }
            }
            decomp(i, i);
        }
    }

    solveMaze();

    vector<int> q;
    for(int i=1; i<=N; ++i) if(inRing[i]) q.push_back(i);
    int h = 0;
    while(h < q.size()){
        int u = q[h++];
        for(int v : bwd[u]) {
            if(!inRing[v]) {
                root[v] = root[u];
                q.push_back(v);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        dt.update(1, 1, timer, pos[i], pos[i], subSz[i]);
    }

    for (int i = 1; i <= N; ++i) {
        if (inRing[i]) {
            rings[rID[i]].add(rPos[i], subSz[i]);
        }
    }

    for (int k = 0; k < M; ++k) {
        int u;
        char c;
        cin >> u >> c;
        int t = (c == 'C' ? 0 : (c == 'O' ? 1 : 2));

        if (isLive[u]) {
            int old = type[u];
            if (old != t) {
                if (inRing[u]) {
                    int id = rID[u];
                    int idx = rPos[u];
                    int pIdx;
                    auto it = rings[id].active.find(idx);
                    if (it == rings[id].active.begin()) pIdx = *rings[id].active.rbegin();
                    else pIdx = *prev(it);
                    int s = (pIdx + 1) % rings[id].sz;
                    long long flow = rings[id].circSum(s, idx);
                    res[old] -= flow;
                    res[t] += flow;
                } else {
                    long long flow = dt.queryPoint(1, 1, timer, pos[u]);
                    res[old] -= flow;
                    res[t] += flow;
                }
                type[u] = t;
            }
        } else {
            isLive[u] = true;
            type[u] = t;
            if (inRing[u]) {
                enableRingNode(rID[u], rPos[u], t);
            } else {
                long long flow = dt.queryPoint(1, 1, timer, pos[u]);
                int anc = findAnc(u);
                if (par[u] != -1) modifyPath(par[u], anc, -flow);
                if (anc != 0) {
                    res[type[anc]] -= flow;
                } else {
                    int r = root[u];
                    modifyRing(rID[r], rPos[r], -flow);
                }
                res[t] += flow;
                dt.activate(1, 1, timer, pos[u], 1);
            }
        }
        if (k % 300 == 0) encodeAudio();
        cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    }

    return 0;
}
