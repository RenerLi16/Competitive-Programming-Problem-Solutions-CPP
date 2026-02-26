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

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
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

int N,A[maxn],tmp1,tmp2,sum[maxn];

bool check(int x, int k, int k1) {
    return (sum[x]-sum[x-k-1]+sum[N]-sum[N-k])*(2*k1+1)<=(sum[x]-sum[x-k1-1]+sum[N]-sum[N-k1])*(2*k+1);
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    sort(A+1,A+N+1);
    for(int i=1;i<=N;i++) {
        sum[i]=sum[i-1]+A[i];
    }
    double ans=(-1);
    for(int i=1;i<=N;i++) {
        int l=0;
        int r=min(i-1,N-i);
        while(l<r) {
            int mid=(l+r)>>1;
            if(check(i,mid,mid+1)) {
                l=mid+1;
            } else {
                r=mid;
            }
        }
        if(ans<1.0*(sum[i]-sum[i-l-1]+sum[N]-sum[N-l])/(2*l+1)-A[i]) {
            ans=1.0*(sum[i]-sum[i-l-1]+sum[N]-sum[N-l])/(2*l+1)-A[i];
            tmp1=i;
            tmp2=l;
        }
    }
    cout<<1+tmp2*2<<endl;
    for(int i=tmp1-tmp2;i<=tmp1;i++) {
        cout<<A[i]<<" ";
    }
    for(int i=N-tmp2+1;i<=N;i++) {
        cout<<A[i]<<" ";
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