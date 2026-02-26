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
const int maxn=1e5+10;

vi mp[maxn];
int N,Q,dfn[maxn],siz[maxn],fa[maxn],dep[maxn],tot,P[maxn],qsum,A[maxn];

struct XDS {
    #define ls (x<<1)
    #define rs ((x<<1)+1)
    #define mid ((l+r)/2)
    int xsum[maxn<<2],tag[maxn<<2];
    void Update(int x) {
        xsum[x]=(xsum[ls]^xsum[rs]);
    }
    void AddTag(int x,int l,int r,int t) {
        xsum[x]^=t;
        tag[x]^=t;
    }
    void Build(int x,int l,int r) {
        if(l==r) {
            xsum[x]=A[l];
            return;
        }
        Build(ls,l,mid);
        Build(rs,(mid+1),r);
        Update(x);
    }
    void Add(int x,int l,int r,int s,int t,int k) {
        if(l>=s && r<=t) {
            AddTag(x,l,r,k);
            return;
        }
        AddTag(ls,l,mid,tag[x]);
        AddTag(rs,(mid+1),r,tag[x]);
        tag[x]=0;
        if(s<=mid) {
            Add(ls,l,mid,s,t,k);
        }
        if(t>mid) {
            Add(rs,(mid+1),r,s,t,k);
        }
        Update(x);
    }
    void Ask(int x,int l,int r,int s,int t) {
        if(l>=s && r<=t) {
            qsum=xsum[x];
            return;
        }
        AddTag(ls,l,mid,tag[x]);
        AddTag(rs,(mid+1),r,tag[x]);
        tag[x]=0;
        if(s<=mid) {
            Ask(ls,l,mid,s,t);
        }
        if(t>mid) {
            Ask(rs,(mid+1),r,s,t);
        }
    }
    #undef ls
    #undef rs
    #undef mid
} xt;

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
    int LCA(int &x,int &y) {
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

void DFS(int x,int _fa) {
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

void DFSGetA(int x,int _fa) {
    A[dfn[x]]^=P[x];
    for(int to:mp[x]) {
        if(to!=_fa) {
            A[dfn[to]]^=A[dfn[x]];
            DFSGetA(to,x);
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>P[i];
    }
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    DFS(1,0);
    st.init();
    // return;
    DFSGetA(1,0);
    xt.Build(1,1,N);
    // return;
    while(Q--) {
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1) {
            xt.Add(1,1,N,dfn[x],(dfn[x]+siz[x]-1),P[x]);
            // return;
            P[x]=y;
            xt.Add(1,1,N,dfn[x],(dfn[x]+siz[x]-1),P[x]);
        } else {
            int qlca=st.LCA(x,y);
            // debug(qlca);
            qsum=0;
            xt.Ask(1,1,N,dfn[x],dfn[x]);
            // return;
            int lssum=qsum;
            qsum=0;
            xt.Ask(1,1,N,dfn[y],dfn[y]);
            // return;
            int rssum=qsum;
            qsum=0;
            if(qlca!=1) xt.Ask(1,1,N,dfn[fa[qlca]],dfn[fa[qlca]]);
            int ufasum=qsum;
            qsum=0;
            xt.Ask(1,1,N,dfn[qlca],dfn[qlca]);
            int dfasum=qsum;
            cout<<(lssum^rssum^ufasum^dfasum)<<endl;
            // return;
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