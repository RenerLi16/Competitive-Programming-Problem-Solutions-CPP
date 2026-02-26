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

const int dy[4]={0,-1,0,1};
const int dx[4]={1,0,-1,0};
const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

int X1,Y1,X,Y,N,seq[maxn],re;

bool Check(int k) {
    int wx=0,wy=0;
    if(k>=N) {
        for(int i=1;i<=N;i++) {
            wx=(wx+dx[seq[i]]);
            wy=(wy+dy[seq[i]]);
        }
        wx=(wx*(k/N));
        wy=(wy*(k/N));
    }
    for(int i=1;i<=(k%N);i++) {
        wx=(wx+dx[seq[i]]);
        wy=(wy+dy[seq[i]]);
    }
    debug(k,wx,wy);
    debug(X,Y);
    debug(abs(X-wx),abs(Y-wy));
    return (abs(X-wx)+abs(Y-wy))<=k;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>X1>>Y1>>X>>Y>>N;
    X-=X1,Y-=Y1;
    for(int i=1;i<=N;i++) {
        char c;
        cin>>c;
        if(c=='R') seq[i]=0;
        else if(c=='D') seq[i]=1;
        else if(c=='L') seq[i]=2;
        else seq[i]=3;
    }
    debug(Check(5));
    int l=1,r=1e18;
    while(l<=r) {
        int mid=((l+r)/2);
        if(Check(mid)) r=mid-1;
        else l=mid+1;
    }
    if(l>=1e18+1) {
        cout<<"-1"<<endl;
        return;
    }
    cout<<l<<endl;
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