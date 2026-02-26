#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
#include <bitset>
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

#define int long long
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
const int maxn=2e5+10;

int N,Q,flag[maxn],initstat[maxn];
vi mp[maxn];
vii edges;
tuple<char,int,int> qry[maxn];

void DFS(int x, int t) {
    flag[x]=max(flag[x],t);
    for(auto nxt:mp[x]) {
        if(!flag[nxt]) {
            DFS(nxt,t);
        }
    }
}

struct DSU {
    int fa[maxn],cnt[maxn],siz[maxn];
    void init() {
        for(int i=1;i<=N;i++) {
            fa[i]=i;
            cnt[i]=initstat[i];
            siz[i]=0;
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        }
        return getfa(fa[x]);
    }
    void merge(int x, int y, int t) {
        x=getfa(x);
        y=getfa(y);
        if(x==y) {
            return;
        }
        if(siz[x]>siz[y]) {
            swap(x,y);
        }
        fa[x]=y;
        mp[y].pb(x);
        siz[y]+=siz[x];
        cnt[y]+=cnt[x];
        if(cnt[y]) {
            DFS(y,t);
        }
    }
} su;

void solve() {
//--------Initiallize--------
    memset(initstat,1,sizeof(initstat));
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        flag[i]=Q;
    }
    su.init();
    for(int i=1;i<=Q;i++) {
        char ch;
        cin>>ch;
        if(ch=='A') {
            int u,v;
            cin>>u>>v;
            qry[i]=((tuple<char,int,int>) {ch,u,v});
            edges.pb({u,v});
        } else {
            int x;
            cin>>x;
            qry[i]=((tuple<char,int,int>) {ch,x,0});
            if(ch=='D') {
                initstat[x]=0;
                flag[x]=0;
            }
        }
    }
    for(int i=Q;i>=1;i--) {
        auto [ch,x,y]=qry[i];
        debug(ch,x,y);
        if(ch=='D') {
            su.cnt[su.getfa(x)]++;
            DFS(su.getfa(x),(i-1));
        } else if (ch=='R') {
            su.merge(edges[x-1].fi,edges[x-1].se,(i-1));
        }
    }
    for(int i=1;i<=N;i++) {
        if(flag[i]==0) {
            cout<<Q<<endl;
        } else {
            cout<<flag[i]<<endl;
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