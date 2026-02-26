#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
#include <bitset>
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

#define LL long long
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
const int maxn=2010;

int A,B,n,m,ans,xpos[maxn],ypos[maxn];
vector<tiii> mp;

struct DSU {
    int fa[2*maxn*maxn],siz[2*maxn*maxn];
    void init() {
        for(int i=1;i<=((A+1)*(B+1));i++) {
            fa[i]=i;
            siz[i]=1;
        }
    }
    int getfa(int x) {
        //debug(x);
        if(fa[x]==x) {
            return x;
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) {
        x=getfa(x),y=getfa(y);
        if(x==y) {
            return;
        }
        if(siz[x]<siz[y]) {
            swap(x,y);
        }
        fa[y]=x;
        siz[x]+=siz[y];
    }
} su;

int hsh(int x, int y) {
    return (x-1)*(B+1)+y;
}

void Kruskal() {
    sort(mp.begin(),mp.end());
    for(auto [w,u,v]:mp) {
        if(su.getfa(u)!=su.getfa(v)) {
            ans+=w;
            su.merge(u,v);
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>A>>B>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>xpos[i];
    }
    sort(xpos+1,xpos+n+1);
    for(int i=1;i<=m;i++) {
        cin>>ypos[i];
    }
    sort(ypos+1,ypos+m+1);
    int cur=1;
    for(int i=1;i<=A;i++) {
        for(int j=1;j<=B;j++) {
            int cost=((i==xpos[cur]) ? 1 : 0);
            mp.pb({cost,hsh(i,j),hsh((i+1),j)});
            if(i==xpos[cur]) {
                if(cur<n) {
                    cur++;
                }
            }
        }
    }
    cur=1;
    for(int i=1;i<=A;i++) {
        for(int j=1;j<=B;j++) {
            int cost=((j==ypos[cur]) ? 1 : 0);
            mp.pb({cost,hsh(i,j),hsh(i,(j+1))});
            if(j==ypos[cur]) {
                if(cur<m) {
                    cur++;
                }
            }
        }
    }
    su.init();
    //return;
    Kruskal();
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