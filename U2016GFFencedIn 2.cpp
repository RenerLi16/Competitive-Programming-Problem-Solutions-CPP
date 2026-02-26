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

#define ll long long
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
const int maxedge=4e6+10;

struct DSU {
    int tot;
    pii fa[maxn][maxn];
    void init(pii siz) {
        tot=(max(siz.fi,siz.se));
        for(int i=1;i<=tot;i++) {
            for(int j=1;j<=tot;j++) {
                fa[i][j]={i,j};
            }
        }
    }
    pii getf(pii x) {
        if(fa[x.fi][x.se]==x) {
            return x;
        } else {
            fa[x.fi][x.se]=getf(fa[x.fi][x.se]);
            return fa[x.fi][x.se];
        }
    }
    void merge(pii x,pii y) {
        pii xfa=getf(x),yfa=getf(y);
        if(xfa==yfa) {
            return;
        }
        fa[xfa.fi][xfa.se]=yfa;
    }
}dd;

struct Edge{
    int w;
    pii u,v;
    friend bool operator<(Edge first, Edge second) {
        return first.w<second.w;
    }
};

vector<Edge> pool;
int len1,len2,N,M,A[maxn],B[maxn];
ll ans;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>len1>>len2>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<=M;i++) {
        cin>>B[i];
    }

    sort(A+1,A+N+1);
    sort(B+1,B+M+1);

    A[N+1]=len1;
    N++;
    B[M+1]=len2;
    M++;
    for(int i=N;i>=1;i--) {
        A[i]-=A[i-1];
    }
    for(int i=M;i>=1;i--) {
        B[i]-=B[i-1];
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(i<N) {
                pool.push_back({B[j],{i,j},{(i+1),j}});
                debug(pool.back().w,pool.back().u,pool.back().v);
            }
            if(j<M) {
                pool.push_back({A[i],{i,j},{i,(j+1)}});
                debug(pool.back().w,pool.back().u,pool.back().v);
            }
        }
    }

    sort(pool.begin(),pool.end());

    dd.init({N,M});
    for(auto [w,u,v]:pool) {
        if(dd.getf(u)==dd.getf(v)) {
            continue;
        }
        ans+=((ll)(w));
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