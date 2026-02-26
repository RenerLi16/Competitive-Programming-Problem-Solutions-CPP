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
const int maxch=26;
const int maxn=2e5+10;

int N,M,h[maxn],r[maxn],qpos;

struct SegTree {
    #define lson (x*2)
    #define rson (x*2+1)
    int mx[maxn<<2];
    void pushUp(int x) {
        mx[x]=max(mx[lson],mx[rson]);
    }
    void build(int x, int l, int r) {
        if(l==r) {
            mx[x]=h[l];
            return;
        }
        int mid=(l+r)/2;
        build(lson,l,mid);
        build(rson,(mid+1),r);
        pushUp(x);
    }
    void AsknUpdate(int x, int l, int r, int lb, int rb, int val) {
        if(l==r) {
            qpos=l;
            mx[x]-=val;
            return;
        }
        int mid=(l+r)/2;
        if(mx[lson]>=val) {
            AsknUpdate(lson,l,mid,lb,rb,val);
        } else {
            AsknUpdate(rson,(mid+1),r,lb,rb,val);
        }
        pushUp(x);
    }
} sgt;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>h[i];
    }
    sgt.build(1,1,N);
    for(int i=1;i<=M;i++) {
        cin>>r[i];
        if(sgt.mx[1]<r[i]) {
            cout<<0<<" ";
        } else {
            sgt.AsknUpdate(1,1,N,1,N,r[i]);
            cout<<qpos<<" ";
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