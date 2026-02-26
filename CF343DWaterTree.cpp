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
const int maxn=5e5+10;

vi mp[maxn];
int N,Q;

struct XDT {
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    int sum[maxn<<2],mx[maxn<<2],tag[maxn<<2];
    void Update(int x) {
        sum[x]=(sum[lson]+sum[rson]);
        mx[x]=max(mx[lson],mx[rson]);
    }
    void AddTag(int x,int l,int r,int t) {
        sum[x]=(sum[x]+((r-l+1)*t));
        mx[x]+=t;
    }
    void Add(int x,int l,int r,int s,int t,int k) {
        if(l>=s && r<=t) {
            AddTag(x,l,r,k);
            return;
        }
        AddTag(lson,l,mid,tag[x]);
        AddTag(rson,(mid+1),r,tag[x]);
        tag[x]=0;
        if(s<=mid) {
            Add(lson,l,mid,s,t,k);
        }
        if(t>mid) {
            Add(rson,(mid+1),r,s,t,k);
        }
        Update(x);
    }
    void Ask(int x,int l,int r,int s,int t) {
        if(l>=s && r<=t) {
            qmn=min(qmn,mn[x]);
            return;
        }
        AddTag(lson,l,mid,tag[x]);
        AddTag(rson,(mid+1),r,tag[x]);
        tag[x]=0;
        if(s<=mid) {
            Ask(lson,l,mid,s,t);
        }
        if(t>mid) {
            Ask(rson,(mid+1),r,s,t);
        }
    }
} xt1,xt2;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=2;i<=N;i++) {
        cin>>P[i];
        adj[i].push_back(P[i]);
        adj[P[i]].push_back(i);
    }
    DFS(1,1,0);
    for(int i=1;i<=N;i++) {
        sort(sdep[i].begin(),sdep[i].end());
        // for(int it:sdep[i]) {
        //     debug(i,it);
        // }
    }
    cin>>Q;
    while(Q--) {
        int u,d;
        cin>>u>>d;
        if(sdep[d].empty()) {
            cout<<0<<endl;
            return;
        }
        int pos1=lower_bound(sdep[d].begin(),sdep[d].end(),dfn[u])-sdep[d].begin(), pos2=lower_bound(sdep[d].begin(),sdep[d].end(),(dfn[u]+siz[u]-1))-sdep[d].begin();
        if((pos2<sdep[d].size() && sdep[d][pos2]>(dfn[u]+siz[u]-1)) || (!sdep[d].empty() && pos2==sdep[d].size())) {
            pos2--;
        }
        // debug(siz[u],pos1,pos2);
        cout<<(pos2-pos1+1)<<endl;
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