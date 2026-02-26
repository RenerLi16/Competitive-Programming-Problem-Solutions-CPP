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

const ll INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

ll N,M,Q,B[maxn];
vector<ll> sum;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M>>Q;
//--------No fluff real stuff--------
    ll Asum=0;
    for(ll i=1;i<=N;i++) {
        ll x;
        cin>>x;
        if(i%2) {
            Asum+=x;
        } else {
            Asum-=x;
        }
    }
    ll Bsum=0;
    for(ll i=1;i<=M;i++) {
        cin>>B[i];
        if(i>N) {
            Bsum=-Bsum;
            Bsum+=B[i-N];
        }
        if((i<=N && i%2) || (i>N && N%2)) {
            Bsum+=B[i];
        } else {
            Bsum-=B[i];
        }
        if(i>=N) {
            sum.push_back(Bsum);
        }
        // debug(Bsum);
    }
    sort(sum.begin(),sum.end());
    ll pos=lower_bound(sum.begin(),sum.end(),Asum)-sum.begin(),ans=INF;
    // debug(pos);
    if(pos!=sum.size()) {
        ans=min(ans,sum[pos]-Asum);
    }
    if(pos!=0) {
        ans=min(ans,Asum-sum[pos-1]);
    }
    cout<<ans<<endl;
    while(Q--) {
        ll l,r,x;
        cin>>l>>r>>x;
        if((r-l+1)%2) {
            if(l%2) {
                Asum+=x;
            } else {
                Asum-=x;
            }
        }
        pos=lower_bound(sum.begin(),sum.end(),Asum)-sum.begin(),ans=INF;
        if(pos!=sum.size()) {
            ans=min(ans,sum[pos]-Asum);
        }
        if(pos!=0) {
            ans=min(ans,Asum-sum[pos-1]);
        }
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