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
const int maxn=1e5+10;

int N,M;
double A[maxn];
double sum1,sum2;

struct XDS {
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)/2)
    double sum[maxn<<3],tag[maxn<<3],sqsum[maxn<<3];
    void Update(int x) {
        sum[x]=(sum[lson]+sum[rson]);
        sqsum[x]=(sqsum[lson]+sqsum[rson]);
    }
    void AddTag(int x,int l,int r,double t) {
        sqsum[x]=(sqsum[x]+(2*t*sum[x])+((r-l+1)*(t*t)));
        sum[x]=(sum[x]+(r-l+1)*t);
        tag[x]=(tag[x]+t);
    }
    void Build(int x,int l,int r) {
        if(l==r) {
            sum[x]=A[l];
            sqsum[x]=(A[l]*A[l]);
            return;
        }
        Build(lson,l,mid);
        Build(rson,(mid+1),r);
        Update(x);
    }
    void Add(int x,int l,int r,int s,int t,double k) {
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
            sum1=(sum1+sum[x]);
            sum2=(sum2+sqsum[x]);
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
        Update(x);
    }
    #undef lson
    #undef rson
    #undef mid
}xt;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    xt.Build(1,1,N);
    for(int i=1;i<=M;i++) {
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1) {
            double x;
            cin>>x;
            xt.Add(1,1,N,l,r,x);
        } else if(type==2) {
            sum1=0;
            sum2=0;
            xt.Ask(1,1,N,l,r);
            printf("%.4lf\n",(1.0*sum1/(r-l+1)));
        } else {
            sum1=0;
            sum2=0;
            xt.Ask(1,1,N,l,r);
            double average=(sum1/(r-l+1));
            printf("%.4lf\n",((sum2/(r-l+1))-(2*average/(r-l+1)*sum1)+(average*average)));
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