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
#define fi first
#define se second

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1005;

struct Edge{
    int u,v,w;
} pool[maxn];

vi mp[maxn];
int N,A[maxn],tag[maxn],M,vis[maxn];

void DFS(int x,int colr) {
    debug(x,colr);
    vis[x]=1;
    tag[x]=colr;
    for(int v:mp[x]) {
        if(!vis[v]) {
            DFS(v,colr);
        }
    }
}

bool Check(int lb) {
    for(int i=1;i<=N;i++) {
        mp[i].clear();
        tag[i]=0;
        vis[i]=0;
    }
    for(int i=1;i<=M;i++) {
        if(pool[i].w>=lb) {
            mp[pool[i].u].push_back(pool[i].v);
            mp[pool[i].v].push_back(pool[i].u);
        }
    }
    for(int i=1;i<=N;i++) {
        if(!vis[i]) {
            DFS(i,i);
        }
    }
    for(int i=1;i<=N;i++) {
        debug(i,tag[i]);
    }
    for(int i=1;i<=N;i++) {
        if(tag[i]!=tag[A[i]]) {
            return false;
        }
    }
    return true;
}

int BinSearch() {
    int l=0,r=1e9;
    while(l<=r) {
        debug(l,r);
        int mid=((l+r)/2);
        if(Check(mid)) {
            l=(mid+1);
        } else {
            r=(mid-1);
        }
    }
    return r;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<=M;i++) {
        cin>>pool[i].u>>pool[i].v>>pool[i].w;
    }
    cout<<BinSearch()<<endl;
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