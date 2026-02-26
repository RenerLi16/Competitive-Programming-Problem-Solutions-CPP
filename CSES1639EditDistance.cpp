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

#define ll long long
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
const int maxn=5005;

int f[maxn][maxn],len1,len2;
char s1[maxn],s2[maxn];

void solve() {
//--------Initiallize--------
    memset(f,0x3f,sizeof(f));
//--------Input--------
    cin>>s1>>s2;
    len1=strlen(s1);
    len2=strlen(s2);
    debug(len1,len2);
    for(int i=len1;i>=1;i--) {
        s1[i]=s1[i-1];
    }ø
    for(int i=len2;i>=1;i--) {
        s2[i]=s2[i-1];
    }
    f[0][0]=0;
    for(int i=1;i<=len1;i++) {
        f[i][0]=i;
    }
    for(int j=1;j<=len2;j++) {
        f[0][j]=j;
    }
    for(int i=1;i<=len1;i++) {
        for(int j=1;j<=len2;j++) {
            if(s1[i]==s2[j]) {
                f[i][j]=min(f[i][j],f[i-1][j-1]);
            } else {
                f[i][j]=min(f[i][j],(f[i-1][j-1]+1));
            }
            f[i][j]=min(f[i][j],(f[i-1][j]+1));
            f[i][j]=min(f[i][j],(f[i][j-1]+1));
        }
    }
    cout<<f[len1][len2]<<endl;
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