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
const int maxn=3e5+10;
const int maxval=1e6+10;

int N,M,A[maxn],B[maxn],ans,Q;

struct XDS{
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)/2)
    int mx[maxval<<2],tag[maxval<<2];
    void Update(int x) {
        mx[x]=max(mx[lson],mx[rson]);
    }
    void AddTag(int x,int l,int r,int t) {
        mx[x]+=t;
        tag[x]+=t;
    }
    void Add(int x,int l,int r,int s,int t,int k) {
        if(s<=l && r<=t) {
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
    void Ask(int x,int l,int r) {
        if(mx[x]<=0) return;
        if(l==r) {
            ans=l;
            return;
        }
        AddTag(lson,l,mid,tag[x]);
        AddTag(rson,(mid+1),r,tag[x]);
        tag[x]=0;
        if(mx[rson]>0) {
            Ask(rson,(mid+1),r);
        } else if(mx[rson]<=0) {
            Ask(lson,l,mid);
        }
    }
    #undef lson
    #undef rson
    #undef mid
} xt;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        xt.Add(1,1,1e6,1,A[i],1);
    }
    for(int i=1;i<=M;i++) {
        cin>>B[i];
        xt.Add(1,1,1e6,1,B[i],(-1));
    }
    cin>>Q;
    while(Q--) {
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1) {
            if(A[x]<y){
                xt.Add(1,1,1e6,(A[x]+1),y,1);
            } else if(A[x]>y) {
                xt.Add(1,1,1e6,(y+1),A[x],(-1));
            }
            A[x]=y;
        } else {
            if(B[x]<y) {
                xt.Add(1,1,1e6,(B[x]+1),y,(-1));
            } else if(B[x]>y) {
                xt.Add(1,1,1e6,(y+1),B[x],1);
            }
            B[x]=y;
        }
        ans=(-1);
        xt.Ask(1,1,1e6);
        cout<<ans<<endl;
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