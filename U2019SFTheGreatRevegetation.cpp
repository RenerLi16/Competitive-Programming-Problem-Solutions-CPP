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
const int maxn=1e5+10;

struct DSU {
    int fa[maxn*2],siz;
    void init() {
        for(int i=1;i<=siz;i++) fa[i]=i;
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return fa[x];
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void merge(int x,int y) {
        int xfa=getfa(x),yfa=getfa(y);
        if(xfa==yfa) {
            return;
        }
        fa[xfa]=yfa;
    }
} Uni,S;

int N,M;
int vis[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    Uni.siz=N;
    S.siz=(N*2+10);
    Uni.init();
    S.init();
    for(int i=1;i<=M;i++) {
        char c;
        cin>>c;
        int u,v;
        cin>>u>>v;
        Uni.merge(u,v);
        int u1=u,u2=(u1+N),v1=v,v2=(v1+N);
        if(c=='D') {
            if(S.getfa(u1)==S.getfa(v1) || S.getfa(u2)==S.getfa(v2)) {
                cout<<0<<endl;
                return;
            }
            S.merge(u1,v2),S.merge(u2,v1);
        } else {
            if(S.getfa(u1)==S.getfa(v2) || S.getfa(u2)==S.getfa(v1)) {
                cout<<0<<endl;
                return;
            }
            S.merge(u1,v1),S.merge(u2,v2);
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++) {
        if(!vis[Uni.getfa(i)]) {
            vis[Uni.getfa(i)]=1;
            ans++;
        }
    }
    if(N==0) {
        cout<<0<<endl;
        return;
    }
    cout<<"1";
    for(int i=1;i<=ans;i++) cout<<"0";
    cout<<endl;
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