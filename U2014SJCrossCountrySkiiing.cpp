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

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=505;

vii pool;
int mp[maxn][maxn],vis[maxn][maxn],N,M,ans;

void DFS(pii x,int ub) {
    // debug(x);
    vis[x.first][x.second]=1;
    for(int dir=0;dir<4;dir++) {
        int xv=x.first+dx[dir],yv=x.second+dy[dir];
        if(xv>=1 && xv<=N && yv>=1 && yv<=M && !vis[xv][yv] && abs(mp[x.first][x.second]-mp[xv][yv])<=ub) {
            DFS({xv,yv},ub);
        }
    }
}

bool Check(int x) {
    memset(vis,0,sizeof(vis));
    DFS(pool[0],x);
    for(pii it:pool) {
        if(!vis[it.first][it.second]) {
            return false;
        }
    }
    return true;
}

int BinSearch() {
    int l=0,r=1e9;
    while(l<=r) {
        // debug(l,r);
        int mid=(l+r)/2;
        if(Check(mid)) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return l;
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
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            int x;
            cin>>x;
            if(x) {
                pool.push_back({i,j});
            }
        }
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    ans=BinSearch();
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