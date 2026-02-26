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
const int maxn=1e6+10;

int exp(int a,int b) {
    int tmp=1;
    while(b) {
        if((b%2)==1) {
            tmp=(tmp*a%MOD);
        }
        a=(a*a%MOD);
        b=(b/2);
    }
    return tmp;
}

int K,N,L,ans,fac[maxn],inv[maxn];
char s[maxn];

//borrowed, will change after figuring it out
int C (int x, int y) { return (y < 0 || y > x) ? 0 : 1ll * fac[x] * inv[y] % MOD * inv[x - y] % MOD; }

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>K>>N>>L;
    cin>>(s+1);
    reverse(s+1,s+N+1);
    fac[0]=1;
    for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N] = exp (fac[N], MOD - 2), ans = 1;
    for (int i = N - 1; ~i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    int cnt=0;
    ans=1;
    for(int i=1;i<=N;i++) {
        if(s[i]=='O') {
            cnt++;
        } else {
            debug(i,cnt);
            ans=((ans*C(cnt,K))%MOD);
            cnt-=K;
        }
    }
    ans=exp(ans,L);
    cout<<ans<<endl;
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