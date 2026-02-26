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
#include <random>
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
#define tiii tuple<int,int,int>
#define vstto vector<Edge>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=45;

struct Node {
    int x,y;
    friend bool operator < (Node fst, Node snd) {
        if(fst.x==0 && fst.y==0) {
            return true;
        }
        if(snd.x==0 && snd.y==0) {
            return false;
        }
        return (fst.x*snd.y)>(fst.y*snd.x);
    }
    friend Node operator - (Node fst, Node snd) {
        return {(fst.x-snd.x),(fst.y-snd.y)};
    }
} A[maxn];

bool further(int bas, int x, int y) {
    return (A[y]-A[bas])<(A[x]-A[bas]);
}

bool ok(int i, int j, int k, int l) {
    if(further(i,j,k)) {
        return (further(i,j,l) && further(j,k,l) && further(k,i,l));
    } else {
        return (further(i,k,l) && further(k,j,l) && further(j,i,l));
    }
}

int N,f[maxn][maxn][maxn][maxn],g[maxn][maxn][maxn][maxn],num[maxn][maxn][maxn],ans;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    int xx=0,yy=0;
    for(int i=1;i<=N;i++) {
        cin>>A[i].x>>A[i].y;
        if(A[i].x<xx && (A[i].x==xx && A[i].y<=yy)) {
            xx=A[i].x;
            yy=A[i].y;
        }
    }
    for(int i=1;i<=N;i++) {
        A[i].x-=xx;
        A[i].y-=yy;
    }
    sort(A+1,A+N+1);
    for(int i=1;i<=N;i++) {
        for(int j=(i+1);j<=N;j++) {
            for(int k=(j+1);k<=N;k++) {
                f[0][i][j][k]=6;
                for(int l=1;l<=N;l++) {
                    if(l!=i && l!=j && l!=k && ok(i,j,k,l)) {
                        g[i][j][k][l]=1;
                        num[i][j][k]++;
                    }
                }
            }
        }
    }
    for(int l=1;l<=(N-3);l++) {
        for(int i=1;i<=N;i++) {
            for(int j=(i+1);j<=N;j++) {
                for(int k=(j+1);k<=N;k++) {
                    f[l][i][j][k]=((f[l-1][i][j][k]*(num[i][j][k]+1-l))%MOD);
                    for(int nxt=(i+1);nxt<=(j-1);nxt++) {
                        if(g[i][j][k][nxt]) {
                            f[l][i][j][k]=((f[l][i][j][k]+f[l-1][i][nxt][k]+f[l-1][i][nxt][j]+f[l-1][nxt][j][k])%MOD);
                        }
                    }
                    for(int nxt=(j+1);nxt<=(k-1);nxt++) {
                        if(g[i][j][k][nxt]) {
                            f[l][i][j][k]=((f[l][i][j][k]+f[l-1][i][nxt][k]+f[l-1][j][nxt][k]+f[l-1][i][j][nxt])%MOD);
                        }
                    }
                    if(l==(N-3)) {
                        ans=((ans+f[l][i][j][k])%MOD);
                    }
                }
            }
        }
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