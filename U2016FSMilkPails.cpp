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
const int maxn=105;

int X,Y,K,M,dist[maxn][maxn],ans=INF,f[maxn][maxn];

void BFS(pii src,int step) {
    queue<pair<pii,int>> q;
    dist[src.fi][src.se]=0;
    q.push({src,step});
    while(!q.empty()) {
        pair<pii,int> cur=q.front();
        q.pop();

    }
}

void dfs(int xn,int yn,int kn)
{
    if ((f[xn][yn]==1)||(kn-1>K)) return;
    f[xn][yn]=1;
    ans=min(ans,abs(M-xn-yn));
    dfs(X,yn,kn+1);
    dfs(xn,Y,kn+1);
    dfs(0,yn,kn+1);
    dfs(xn,0,kn+1);
    if(X-xn<=yn) dfs(X,yn-(X-xn),kn+1);
    else dfs(xn+yn,0,kn+1);
    if(Y-yn<=xn) dfs(xn-(Y-yn),Y,kn+1);
    else dfs(0,xn+yn,kn+1);
    f[xn][yn]=0;
    return;
}

void solve() {
//--------Initiallize--------
    memset(dist,0x3f,sizeof(dist));
//--------Input--------
    cin>>X>>Y>>K>>M;
    dist[X][Y]=K;
    dfs(0,0,1);
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