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

#define ll long long
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
const int maxn=1e6+10;

vi mp[maxn];
int N,A;
int dfn[maxn],fa[maxn],siz[maxn],tot,dep[maxn],d[maxn];

struct STBForLCA {
    int mn[maxn][20];
    int Merge(int x,int y) {
        if(dep[x]<dep[y]) {
            return x;
        }else {
            return y;
        }
    }
    int LCA(int l,int r) {
        int k=(31-__builtin_clz(r-l+1));
        return fa[Merge(mn[l][k],mn[r-(1<<k)+1][k])];
    }
    void init() {
        for(int j=1;j<=20;j++) {
            for(int i=1;(i+(1<<j)-1)<=N;i++) {
                mn[i][j]=Merge(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            }
        }
    }
} st;

void DFS(int u,int _fa) {
    dfn[u]=(++tot);
    siz[u]=1;
    st.mn[tot][0]=u;
    for(int to:mp[u]) {
        if(to!=_fa) {
            dep[to]=(dep[u]+1);
            fa[to]=u;
            DFS(to,u);
            siz[u]+=siz[to];
        }
    }
}

void DFSGetPreSum(int u,int _fa) {
    for(int to:mp[u]) {
        if(to!=_fa) {
            DFSGetPreSum(to,u);
            d[u]+=d[to];
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>A;
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    DFS(1,0);
    st.init();
    for(int i=1;i<=A;i++) {
        int x,y;
        cin>>x>>y;
        // debug(x,y);
        if(dfn[x]>dfn[y]) {
            swap(x,y);
        }
        int qlca=st.LCA((dfn[x]+1),dfn[y]);
        d[x]++;
        d[y]++;
        d[qlca]--;
        d[fa[qlca]]--;
        debug(x,y,qlca,st.mn[qlca][0]);
    }
    int s,t;
    cin>>s>>t;
    if(dfn[s]>dfn[t]) {
        swap(s,t);
    }
    DFSGetPreSum(1,0);
    debug(st.LCA((dfn[s]+1),dfn[t]));
    for(int i=1;i<=N;i++) {
        debug(i,dfn[i],dep[i],fa[i],d[i]);
    }
    int num=0;
    while(s!=t) {
        if(dep[s]<dep[t]) {
            swap(s,t);
        }
        if(!d[s]) {
            num++;
        }
        s=fa[s];
    }
    cout<<num<<endl;
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