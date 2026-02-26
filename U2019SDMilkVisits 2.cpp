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

vi mp[maxn];
int tag[maxn],tot,N,M,ans;
char A[maxn];

void DFS(int x) {
    tag[x]=tot;
    for(int v:mp[x]) {
        if(!tag[v] && A[x]==A[v]) {
            DFS(v);
        }
    }
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<N;i++) {
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    for(int i=1;i<=N;i++) {
        if(!tag[i]) {
            tot++;
            DFS(i);
        }
    }
    for(int i=1;i<=M;i++) {
        ans=0;
        int x,y;
        char c;
        cin>>x>>y>>c;
        if((tag[x]==tag[y] && A[x]==c) || tag[x]!=tag[y]) {
            ans=1;
        }
        cout<<ans;
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