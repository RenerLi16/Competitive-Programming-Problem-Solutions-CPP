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

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1005;

pii fjpos[maxn];
pii bpos[maxn];
int N,M,fjx,fjy,bx,by,f[maxn][maxn];

int dist(pii first,pii second) {
    return (sqsq(first.fi-second.fi)+sqsq(first.se-second.se));
}

void solve() {
//--------Initiallize--------
    memset(f,0x3f,sizeof(f));
//--------Input--------
    cin>>N>>M;
    cin>>fjx>>fjy;
    cin>>bx>>by;
    fjpos[0]={fjx,fjy};
    bpos[0]={bx,by};
    for(int i=1;i<=N;i++) {
        char c;
        cin>>c;
        fjpos[i]=fjpos[i-1];
        if(c=='N') {
            fjpos[i].se++;
        } else if(c=='E') {
            fjpos[i].fi++;
        } else if(c=='S') {
            fjpos[i].se--;
        } else if(c=='W') {
            fjpos[i].fi--;
        }
    }
    for(int i=1;i<=M;i++) {
        char c;
        cin>>c;
        bpos[i]=bpos[i-1];
        if(c=='N') {
            bpos[i].se++;
        } else if(c=='E') {
            bpos[i].fi++;
        } else if(c=='S') {
            bpos[i].se--;
        } else if(c=='W') {
            bpos[i].fi--;
        }
    }
    // for(int i=0;i<=N;i++) {
    //     cout<<fjpos[i].fi<<" "<<fjpos[i].se<<endl;
    // }
    // cout<<endl;
    // for(int i=0;i<=M;i++) {
    //     cout<<bpos[i].fi<<" "<<bpos[i].se<<endl;
    // }
    f[0][0]=0;//dist({fjx,fjy},{bx,by});
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            if(i<N) {
                f[i+1][j]=min(f[i+1][j],f[i][j]+dist(fjpos[i+1],bpos[j]));
            }
            if(i<N && j<M) {
                f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+dist(fjpos[i+1],bpos[j+1]));
            }
            if(j<M) {
                f[i][j+1]=min(f[i][j+1],f[i][j]+dist(fjpos[i],bpos[j+1]));
            }
        }
    }
    cout<<f[N][M]<<endl;
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