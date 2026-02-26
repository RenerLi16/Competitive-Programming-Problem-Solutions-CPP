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

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e5+10;
const int maxval=5e5+10;

pair<int,pii> pool[maxn];
vi rnkd[maxn];
vii qry[maxn];
int N,M,Q,ans[maxn];

struct DSU {
    int tot;
    vi fa,rev,siz;
    void init() {
        fa.resize(tot+5);
        siz.resize(tot+5);
        for(int i=1;i<=tot;i++) {
            siz[i]=1;
            fa[i]=i;
        }
    }
    void pop() {
        reverse(all(rev));
        for(int cur:rev) {
            siz[fa[cur]]-=siz[cur];
            fa[cur]=cur;
        }
        rev.clear();
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        }
        return getfa(fa[x]);
    }
    void merge(pii req) {
        int ufa=getfa(pool[req.second].second.first),vfa=getfa(pool[req.second].second.second);
        if(ufa==vfa) {
            ans[req.first]=1;
            return;
        }
        if(siz[ufa]>siz[vfa]) {
            swap(ufa,vfa);
        }
        rev.push_back(ufa);
        siz[vfa]+=siz[ufa];
        fa[ufa]=vfa;
    }
} dd;

void solve() {
    // Initiallize
    // No fluff real stuff
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        cin>>pool[i].second.first>>pool[i].second.second>>pool[i].first;
        rnkd[pool[i].first].push_back(i);
    }
    dd.tot=N;
    dd.init();
    cin>>Q;
    for(int i=1;i<=Q;i++) {
        int K;
        cin>>K;
        for(int j=1;j<=K;j++) {
            int x;
            cin>>x;
            qry[pool[x].first].push_back({i,x});
        }
        // cout<<1<<endl;
    }
    // systemwait
    for(int i=1;i<maxval;i++) {
        // cout<<i<<endl;
        // return;
        // systemwait
        int last=0;
        for(pii cur:qry[i]) {
            // cout<<cur.first<<" "<<cur.second<<endl;
            // return;
            if(cur.first!=last) {
                dd.pop();
                last=cur.first;
            }
            dd.merge(cur);
            // cout<<1<<endl;
            // return;
        }
        // cout<<i<<endl;
        // return;
        dd.pop();
        for(int u:rnkd[i]){
            dd.merge({0,u});
        }
        dd.rev.clear();
    }
    for(int i=1;i<=Q;i++) {
        if(ans[i]==1) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
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