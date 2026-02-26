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
const int maxn=55;

char mp[maxn][maxn];
int vis[maxn][maxn],N,M;

void DFS(int x,int y) {
    if(mp[x][y]=='B') {
        return;
    }
    for(int dir=0;dir<4;dir++) {
        int xv=x+dx[dir],yv=y+dy[dir];
        if(xv>=1 && xv<=N && yv>=1 && yv<=M && mp[xv][yv]=='B') {
            return;
        }
    }
    vis[x][y]=1;
    for(int dir=0;dir<4;dir++) {
        int xv=x+dx[dir],yv=y+dy[dir];
        if(xv>=1 && xv<=N && yv>=1 && yv<=M && !vis[xv][yv] && mp[xv][yv]!='#') {
            DFS(xv,yv);
        }
    }
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>(mp[i]+1);
    }
//--------Initiallize Bounded--------
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            vis[i][j]=0;
        }
    }
//--------No fluff real stuff--------
    DFS(N,M);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(mp[i][j]=='G' && !vis[i][j]) {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
    return;

}

int32_t main() {
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}