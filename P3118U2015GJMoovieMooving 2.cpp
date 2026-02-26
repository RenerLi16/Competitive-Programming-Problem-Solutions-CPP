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
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=25;
const int maxst=(1<<20);

vi pool[maxn];
int N,L,D[maxn],f[maxst],ans=0x3f3f3f3f;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>L;
    for(int i=0;i<N;i++) {
        cin>>D[i];
        int x;
        cin>>x;
        for(int j=1;j<=x;j++) {
            int lenx;
            cin>>lenx;
            pool[i].pb(lenx);
        }
    }
    for(int S=0;S<(1<<N);S++) {
        for(int i=0;i<N;i++) {
            if(!(S&(1<<i))) {
                int l=0,r=(pool[i].size()-1);
                while(l<=r) {
                    int mid=((l+r)/2);
                    if(pool[i][mid]<=f[S]) {
                        l=(mid+1);
                    } else {
                        r=(mid-1);
                    }
                }
                if(r!=(-1)) {
                    int T=(S|(1<<i));
                    f[T]=max(f[T],max(f[S],(pool[i][r]+D[i])));
                }
            }
        }
        if(f[S]>=L) {
            ans=min(ans,(int)__builtin_popcount(S));
        }
    }
    if(ans==0x3f3f3f3f) {
        cout<<(-1)<<endl;
    } else {
        cout<<ans<<endl;
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