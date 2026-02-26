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
const int maxn=20;
const int maxedge=1005;
const int maxstat=(1<<12)+10;

int f[maxn][maxstat],g[maxn][maxstat],N,M,mp[maxn][maxn],ans=INF;

void solve() {
    // Initiallize
    memset(mp,0x3f,sizeof(mp));
    for(int i=0;i<maxn;i++) mp[i][i]=0;
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<12;i++) f[1][1<<i]=0;
    // No fluff real stuff
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int uu,vv,ww;
        cin>>uu>>vv>>ww;
        uu--;
        vv--;
        mp[uu][vv]=min(mp[uu][vv],ww);
        mp[vv][uu]=min(mp[vv][uu],ww);
    }
//    cout<<1<<endl;
    for(int i=0;i<N;i++) {
        for(int S=1;S<(1<<N);S++) {
            g[i][S]=0x3f3f3f3f;
            for(int j=0;j<N;j++) {
                if(S&(1<<j)) {
                    g[i][S]=min(g[i][S],mp[i][j]);
                }
            }
        }
    }
    for(int h=1;h<N-1;h++) {
        for(int S=1;S<(1<<N);S++) {
            if(f[h][S]>0x3f3f3f3f) {
                continue;
            }
            for(int T=1;T<(1<<N);T++) {
                if((S&T)>0) {
                    continue;
                }
                ll sum=0;
                for(int w=0;w<N;w++) {
                    if((1<<w)&T) {
                        sum+=g[w][S];
                    }
                }

                if(sum<0x3f3f3f3f) {
                    f[h+1][S|T]=min(f[h+1][S|T],f[h][S]+(int)sum*h);
                }
            }
        }
    }
    for(int h=1;h<=N;h++) {
        ans=min(ans,f[h][(1<<N)-1]);
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