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
const int maxn=1e5+10;

vii mp[maxn];
int N,M,C,S[maxn],deg[maxn],dist[maxn];

void TopologicalExpansion() {
    memset(dist,(-0x3f),sizeof(dist));
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()) {
        auto cur=q.front();
        q.pop();
        for(auto [to,w]:mp[cur]) {
            deg[to]--;
            dist[to]=max(dist[to],(dist[cur]+w));
            if(deg[to]==0) {
                q.push(to);
            }
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M>>C;
    for(int i=1;i<=N;i++) {
        cin>>S[i];
        mp[0].push_back({i,S[i]});
        deg[i]++;
    }
    for(int i=1;i<=C;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        deg[v]++;
    }
    TopologicalExpansion();
    for(int i=1;i<=N;i++) {
        cout<<dist[i]<<endl;
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