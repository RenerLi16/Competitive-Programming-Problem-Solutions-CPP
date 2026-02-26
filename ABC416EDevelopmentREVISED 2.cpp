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

const int INF=2e13+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=505;

int N,M,K,T,Q,ans;
int dist[maxn][maxn];

void Floyed() {
    for(int k=0;k<=N;k++) {
        for(int i=0;i<=N;i++) {
            for(int j=0;j<=N;j++) {
                dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }
    }
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            if(i!=j) {
                dist[i][j]=INF;
            }
        }
    }
    for(int i=1;i<=M;i++) {
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        dist[aa][bb]=min(dist[aa][bb],cc*2);
        dist[bb][aa]=min(dist[bb][aa],cc*2);
    }
    cin>>K>>T;
    for(int i=1;i<=K;i++) {
        int dd;
        cin>>dd;
        dist[dd][0]=min(dist[dd][0],T);
        dist[0][dd]=min(dist[0][dd],T);
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    Floyed();
    cin>>Q;
    for(int i=1;i<=Q;i++) {
        int type,x=INF,y=INF,t;
        cin>>type;
        if(type==1) {
            cin>>x>>y>>t;
            dist[x][y]=min(dist[x][y],t*2);
            dist[y][x]=min(dist[y][x],t*2);
        } else if(type==2) {
            cin>>x;
            y=0;
            t=T;
            dist[x][0]=min(dist[x][0],T);
            dist[0][x]=min(dist[0][x],T);
        } else {
            ans=0;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    if(dist[i][j]!=INF) {
                        ans+=dist[i][j];
                    }
                }
            }
            ans=(ans/2);
            cout<<ans<<endl;
        }
        if(x!=INF || y!=INF) {
            for(int i=0;i<=N;i++) {
                for(int j=0;j<=N;j++) {
                    dist[i][j]=min(dist[i][j],(dist[i][x]+dist[y][j]+dist[x][y]));
                    dist[i][j]=min(dist[i][j],(dist[i][y]+dist[x][j]+dist[y][x]));
                }
            }
        }
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