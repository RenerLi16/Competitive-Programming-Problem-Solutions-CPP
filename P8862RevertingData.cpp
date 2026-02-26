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

vector<tuple<int,int,int,int>> qry;
int N,Q,A[maxn];
vector<int> ans;
int qmn,qsum;

struct XDT{
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)/2)
    int mn[maxn<<2],sum[maxn<<2],tag[maxn<<2];
    void Update(int x) {
        mn[x]=min(mn[lson],mn[rson]);
        sum[x]=(sum[lson]+sum[rson]);
    }
    void AddTag(int x,int l,int r,int t) {
        mn[x]=(mn[x]+t);
        sum[x]=(sum[x]+((r-l+1)*t));
        tag[x]=(tag[x]+t);
    }
    void Build(int x,int l,int r) {
        if(l==r) {
            mn[x]=A[l];
            sum[x]=A[l];
            return;
        }
        Build(lson,l,mid);
        Build(rson,(mid+1),r);
        Update(x);
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
            qsum=(qsum+sum[x]);
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
}xt;

void solve() {
//--------Initiallize--------
    qry.clear();
    ans.clear();
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    while(Q--) {
        int type,l,r,x;
        cin>>type>>l>>r;
        if(type==1) {
            cin>>x;
        }
        qry.push_back({type,l,r,x});
    }
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    memset(xt.tag,0,sizeof(xt.tag));
    xt.Build(1,1,N);
    // return;
    reverse(qry.begin(),qry.end());
    for(auto [type,l,r,x]:qry) {
        if(type==1) {
            xt.Add(1,1,N,l,r,(-x));
        } else {
            qmn=INF;
            qsum=0;
            // return;
            xt.Ask(1,1,N,l,r);
            // for(int i=1;i<=(2*N);i++) {
            //     debug(i,xt.mn[i]);
            // }
            // return;
            // debug(qmn);
            // debug(type,l,r,x);
            // debug(qsum);
            ans.push_back(qmn);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) {
        cout<<it<<" ";
    }
    cout<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}