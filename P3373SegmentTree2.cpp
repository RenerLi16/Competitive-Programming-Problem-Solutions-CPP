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
const int MOD=571373;
//const int MOD=998244353;
const int maxn=1e5+10;

struct XDS{
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)>>1)
    int sum[maxn<<2],tag[maxn<<2][2];
    void Update(int x) {
        sum[x]=(sum[lson]+sum[rson])%MOD;
    }
    void AddTag(int x,int l,int r,int t1,int t2) {
        sum[x]=(sum[x]*t1+(r-l+1)*t2)%MOD;
        tag[x][0]=(tag[x][0]*t1)%MOD;
        tag[x][1]=((tag[x][1]*t1)+t2)%MOD;
    }
    void Build(int x,int l,int r,int a[]) {
        tag[x][0]=1, tag[x][1]=0;
        if(l==r) {
            sum[x]=a[l];
            return;
        }
        Build(lson,l,mid,a);
        Build(rson,(mid+1),r,a);
        Update(x);
    }
    void Add(int x,int l,int r,int s,int t,int t1,int t2) {
        if(l>=s && r<=t) {
            AddTag(x,l,r,t1,t2);
            return;
        }
        AddTag(lson,l,mid,tag[x][0],tag[x][1]);
        AddTag(rson,(mid+1),r,tag[x][0],tag[x][1]);
        tag[x][0]=1,tag[x][1]=0;
        if(s<=mid) {
            Add(lson,l,mid,s,t,t1,t2);
        }
        if(t>mid) {
            Add(rson,(mid+1),r,s,t,t1,t2);
        }
        Update(x);
    }
    int Ask(int x,int l,int r,int s,int t) {
        if(l>=s && r<=t) {
            return sum[x];
        }
        AddTag(lson,l,mid,tag[x][0],tag[x][1]);
        AddTag(rson,(mid+1),r,tag[x][0],tag[x][1]);
        tag[x][0]=1,tag[x][1]=0;
        int res=0;
        if(s<=mid) {
            res=(res+Ask(lson,l,mid,s,t));
        }
        if(t>mid) {
            res=(res+Ask(rson,(mid+1),r,s,t));
        }
        res=(res%MOD);
        return res;
    }
    #undef lson
    #undef rson
    #undef mid
} xt;

int N,Q,M,A[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    xt.Build(1,1,N,A);
    while(Q--) {
        int type,x,y;
        cin>>type;
        if(type==1) {
            int k;
            cin>>x>>y>>k;
            xt.Add(1,1,N,x,y,k,0);
        } else if(type==2) {
            int k;
            cin>>x>>y>>k;
            xt.Add(1,1,N,x,y,1,k);
        } else {
            cin>>x>>y;
            cout<<(xt.Ask(1,1,N,x,y))<<endl;
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