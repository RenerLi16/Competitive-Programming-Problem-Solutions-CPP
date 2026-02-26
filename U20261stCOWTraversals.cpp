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
const int maxn=2e5+10;

int N,M,fa[maxn],vis[maxn],tot,inring[maxn],cnt[3],active[maxn],pos[maxn],curType[maxn];
vi ring[maxn];
map<int,int> bp[maxn];

void DFS(int x, int id) {
    if(vis[x]) {
        return;
    }
    vis[x]=1;
    inring[x]=id;
    pos[x]=ring[id].size();
    ring[id].pb(x);
    DFS(fa[x],id);
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>fa[i];
    }
    for(int i=1;i<=N;i++) {
        if(!vis[i]) {
            tot++;
            DFS(i,tot);
        }
    }
    cin>>M;
    for(int i=1;i<=M;i++) {
        int x,_type;
        char type;
        cin>>x>>type;
        if(type=='C') {
            _type=0;
        } else if(type=='O') {
            _type=1;
        } else if(type=='W') {
            _type=2;
        }
        if(active[x]) {
            bp[inring[x]].erase(pos[x]);
        }
        active[x]=1;
        bp[inring[x]].insert({pos[x],type});
        int c=inring[x],l=(int)ring[c].size(),px=pos[x];
        auto dist=[&](int p,int q)->int {
            return (q-p+l)%l;
        };
        auto &mp=bp[c];
        auto lb=mp.upper_bound(px);
        if(lb==mp.end()) {
            lb=mp.begin();
        }
        int spos=lb->fi,snod=lb->se;
        auto rb=mp.lower_bound(px);
        if(rb==mp.begin()) {
            rb=mp.end();
        }
        --rb;
        int prevpos=rb->fi;
        int _len=((int)mp.size()==1 ? l : dist(prevpos,spos));
        int len1=dist(prevpos,px);
        int len2=dist(px,spos);
        cnt[curType[snod]]-=_len;
        cnt[curType[snod]]+=len2;
        cnt[_type]+=len1;
        cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
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