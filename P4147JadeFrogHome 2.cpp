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
const int maxn=1005;

vii stkmim;
int N,M,A[maxn][maxn],rpos[maxn][maxn],lpos[maxn][maxn],ans;
char mp[maxn][maxn];

void cstpop(int posx,int posy,int x) {
    if(x==0) {
        rpos[posx][stkmim.back().second]=(posy-1);
    } else {
        lpos[posx][stkmim.back().second]=(posy+1);
    }
    stkmim.pop_back();
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>mp[i][j];
        }
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(mp[i][j]=='F') A[i][j]=A[i-1][j]+1;
            while(!stkmim.empty() && stkmim.back().first>A[i][j]) {
                cstpop(i,j,0);
            }
            // if(i==N) {
            //     debug(ans,j);
            // }
            stkmim.push_back({A[i][j],j});
        }
        while(!stkmim.empty()) {
            cstpop(i,M+1,0);
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=M;j>=1;j--) {
            while(!stkmim.empty() && stkmim.back().first>A[i][j]) {
                cstpop(i,j,1);
            }
            // if(i==N) {
            //     debug(ans,j);
            // }
            stkmim.push_back({A[i][j],j});
        }
        while(!stkmim.empty()) {
            cstpop(i,0,1);
        }
    }
    // for(int i=1;i<=N;i++) {
    //     debug(lpos[N][i],rpos[N][i]);
    // }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            ans=max(ans,A[i][j]*(rpos[i][j]-lpos[i][j]+1));
        }
    }
    ans*=3;
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