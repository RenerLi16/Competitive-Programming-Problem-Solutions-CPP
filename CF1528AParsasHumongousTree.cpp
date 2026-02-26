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
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

vi mp[maxn];
int N,f[maxn][2],A[maxn][2];

void DFS(int x,int _fa) {
    // debug(x);
    if(x!=1 && mp[x].size()==1) {
        f[x][0]=0;
        f[x][1]=0;
        return;
    }
    for(int to:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
            f[x][1]+=max(f[to][0]+abs(A[x][1]-A[to][0]),f[to][1]+abs(A[x][1]-A[to][1]));
            f[x][0]+=max(f[to][0]+abs(A[x][0]-A[to][0]),f[to][1]+abs(A[x][0]-A[to][1]));
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    // debug(N);
    for(int i=1;i<=N;i++) {
        f[i][0]=0;
        f[i][1]=0;
        mp[i].clear();
    }
    for(int i=1;i<=N;i++) {
        cin>>A[i][0]>>A[i][1];
    }
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].pb(y);
        mp[y].pb(x);
    }
    DFS(1,0);
    cout<<(max(f[1][0],f[1][1]))<<endl;
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