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
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=15;
const int maxstat=(1<<12)+10;
const int maxtot=105;

int presum[maxstat][maxtot],sum[maxstat],cnt[maxstat],N,M,Q,A[maxn];

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M>>Q;
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<=M;i++) {
        char s[maxn];
        int x=0;
        cin>>s;
        for(int j=0;j<strlen(s);j++) {
            x=x|((s[j]=='1')<<j);
        }
        // debug(x);
        cnt[x]++;
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    for(int S=0;S<(1<<N);S++) {
        for(int i=0;i<N;i++) {
            if(S&(1<<i)) {
                sum[S]+=A[i];
            }
        }
    }
    for(int S=0;S<(1<<N);S++) {
        for(int T=0;T<(1<<N);T++) {
            int tmp=sum[S^T^((1<<N)-1)];
            if(tmp<=100) {
                presum[S][tmp]+=cnt[T];
            }
        }
    }
    for(int S=0;S<(1<<N);S++) {
        for(int i=1;i<=100;i++) {
            presum[S][i]=presum[S][i]+presum[S][i-1];
        }
    }
    for(int i=1;i<=Q;i++) {
        char s[maxn];
        int x,stcur=0;
        cin>>s>>x;
        for(int j=0;j<strlen(s);j++) {
            stcur=stcur|((s[j]=='1')<<j);
        }
        // debug(stcur);
        cout<<presum[stcur][x]<<endl;
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