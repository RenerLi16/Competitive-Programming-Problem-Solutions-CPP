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
const int maxn=1005;

struct Node {
    int x,y,ind;
};

vector<Node> pool[2];
int N;
vector<pair<int,pii>> meet;
int vis[maxn],fa[maxn],ans[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='N') pool[0].push_back({x,y,i});
        else pool[1].push_back({x,y,i});
        fa[i]=i;
    }
    for(int i=0;i<pool[0].size();i++) {
        for(int j=0;j<pool[1].size();j++) {
            debug(i,j);
            int idist=(pool[1][j].y-pool[0][i].y),jdist=(pool[0][i].x-pool[1][j].x);
            debug(idist,jdist);
            if(idist<=0 || jdist<=0 || idist==jdist) continue;
            if(idist<jdist) meet.push_back({jdist,{pool[1][j].ind,pool[0][i].ind}});
            else meet.push_back({idist,{pool[0][i].ind,pool[1][j].ind}});
        }
    }
    sort(meet.begin(),meet.end());
    for(auto [t,p]:meet) {
        auto [x,y]=p;
        if(fa[x]!=x || fa[y]!=y) {
            continue;
        }else {
            debug(x,y,p,t,fa[y]);
            fa[x]=y;
        }
    }
    for(int i=1;i<=N;i++) {
        debug(fa[i]);
        int tmp=i;
        while(fa[tmp]!=tmp) {
            tmp=fa[tmp];
            ans[tmp]++;
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<ans[i]<<endl;
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