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
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=2e5+10;

vii mp[maxn];
vii ans,pool;
int N,M,deg[maxn],vis[maxn],pos[maxn];

void TopologicalExpansion() {
    memset(vis,0,sizeof(vis));
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(deg[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        auto u=q.front();
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u]=1;
        debug(u);
        for(auto [type,v]:mp[u]) {
            if(type==0 && !vis[v]) {
                debug(u,v);
                ans.push_back({u,v});
            } else if(type==1) {
                deg[v]--;
            }
            debug(v,deg[v]);
            if(deg[v]==0) {
                q.push(v);
            }
        }
    }
}

void solve() {
//--------Initiallize--------
    memset(deg,0,sizeof(deg));
    ans.clear();
    pool.clear();
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        mp[i].clear();
        mp[i].clear();
    }
    for(int i=1;i<=M;i++) {
        int type,u,v;
        cin>>type>>u>>v;
        if(type==0) {
            mp[u].push_back({0,v});
            mp[v].push_back({0,u});
        } else {
            pool.push_back({u,v});
            mp[u].push_back({1,v});
            deg[v]++;
        }
    }
    TopologicalExpansion();
    for(int i=1;i<=N;i++) {
        if(!vis[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(auto it:ans) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    for(auto it:pool) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}