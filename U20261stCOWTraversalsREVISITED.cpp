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
const int maxn=2e5+10;

int N,M,nxt[maxn],cnt[maxn],ans[3],cty[maxn],tsp[maxn],rt[maxn];
pii qry[maxn];

struct DSU {
    int fa[maxn],siz[maxn];
    void init() {
        for(int i=1;i<=N;i++) {
            fa[i]=i;
            siz[i]=1;
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) {
        x=getfa(x);
        y=getfa(y);
        if(x==y) {
            return;
        }
        siz[y]+=siz[x];
        fa[x]=y;
    }
    void spmerge(int x, int y, int t) {
        x=getfa(x);
        y=getfa(y);
        if(x==y) {
            return;
        }
        tsp[t]=siz[y];
        rt[t]=y;
        siz[y]+=siz[x];
        fa[x]=y;
    }
} us;

void solve() {
//--------Initiallize--------
    memset(cty,(-1),sizeof(cty));
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>nxt[i];
    }
    cin>>M;
    for(int i=1;i<=M;i++) {
        char ch;
        cin>>qry[i].se>>ch;
        cnt[qry[i].se]++;
        if(ch=='C') {
            qry[i].fi=0;
        } else if(ch=='O') {
            qry[i].fi=1;
        } else {
            qry[i].fi=2;
        }
    }
    us.init();
    for(int i=1;i<=N;i++) {
        if(cnt[i]==0) {
            us.merge(i,nxt[i]);
        }
    }
    for(int i=M;i>=1;i--) {
        auto [ncty,x]=qry[i];
        cnt[x]--;
        if(cnt[x]==0) {
            us.spmerge(x,nxt[x],i);
        }
    }
    for(int i=1;i<=M;i++) {
        auto [ncty,x]=qry[i];
        if(tsp[i]!=0) {
            us.siz[rt[i]]=tsp[i];
            ans[cty[rt[i]]]-=us.siz[x];
        }
        if(cty[x]!=(-1)) {
            ans[cty[x]]-=us.siz[x];
        }
        cty[x]=ncty;
        ans[cty[x]]+=us.siz[x];
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
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