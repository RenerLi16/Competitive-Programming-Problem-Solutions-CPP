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
#include <random>
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
#define vstto vector<Edge>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=1005;

int N,M,dist[maxn][maxn];
char mp[maxn][maxn];

void BFS(pii src) {
    memset(dist,(0x3f),sizeof(dist));
    queue<pii> q;
    q.push(src);
    dist[src.fi][src.se]=0;
    while(!q.empty()) {
        pii cur=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++) {
            pii to={(cur.fi+dx[dir]),(cur.se+dy[dir])};
            if(to.fi>=1 && to.fi<=N && to.se>=1 && to.se<=M && mp[to.fi][to.se]!='#' && dist[to.fi][to.se]>(dist[cur.fi][cur.se]+1)) {
                dist[to.fi][to.se]=(dist[cur.fi][cur.se]+1);
                q.push(to);
            }
        }
    }
}

vi rec;
void DFS(pii cur, int len, pii tar) {
    debug(cur);
    if(cur==tar) {
        cout<<len<<endl;
        reverse(rec.begin(),rec.end());
        for(int i=0;i<rec.size();i++) {
            if(rec[i]==0) {
                cout<<"L";
            } else if(rec[i]==1) {
                cout<<"U";
            } else if(rec[i]==2) {
                cout<<"R";
            } else {
                cout<<"D";
            }
        }
        exit(0);
    }
    for(int dir=0;dir<4;dir++) {
        pii to={(cur.fi-dx[dir]),(cur.se-dy[dir])};
        if(to.fi>=1 && to.fi<=N && to.se>=1 && to.se<=M && (dist[to.fi][to.se]+1)==dist[cur.fi][cur.se]) {
            rec.pb(dir);
            DFS(to,(len+1),tar);
        }
    }
    return;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>mp[i][j];
        }
    }
    pii src,drn;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(mp[i][j]=='A') {
                src={i,j};
            } else if(mp[i][j]=='B') {
                drn={i,j};
            }
        }
    }
    BFS(src);
    if(dist[drn.fi][drn.se]==(0x3f3f3f3f)) {
        cout<<"NO"<<endl;
    } else {
        //for(int i=1;i<=N;i++) {
            //for(int j=1;j<=M;j++) {
                //cout<<dist[i][j]<<" ";
            //}
            //cout<<endl;
        //}
        cout<<"YES"<<endl;
        DFS(drn,0,src);
    }
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