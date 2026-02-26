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

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

set<pii> smp[maxn];
vector<int> mp[maxn];
int N,dfn[maxn],dep[maxn],fa[maxn],siz[maxn],tot,Q,qsum;

struct XDS {
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)/2)
    int sum[maxn<<2],tag[maxn<<2];
    void Update(int x) {
        sum[x]=sum[lson]+sum[rson];
    }
    void AddTag(int x,int l,int r,int t) {
        sum[x]+=(r-l+1)*t;
        tag[x]+=t;
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
            qsum+=sum[x];
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
    #undef lson
    #undef rson
    #undef mid
} xt;

void DFS(int x,int _fa) {
    dfn[x]=(++tot);
    dep[x]=dep[_fa]+1;
    fa[x]=_fa;
    siz[x]=1;
    for(int to:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
            siz[x]+=siz[to];
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<N;i++) {
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    DFS(1,0);
    for(int i=1;i<=Q;i++) {
        int type;
        cin>>type;
        if(type==1) {
            int x,k;
            cin>>x>>k;
            pii tmp={dfn[x],(dfn[x]+siz[x]-1)};
            auto pos=smp[k].upper_bound(tmp);
            while(pos!=smp[k].end() && (*pos).se<=tmp.se) {
                xt.Add(1,1,N,(*pos).fi,(*pos).se,(-1));
                smp[k].erase(pos++);
                // ++pos;
            }
            bool flag=true;
            if(pos!=smp[k].begin()) {
                --pos;
                if((*pos).se>=tmp.se) {
                    flag=false;
                }
            }
            if(flag) {
                xt.Add(1,1,N,tmp.fi,tmp.se,1);
                smp[k].insert(tmp);
            }
        } else {
            int x;
            cin>>x;
            qsum=0;
            xt.Ask(1,1,N,dfn[x],(dfn[x]+siz[x]-1));
            cout<<qsum<<endl;
        }
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