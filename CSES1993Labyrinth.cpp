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

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define tiii tuple<int,int,int>
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

int N,M,dist[maxn][maxn],vis[maxn][maxn];
char mp[maxn][maxn];

bool inBound(pii pos) {
    return pos.fi>=1 && pos.fi<=N && pos.se>=1 && pos.se<=M;
}

void Dijkstra(pii src) {
    memset(dist,0x3f,sizeof(dist));
    priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
    dist[src.fi][src.se]=0;
    vis[src.fi][src.se]=0;
    pq.push({0,src.fi,src.se});
    while(!pq.empty()) {
        auto [len,x,y]=pq.top();
        //debug(x,y);
        pq.pop();
        if(vis[x][y]) {
            continue;
        }
        vis[x][y]=1;
        for(int dir=0;dir<4;dir++) {
            pii nxt={(x+dx[dir]),(y+dy[dir])};
            //debug(nxt,inBound(nxt),dist[nxt.fi][nxt.se]>dist[x][y]);
            if(inBound(nxt) && dist[nxt.fi][nxt.se]>(dist[x][y]+1) && mp[nxt.fi][nxt.se]!='#') {
                dist[nxt.fi][nxt.se]=(dist[x][y]+1);
                pq.push({(dist[x][y]+1),nxt.fi,nxt.se});
            }
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    pii src,drn;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>mp[i][j];
            if(mp[i][j]=='A') {
                src={i,j};
            } else if(mp[i][j]=='B') {
                drn={i,j};
            }
        }
    }
    Dijkstra(src);
    //for(int i=1;i<=N;i++) {
        //for(int j=1;j<=M;j++) {
            //if(dist[i][j]==0x3f3f3f3f3f3f3f3f) {
                //cout<<"INF ";
            //} else {
                //cout<<dist[i][j]<<" ";
            //}
        //}
        //cout<<endl;
    //}
    if(dist[drn.fi][drn.se]!=0x3f3f3f3f3f3f3f3f) {
        cout<<"YES"<<endl;
        cout<<dist[drn.fi][drn.se]<<endl;
        pii pos=drn;
        string ans;
        while(pos!=src) {
            //debug(pos);
            //systemwait;
            for(int dir=0;dir<4;dir++) {
                pii nxt={(pos.fi-dx[dir]),(pos.se-dy[dir])};
                if(inBound(nxt) && dist[nxt.fi][nxt.se]==(dist[pos.fi][pos.se]-1)) {
                    if(dir==0) {
                        ans.pb('L');
                    } else if(dir==1) {
                        ans.pb('U');
                    } else if(dir==2) {
                        ans.pb('R');
                    } else {
                        ans.pb('D');
                    }
                    pos=nxt;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    } else {
        cout<<"NO"<<endl;
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