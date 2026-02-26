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
const int maxn=1e4+10;
const int maxedge=5e4+10;//here

vii mp[maxn];
int N,M,f[maxn][20],g[maxn][20],dep[maxn],Q,sum,qmn;

struct Node {
    int u,v,w;
    friend bool operator < (Node first,Node second) {
        return first.w>second.w;
    }
}pool[maxedge];

struct DSU {
    int fa[maxn];
    int getfa(int x) {
        if(fa[x]==x) {
            return fa[x];
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void Merge(int x,int y) {
        int xfa=getfa(x),yfa=getfa(y);
        if(xfa==yfa) {
            return;
        }
        fa[xfa]=yfa;
    }
} su;

void DFS(int x,int _fa) {
    f[x][0]=_fa;
    dep[x]=dep[_fa]+1;
    for(auto [to,w]:mp[x]) {
        if(to!=_fa) {
            g[to][0]=w;
            DFS(to,x);
        }
    }
}

int lca(int x,int y) {
    qmn=INF;
    if(dep[x]<dep[y]) {
        swap(x,y);
    }
    int k=(dep[x]-dep[y]);
    for(int i=0;i<20;i++) {
        if(k&(1<<i)) {
            qmn=min(qmn,g[x][i]);
            x=f[x][i];
        }
    }
    if(x==y) {
        return y;
    }
    for(int i=19;i>=0;i--) {
        if(f[x][i]!=f[y][i]) {
            qmn=min(qmn,min(g[x][i],g[y][i]));
            x=f[x][i];
            y=f[y][i];
        }
    }
    qmn=min(qmn,min(g[x][0],g[y][0]));
    return f[x][0];
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        pool[i]={u,v,w};
    }
    sort(pool+1,pool+M+1);
    for(int i=1;i<=N;i++) {
        su.fa[i]=i;
    }
    for(int i=1;i<=M;i++) {
        if(su.getfa(pool[i].u)!=su.getfa(pool[i].v)) {
            mp[pool[i].u].pb({pool[i].v,pool[i].w});
            mp[pool[i].v].pb({pool[i].u,pool[i].w});
            su.Merge(pool[i].u,pool[i].v);
            sum+=pool[i].w;
        }
    }
    for(int i=1;i<=N;i++) {
        if(!dep[i]) {
            DFS(i,0);
        }
    }
    for(int i=1;i<20;i++) {
        for(int u=1;u<=N;u++) {
            f[u][i]=f[f[u][i-1]][i-1];
            g[u][i]=min(g[u][i-1],g[f[u][i-1]][i-1]);
        }
    }
    cin>>Q;
    for(int i=1;i<=Q;i++) {
        int x,y;
        cin>>x>>y;
        if(su.getfa(x)!=su.getfa(y)) {
            cout<<-1<<endl;
            continue;
        }
        int qlca=lca(x,y);
        cout<<qmn<<endl;
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