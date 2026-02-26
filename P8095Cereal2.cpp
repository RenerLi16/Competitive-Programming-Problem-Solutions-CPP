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
#else
#define debug(x...) 
#define systemwait
#endif

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

struct DSU {
    int tot;
    vi fa;
    void init() {
        fa.resize(tot+10);
        for(int i=1;i<=tot;i++) fa[i]=i;
    }
    int getfa(int x) {
        return fa[x]==x ? x : (fa[x]=getfa(fa[x]));
    }
    void merge(int x,int y) {
        int xfa=getfa(x),yfa=getfa(y);
        if(xfa==yfa) {
            return;
        }
        fa[xfa]=yfa;
    }
} dd;

vector<pair<int,pii>> pool;
vii mp[maxn];
int vis[maxn],N,M,ctn[maxn],ans[maxn],tot;

void dfs(int x,int fa) {
    for(auto [v,id]:mp[x]) {
        if(v==fa) {
            continue;
        }
        ans[++tot]=id;
        ctn[id]=1;
        dfs(v,x);
        // if(id==0) {
        //     cout<<v<<endl;
        // }
    }
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    dd.tot=M;
    dd.init();
    for(int i=1;i<=N;i++) {
        int uu,vv;
        cin>>uu>>vv;
        int ufa=dd.getfa(uu),vfa=dd.getfa(vv);
        if(ufa==vfa) {
            pool.push_back({i,{uu,vv}});
        } else {
            dd.merge(ufa,vfa);
            mp[uu].push_back({vv,i});
            mp[vv].push_back({uu,i});
        }
    }
    // return;
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    // for(int i=1;i<=M;i++) {
    //     debug(dd.getfa(i));
    // }
    for(int i=0;i<pool.size();i++) {
        if(!vis[dd.getfa(pool[i].second.first)]) {
            vis[dd.getfa(pool[i].second.first)]=1;
            // return;
            ans[++tot]=pool[i].first;
            ctn[pool[i].first]=1;
            dfs(pool[i].second.first,-1);
            // cout<<pool[i].first<<endl;
        }
    }
    // for(int i=1;i<=tot;i++) {
    //     debug(ans[i]);
    // }
    for(int i=1;i<=M;i++) {
        if(!vis[dd.getfa(i)]) {
            vis[dd.getfa(i)]=1;
            dfs(i,-1);
        }
    }
    cout<<N-tot<<endl;
    for(int i=1;i<=N;i++) {
        if(!ctn[i]) {
            ans[++tot]=i;
        }
    }
    for(int i=1;i<=tot;i++) {
        cout<<ans[i]<<endl;
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