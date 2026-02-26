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
debug(,,,)
const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1005;
const int maxlen=15;

int f[2][3][1<<maxlen],N,K,ans[maxn];
char s[maxn];

int calc(int S,int p) {
    char c;
    int dp[maxn]={},dpnew[maxn]={};
    if(p==0) {
        c='N';
    } else if(p==1) {
        c='O';
    } else {
        c='I';
    }
    for(int i=0;i<K;i++) {
        dp[i+1]=dp[i]+((S>>i)&1);
    }
    for(int i=1;i<=K;i++) {
        dpnew[i]=max(max(dp[i],dpnew[i-1]),dp[i-1]+(c==s[i]));
    }
    int stret=0;
    for(int i=0;i<K;i++) {
        if(dpnew[i+1]>dpnew[i]) {
            stret+=(1<<i);
        }
    }
    return stret;

}

void solve() {
    // Initiallize
    // No fluff real stuff
    cin>>N>>K;
    cin>>(s+1);
    f[0][0][0]=1;
    for(int i=0;i<N;i++) {
        memset(f[i&1^1],0,sizeof(f[i&1^1]));
        for(int j=0;j<=2;j++) {
            for(int S=0;S<(1<<K);S++) {
                if(f[i&1][j][S]) {
                    for(int p=0;p<=2;p++) {
                        int jnew=0;
                        if(p==0) {
                            jnew=1;
                        } else if(p==1 && j==1) {
                            jnew=2;
                        } else if(p==2 && j==2) {
                            continue;
                        }
                        int Snew=calc(S,p);
                        f[i&1^1][jnew][Snew]=(f[i&1^1][jnew][Snew]+f[i&1][j][S])%MOD;
                    }
                }
            }
        }
    }
    for(int j=0;j<=2;j++) {
        for(int S=0;S<(1<<K);S++) {
            int cur=__builtin_popcount(S);
            ans[cur]=(ans[cur]+f[N&1][j][S])%MOD;
        }
    }
    for(int i=0;i<=K;i++) {
        cout<<ans[i]<<endl;
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