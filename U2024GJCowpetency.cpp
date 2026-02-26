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
const int maxn=10005;
const int maxqry=105;

int N,Q,C,f[maxqry][maxn],s[maxqry][maxn],ans;
pii b[maxn];

int exp(int a,int b) {
    int tmp=1;
    for(;b>0;b/=2) {
        if((b%2)==1) {
            tmp=(tmp*a)%MOD;
        }
        a=(a*a)%MOD;
    }
    return tmp;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q>>C;
    for(int i=1;i<=Q;i++) {
        cin>>b[i].se>>b[i].fi;
    }
    sort(b+1,b+Q+1);
    int tot=1;
    for(int i=2;i<=Q;i++) {
        if(b[i].fi!=b[tot].fi) {
            b[++tot]=b[i];
        }
    }
    f[0][0]=1;
    for(int j=0;j<=C;j++) {
        s[0][j]=1;
    }
    for(int i=1;i<=tot;i++) {
        auto [h,a]=b[i];
        for(int j=2;j<=C;j++) {
            int l1=(a-b[i-1].fi),l2=(h-a-1);
            int k=(j-1);
            f[i][j]=(f[i][j-1]+f[i-1][k]*exp(k,(l1+l2))%MOD+(exp(k,l1)-exp((k-1),l1))*exp(k,l2)%MOD*s[i-1][k-1])%MOD;
            s[i][j]=(s[i][j-1]+f[i][j])%MOD;
        }
    }
    ans=((s[tot][C]*exp(C,(N-b[tot].fi))%MOD)+MOD)%MOD;
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