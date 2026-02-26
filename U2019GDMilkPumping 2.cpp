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

#define int long long
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
const int maxn=1005;

struct EdgePool {
    int u,v,c,flow;
    friend bool operator < (EdgePool first,EdgePool second) {
        return first.flow>second.flow;
    }
};

vector<EdgePool> bufer;
vii mp[maxn];
int N,M,dist[maxn],vis[maxn];
double ans=(-INF);

void Dijkstra(int src) {
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vii,greater<pii>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()) {
        auto [curlen,u]=pq.top();
        pq.pop();
        if(vis[u]) {
            continue;
        }
        debug(u);
        vis[u]=1;
        for(auto [v,w]:mp[u]) {
            debug(v,w);
            if(dist[v]>(dist[u]+w)) {
                dist[v]=(dist[u]+w);
                pq.push({dist[v],v});
            }
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int u,v,c,flow;
        cin>>u>>v>>c>>flow;
        bufer.push_back({u,v,c,flow});
    }
    sort(bufer.begin(),bufer.end());
    for(int i=0;i<M;i++) {
        auto [u,v,c,flow]=bufer[i];
        mp[u].push_back({v,c});
        mp[v].push_back({u,c});
        while((i+1)<M && bufer[i+1].flow==bufer[i].flow) {
            i++;
            auto [u,v,c,flow]=bufer[i];
            mp[u].push_back({v,c});
            mp[v].push_back({u,c});
        }
        Dijkstra(1);
        // for(int i=1;i<=N;i++) {
        //     cout<<dist[i]<<" ";
        // }
        // cout<<endl;
        // debug(bufer[i].flow,dist[N],u,v,c,flow);
        ans=max(ans,(1.0*bufer[i].flow/dist[N]));
    }
    ans*=1e6;
    // debug(ans);
    ans=floor(ans);
    cout<<ans<<endl;
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