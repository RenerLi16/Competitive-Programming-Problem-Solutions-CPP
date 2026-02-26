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
const int maxn=1e5+10;

int N,K,A[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
//--------No fluff real stuff--------
    sort(A+1,A+N+1);
    int l=1,r=N,lcnt=1,rcnt=1,lval=0,rval=0;
    while(l<r) {
        debug(lcnt,rcnt,K);
        if(lcnt<=rcnt) {
            if((K/lcnt)<=(A[l+1]-A[l])) {
                rval=A[r];
                lval=(A[l]+(K/lcnt));
                break;
            } else {
                K=(K-((A[l+1]-A[l])*lcnt));
                lcnt++;
                l++;
            }
        } else {
            if((K/rcnt)<=(A[r]-A[r-1])) {
                lval=A[l];
                rval=(A[r]-(K/rcnt));
                break;
            } else {
                K=(K-((A[r]-A[r-1])*rcnt));
                rcnt++;
                r--;
            }
        }
    }
    if(l>=r) {
        lval=A[l],rval=A[r];
    }
    cout<<(rval-lval)<<endl;
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