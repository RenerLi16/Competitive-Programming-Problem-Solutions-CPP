#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <tuple>
#include <stack>
#include <numeric>
#include <climits>
#include <deque> 
#include <chrono>
#include <unordered_map>
#include <cstring>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define systemwait system("read -p \"Press Enter to continue...\"");
#define debugbreak exit(0)
#else
#define debug(x...) 
#define systemwait
#define debugbreak
#endif

#define LL long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1005;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
const string ds[4]={"L","U","R","D"};

vii pool;
pii src;
char mp[maxn][maxn];
int N,M;
pii dist[2][maxn][maxn];
bool flag;

void BFSGetMonsterRange() {
    queue<pii> q;
    for(auto it:pool) {
        dist[0][it.fi][it.se]={0,0};
        q.push(it);
    }
    while(!q.empty()) {
        pii cur=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++) {
            pii to={(cur.fi+dx[dir]),(cur.se+dy[dir])};
            if(to.fi>=1 && to.fi<=N && to.se>=1 && to.se<=M
                && mp[to.fi][to.se]!='#'
                && dist[0][to.fi][to.se].fi>(dist[0][cur.fi][cur.se].fi+1)) {
                int ndir=((dir+2)%4);
                dist[0][to.fi][to.se]={(dist[0][cur.fi][cur.se].fi+1),ndir};
                q.push(to);
            }
        }
    }
}

void BFS(pii src) {
    queue<pii> q;
    dist[1][src.fi][src.se]={0,(-1)};
    q.push(src);
    while(!q.empty()) {
        pii cur=q.front();
        q.pop();
        if(cur.fi==1 || cur.fi==N || cur.se==1 || cur.se==M) {
            string s;
            while(dist[1][cur.fi][cur.se].se!=(-1)) {
                int dir=dist[1][cur.fi][cur.se].se;
                s+=ds[((dir+2)%4)];
                cur={(cur.fi+dx[dir]),(cur.se+dy[dir])};
            }
            cout<<"YES"<<endl;
            cout<<s.length()<<endl;
            reverse(s.begin(),s.end());
            cout<<s<<endl;
            exit(0);
        }
        for(int dir=0;dir<4;dir++) {
            pii to={(cur.fi+dx[dir]),(cur.se+dy[dir])};
            if(to.fi>=1 && to.fi<=N && to.se>=1 && to.se<=M
                && mp[to.fi][to.se]!='#'
                && dist[1][to.fi][to.se].fi>(dist[1][cur.fi][cur.se].fi+1)
                && dist[0][to.fi][to.se].fi>(dist[1][cur.fi][cur.se].fi+1)) {
                int ndir=((dir+2)%4);
                dist[1][to.fi][to.se]={(dist[1][cur.fi][cur.se].fi+1),ndir};
                q.push(to);
            }
        }
    }
}

void solve() {
//--------Initiallize--------
    memset(dist,0x3f,sizeof(dist));
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>(mp[i]+1);
        for(int j=1;j<=M;j++) {
            if(mp[i][j]=='A') {
                src={i,j};
            } else if(mp[i][j]=='M') {
                pool.push_back({i,j});
            }
        }
    }
    //for(auto it:pool) {
        BFSGetMonsterRange();
    //}
    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=M;j++) {
    //         if(dist[0][i][j].fi==0x3f3f3f3f) {
    //             dist[0][i][j].fi=(-1);
    //         }
    //         printf("%4d",dist[0][i][j].fi);
    //     }
    //     printf("\n");
    // }
    BFS(src);
    cout<<"NO"<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    //cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}