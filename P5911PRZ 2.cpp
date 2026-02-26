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
const int maxn=20;
const int maxstat=(1<<16)+10;
const int maxw=405;

pii pool[maxn],precmp[maxstat];
int f[maxstat],N,W;

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>W>>N;
    for(int i=0;i<N;i++) {
        cin>>pool[i].first>>pool[i].second;
    }
//--------Initiallize Bounded--------
    for(int S=0;S<(1<<N);S++) {
        f[S]=INF;
    }
//--------No fluff real stuff--------
    for(int S=0;S<(1<<N);S++) {
        for(int i=0;i<N;i++) {
            if(S&(1<<i)) {
                precmp[S].first=max(precmp[S].first,pool[i].first);
                precmp[S].second+=pool[i].second;
            }
        }
    }
    // for(int S=0;S<(1<<N);S++) {
    //     debug(S,precmp[S]);
    // }
    f[0]=0;
    for(int S=0;S<(1<<N);S++) {
        for(int T=S;;T=(T-1)&S) {
            if(precmp[S^T].second<=W) {
                f[S]=min(f[S],f[T]+precmp[S^T].first);
            }
            if(T==0) {
                break;
            }
        }
    }
    cout<<f[(1<<N)-1]<<endl;
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