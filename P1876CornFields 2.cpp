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
const int MOD=1e8;
//const int MOD=998244353;
const int maxn=15;
const int maxstat=(1<<12)+10;

int f[maxn][maxstat],N,M,MP[maxn],ans;

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int x;
            cin>>x;
            MP[i]|=(x<<j);
        }
    }
//--------Initiallize Bounded--------
    for(int S=MP[0];;S=(S-1)&MP[0]) {
        if(S&(S<<1)) {
            continue;
        }
        f[0][S]=1;
        if(S==0) {
            break;
        }
    }
//--------No fluff real stuff--------
    for(int i=1;i<N;i++) {
        for(int S=MP[i];;S=(S-1)&MP[i]) {
            if(S&(S<<1)) {
                continue;
            }
            int lastlim=(1<<M)-1-S;
            // debug(lastlim);
            for(int T=lastlim;;T=(T-1)&lastlim) {
                // if(i==1 && S==0) {
                //     debug(T);
                // }
                (f[i][S]+=f[i-1][T])%=MOD;
                if(T==0) {
                    break;
                }
            }
            if(S==0) {
                break;
            }
        }
    }
    // for(int i=0;i<N;i++) {
    //     for(int S=0;S<(1<<M);S++) {
    //         debug(i,S,f[i][S]);
    //     }
    // }
    for(int S=MP[N-1];;S=(S-1)&MP[N-1]) {
        (ans+=f[N-1][S])%=MOD;
        if(S==0) break;
    }
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