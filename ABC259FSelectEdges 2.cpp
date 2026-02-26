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

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=3e5+10;

vii mp[maxn];
int N,D[maxn],f[maxn][2];

void DFS(int x,int _fa) {
    if(x!=1 && mp[x].size()==1) {
        f[x][0]=0;
        f[x][1]=0;
        if(D[x]==0) {
            f[x][0]=-0x3f33f3f3f3f3f3f;
        }
        return;
    }
    int sum0=0,sum1=0;
    vi pool={};
    for(auto [to,w]:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
            sum0+=f[to][1];
            sum1+=f[to][1];
            pool.pb(max((f[to][0]+w-f[to][1]),0LL));
        }
    }
    sort(pool.begin(),pool.end(),greater<int>());
    for(int i=0;i<min((int)(pool.size()),(D[x]-1));i++) {
        sum0+=pool[i];
    }
    for(int i=0;i<min((int)(pool.size()),D[x]);i++) {
        sum1+=pool[i];
    }
    f[x][0]=sum0;
    f[x][1]=sum1;
    if(D[x]==0) {
        f[x][0]=(-0x3f3f3f3f3f3f3f3f);
    }
}


void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>D[i];
    }
    for(int i=1;i<N;i++) {
        int x,y,w;
        cin>>x>>y>>w;
        mp[x].pb({y,w});
        mp[y].pb({x,w});
    }
    DFS(1,0);
    cout<<max(f[1][1],f[1][0])<<endl;
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