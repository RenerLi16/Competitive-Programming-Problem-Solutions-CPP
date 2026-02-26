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

#define ui unsigned int
ui s;

inline ui get(ui x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e5+10;

vi son[maxn];
int N,Q,fa[maxn],f[maxn][20],dep[maxn],ans,tot,rt;

void DFS(int x) {
    f[x][0]=fa[x];
    dep[x]=(dep[fa[x]]+1);
    for(int to:son[x]) {
        DFS(to);
    }
}

void solve() {
    // freopen("/Users/renerli/Documents/code/test.in","r",stdin);
    // freopen("/Users/renerli/Documents/code/test.out","w",stdout);
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q>>s;
    // debug(N,Q,s);
    // return;
    for(int i=1;i<=N;i++) {
        cin>>fa[i];
        if(fa[i]==0) {
            rt=i;
            continue;
        }
        son[fa[i]].push_back(i);
    }
    DFS(rt);
    for(int j=1;j<20;j++) {
        for(int i=1;i<=N;i++) {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    f[rt][0]=rt;
    // for(int i=1;i<=N;i++) {
    //     for(int j=0;j<4;j++) {
    //         cout<<f[i][j]<<endl;
    //     }
    //     putchar('\n');
    // }
    for(int i=1;i<=Q;i++) {
        int x=((get(s)^ans)%N)+1;
        int k=((get(s))^ans)%dep[x];
        // debug(dep[x]);
        // debug(s);
        // debug(x,k);
        // debug(i);
        for(;k;k-=(k&(-k))) {
            x=f[x][__builtin_ctz(k&(-k))];
            if(!x) {
                break;
            }
        }
        ans=x;
        tot^=(i*ans);
    }
    cout<<tot<<endl;
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