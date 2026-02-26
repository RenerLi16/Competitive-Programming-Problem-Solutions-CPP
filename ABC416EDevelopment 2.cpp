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
const int maxn=505;

vi pool,mp[maxn];
double dist[maxn][maxn],ans;
int uvis[maxn],vvis[maxn],N,M,K,T,Q;

void DFS2(int x,int src,int u,int v,double w) {
    if(x==src || x==u || src==v) {
        return;
    }
    vvis[x]=1;
    if(!dist[src][x] || dist[src][x]>dist[src][u]+dist[u][v]+dist[v][x]) {
        int ddist=dist[src][x]-(dist[src][u]+dist[u][v]+dist[v][x]);
        // ans-=2*ddist;
        dist[x][src]-=ddist;
        dist[src][x]-=ddist;
    }
    for(int to:mp[x]) {
        if(!vvis[to]) {
            DFS2(to,src,u,v,w);
        }
    }
}

void DFS1(int x,int u,int v,double w) {
    // debug(x,u,v,w);
    uvis[x]=1;
    memset(vvis,0,sizeof(vvis));
    DFS2(v,x,u,v,w);
    for(int to:mp[x]) {
        if(!uvis[to]) {
            DFS1(to,u,v,w);
        }
    }
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int uu,vv,ww;
        cin>>uu>>vv>>ww;
        mp[uu].push_back(vv);
        mp[vv].push_back(uu);
        dist[uu][vv]=ww;
        dist[vv][uu]=ww;
    }
    cin>>K>>T;
    for(int i=1;i<=K;i++) {
        int x;
        cin>>x;
        mp[x].push_back(0);
        mp[0].push_back(x);
        dist[x][0]=1.0*T/2;
        dist[0][x]=1.0*T/2;
        pool.push_back(x);
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    // for(int i=0;i<pool.size();i++) {
    //     for(int j=0;j<pool.size();j++) {
    //         if(dist[pool[i]][pool[j]]>T) {
    //             int ddist=dist[pool[i]][pool[j]]-T;
    //             ans-=2*ddist;
    //             dist[pool[i]][pool[j]]=T;
    //             dist[pool[j]][pool[i]]=T;
    //         }
    //     }
    // }
    for(int k=0;k<=N;k++) {
        for(int i=0;i<=N;i++) {
            for(int j=0;j<=N;j++) {
                if(i!=j && dist[i][k] && dist[k][j] && (!dist[i][j] || dist[i][j]>dist[i][k]+dist[k][j])) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    // for(int i=0;i<=N;i++) {
    //     for(int j=0;j<=N;j++) {
    //         debug(i,j,dist[i][j]);
    //     }
    // }
    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=N;j++) {
    //         ans+=dist[i][j];
    //     }
    // }
    cin>>Q;
    while(Q--) {
        memset(uvis,0,sizeof(uvis));
        int x;
        cin>>x;
        if(x==1) {
            int uu,vv,ww;
            cin>>uu>>vv>>ww;
            mp[uu].push_back(vv);
            mp[vv].push_back(uu);
            if(!dist[uu][vv] || dist[uu][vv]>ww) {
                int ddist=dist[uu][vv]-ww;
                // ans-=2*ddist;
                dist[uu][vv]=ww;
                dist[vv][uu]=ww;
            }
            DFS1(uu,uu,vv,ww);
            // for(int i=0;i<=N;i++) {
            //     for(int j=0;j<=N;j++) {
            //         debug(i,j,dist[i][j]);
            //     }
            // }
        } else if(x==2) {
            int pos;
            cin>>pos;
            pool.push_back(pos);
            mp[pos].push_back(0);
            mp[0].push_back(pos);
            if(!dist[pos][0] || dist[pos][0]>(1.0*T/2)) {
                int ddist=dist[pos][0]-1.0*T/2;
                // ans-=2*ddist;
                dist[pos][0]=1.0*T/2;
                dist[0][pos]=1.0*T/2;
            }
            DFS1(0,0,pos,(1.0*T/2));
            // for(int i=0;i<=N;i++) {
            //     for(int j=0;j<=N;j++) {
            //         debug(i,j,dist[i][j]);
            //     }
            // }
        } else {
            ans=0;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    ans+=dist[i][j];
                }
            }
            cout<<ans<<endl;
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