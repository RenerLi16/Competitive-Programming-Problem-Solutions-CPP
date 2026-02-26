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
#define vstto vector<Edge>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=2005;

class DSU {
private:
    int fa[maxn];
public:
    DSU(int x) {
        for(int i=1;i<=x;i++) {
            fa[i]=i;
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        } else {
            fa[x]=getfa(fa[x]);
            return fa[x];
        }
    }
    void merge(int x,int y) {
        int xfa=fa[x],yfa=fa[y];
        if(xfa==yfa) {
            return;
        } else {
            fa[xfa]=yfa;
        }
    }
};

struct Edge{
    int w,u,v;
    friend bool operator < (Edge first,Edge second) {
        return first.w>second.w;
    }
};

vector<Edge> pool;
int N,A[maxn],ans;

void solve() {
//--------Initiallize--------
//--------Input--------
    int a[4000005];
    for(int i=1;i<=4000005;i++) {
        a[i]=1;
    }
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }

    for(int i=1;i<=N;i++) {
        for(int j=(i+1);j<=N;j++) {
            pool.push_back({(A[i]^A[j]),i,j});
        }
    }

    sort(pool.begin(),pool.end());

    DSU dd(N);
    for(auto [w,u,v]:pool) {
        debug(w);
        if(dd.getfa(u)==dd.getfa(v)) {
            continue;
        }
        debug(u,v,w);
        ans+=w;
        dd.merge(u,v);
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