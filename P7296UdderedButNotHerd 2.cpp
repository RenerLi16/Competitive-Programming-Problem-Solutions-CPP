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
const int maxn=30;
const int maxstat=(1<<20)+10;
const int maxlen=1e5+10;

int f[maxstat],g[maxstat][maxn],cnt[maxn][maxn],d[maxstat],N,A[maxlen],MP[maxn],tot;
string S;

void solve() {
//--------Initiallize Boundless--------
    memset(MP,0x3f,sizeof(MP));
//--------Input--------
    cin>>S;
    N=S.length();
    for(int i=0;i<N;i++) {
        if(MP[S[i]-'a']==0x3f3f3f3f) {
            MP[S[i]-'a']=tot++;
        }
        A[i]=MP[S[i]-'a'];
        if(i>0) {
            cnt[A[i-1]][A[i]]++;
        }
    }
//--------Initiallize Bounded--------
    for(int i=0;i<tot;i++) {
        d[(1<<i)]=i;
    }
    for(int S=0;S<(1<<tot);S++) {
        f[S]=INF;
    }
//--------No fluff real stuff--------
    for(int S=1;S<(1<<tot);S++) {
        int j=d[S&(-S)];
        for(int i=0;i<tot;i++) {
            g[S][i]=g[S^(1<<j)][i]+cnt[i][j];
        }
    }
    f[0]=0;
    for(int S=1;S<(1<<tot);S++) {
        for(int i=0;i<tot;i++) {
            if(S&(1<<i)) {
                f[S]=min(f[S],f[S^(1<<i)]+g[S][i]);
            }
        }
    }
    cout<<f[(1<<tot)-1]+1<<endl;
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