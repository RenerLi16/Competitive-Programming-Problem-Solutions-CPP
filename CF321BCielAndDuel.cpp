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
const int maxn=105;

vector<int> a,b;
int N,M,A[maxn];
int idle[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        string s;
        cin>>s;
        int x;
        cin>>x;
        if(s=="DEF") a.push_back(x);
        else b.push_back(x);
    }
    for(int i=1;i<=M;i++) cin>>A[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(A+1,A+M+1);
    int pos=1,sum1=0;
    reverse(A+1,A+M+1);
    for(int i=1;i<=min(M,a.size());i++) {
        if(a[i-1]>A[i]) {
            break;
        }
        sum1=(sum1+A[i]-a[i]);
    }
    for(int i=M;i>=1;i--) {
        while(pos<=N && !cards[pos].second) ++pos;
        if(pos>N) {
            break;
        }
        if(cards[pos].first>A[i]) {
            break;
        }
        sum1=(sum1+A[i]-cards[pos].first);
        ++pos;
    }
    pos=1;
    int sum2=0;
    for(int i=1;i<=M;i++) {
        if(pos>N) {
            idle[i]=1;
            continue;
        }
        if(cards[pos].first>A[i]) {
            idle[i]=1;
            continue;
        }
        if(!cards[pos].second) {
            ++pos;
            continue;
        }
        if(pos<=N) {
            sum2=(sum2+A[i]-cards[pos].first);
            ++pos;
        }
        debug(i,pos);
    }
    for(int i=1;i<=M;i++) {
        debug(i,idle[i]);
        if(idle[i]) sum2=(sum2+A[i]);
    }
    debug(sum1,sum2);
    if(pos<=N) sum2=(-INF);
    cout<<max(sum1,sum2)<<endl;
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