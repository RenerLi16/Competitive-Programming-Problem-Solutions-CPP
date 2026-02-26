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
int N,M,R,dfn[maxn],siz[maxn],fa[maxn],dep[maxn],tot,P[maxn];

struct STBForLCA {
    int mn[maxn][20];
    int Merge(int x,int y) {
        if(dep[x]<dep[y]) return x;
        return y;
    }
    int GetMin(int l,int r) {
        int k=(31-__builtin_clz(r-l+1));
        return fa[Merge(mn[l][k],mn[r-(1<<k)+1][k])];
    }
    int LCA(int x,int y) {
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

struct XDS {
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)/2)
    int mn[maxn<<2],tag[maxn<<2];
    void Update(int x) {
        mn[x]=min(mn[lson],mn[rson]);
    }
    void AddTag(int x,int l,int r,int t) {
        mn[x]+=tag[x];
    }
}

struct FWT {
    int t[maxn];
    void Add(int x,int k) {
        if(!x) return;
        for(;x<=N;x+=(x&(-x))) {
            t[x]+=k;
        }
    }
    int Ask(int x) {
        int res=0;
        for(;x;x-=(x&(-x))) {
            res+=t[x];
        }
        return res;
    }
    int AskChangeDepth(int x) {
        int res=0;
        for(;x;x-=(x&(-x))) {
            res+=(dep[x]*t[x]);
        }
        return res;
    }
} at;

void DFS(int x,int _fa) {
    dfn[x]=(++tot);
    siz[x]=1;
    fa[x]=_fa;
    dep[x]=(dep[_fa]+1);
    for(int to:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
            siz[x]+=siz[to];
        }
    }
}

void solve() {
    // Initiallize
    // No fluff real stuff
    cin>>N>>M>>R;
    for(int i=1;i<=N;i++) {
        cin>>P[i];
    }
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    DFS(R,0);
    st.init();
    for(int i=1;i<=M;i++) {
        int type,x;
        cin>>type;
        if(type==1) {
            int y,k;
            cin>>x>>y>>k;
            int qlca=st.LCA(x,y);
            at.Add(dfn[x],k);
            at.Add(dfn[y],k);
            at.Add(dfn[qlca],-d);
            at.Add(dfn[fa[qlca]],-k);
        } else if(type==2) {
            cin>>x;
            cout<<(at.Ask(dfn[x])-at.Ask(dfn[x]-1))<<endl;
        } else if(type==3) {
            cin>>x;
            cout<<((at.AskChangeDepth(dfn[x]+1)-at.AskChangeDepth(dfn[x]+siz[x]-1))-dep[x]*(at.Ask(dfn[x]+1)-at.Ask(dfn[x]+siz[x]-1)))<<endl;
        }
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