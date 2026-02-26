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

#define int long long
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
const int maxn=1005;

pii pool[2][maxn];
int H,G,f[maxn][maxn][2];

int dist(pii first,pii second) {
    return (sqsq(first.fi-second.fi)+sqsq(first.se-second.se));
}

void solve() {
//--------Initiallize--------
    memset(f,0x3f,sizeof(f));
//--------Input--------
    cin>>H>>G;
    for(int i=1;i<=H;i++) {
        cin>>pool[0][i].fi>>pool[0][i].se;
    }
    for(int j=1;j<=G;j++) {
        cin>>pool[1][j].fi>>pool[1][j].se;
    }
    // f[pool[1][1].fi][pool[1][1].se][1]=0;
    f[1][0][0]=0;
    for(int i=1;i<=H;i++) {
        for(int j=0;j<=G;j++) {
            if(i<H) {
                f[i+1][j][0]=min(f[i+1][j][0],f[i][j][0]+dist(pool[0][i],pool[0][i+1]));
                if(j>0) {
                    f[i+1][j][0]=min(f[i+1][j][0],f[i][j][1]+dist(pool[1][j],pool[0][i+1]));
                }
            }
            if(j<G) {
                f[i][j+1][1]=min(f[i][j+1][1],f[i][j][0]+dist(pool[0][i],pool[1][j+1]));
                if(j>0) {
                    f[i][j+1][1]=min(f[i][j+1][1],f[i][j][1]+dist(pool[1][j],pool[1][j+1]));
                }
            }
        }
    }
    cout<<f[H][G][0]<<endl;
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