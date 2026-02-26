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
const int maxn=1010;

struct STBforLCA {
    int mn[maxn][20];
    int Merge(int x, int y) {
        if(dep[x]<dep[y]) {
            return x;
        } else {
            return y;
        }
    }
    int GetMin(int l,int r) {
        int k=(31-__builtin_clz(r-l+1));
        return fa[Merge(mn[l][k],mn[r-(1<<k)+1][k])];
    }
    int LCA(int &x, int &y) {
        if(x==y) {
            return x;
        }
        if(dfn[x]>dfn[y]) {
            swap(x,y);
        }
        return GetMin((dfn[x]+1),dfn[y]);
    }
    void init() {
        for(int j=1;j<20;j++) {
            for(int i=1;(i+(1<<j)-1)<=N;i++) {
                mn[i][j]=Merge(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            }
        }
    }
} st;

int dfn[maxn],siz[maxn],dep[maxn],tot;

void DFS(int x, int _fa) {
    dfn[x]=(++tot);
    siz[x]=1;
    dep[x]=dep[_fa]+1;
    fa[x]=_fa;
    st.mn[dfn[x]][0]=x;
    for(int to:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
            siz[x]+=siz[to];
        }
    }
}

vi mp[maxn];
int N,M,T[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].pb(y);
        mp[y].pb(x);
    }
    DFS();
    st.init();
    for(int i=1;i<=M;i++) {
    }
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