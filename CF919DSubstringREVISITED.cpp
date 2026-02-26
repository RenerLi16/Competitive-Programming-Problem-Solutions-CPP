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

#define int long long
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
const int maxn=3e5+10;

vi mp[maxn],ord;
int N,M,f[maxn][30],deg[maxn],ans;
char ch[maxn];

void topologicalExpansion() {
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(!deg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        ord.pb(cur);
        for(auto nxt:mp[cur]) {
            deg[nxt]--;
            if(deg[nxt]==0) {
                q.push(nxt);
            }
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    cin>>(ch+1);
    for(int i=1;i<=M;i++) {
        int u,v;
        cin>>u>>v;
        mp[u].pb(v);
        deg[v]++;
    }
    topologicalExpansion();
    if(ord.size()<N) {
        cout<<(-1)<<endl;
        return;
    }
    for(int i=0;i<N;i++) {
        f[ord[i]][ch[ord[i]]-'a'+1]=1;
    }
    for(int i=0;i<N;i++) {
        for(int j=1;j<=26;j++) {
            for(auto nxt:mp[ord[i]]) {
                f[nxt][j]=max(f[nxt][j],(f[ord[i]][j]+((ch[nxt]-'a'+1)==j)));
            }
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=26;j++) {
            ans=max(ans,f[i][j]);
        }
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