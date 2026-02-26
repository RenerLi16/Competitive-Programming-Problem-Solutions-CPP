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
const int maxn=1e5+10;

struct Node {
    int id,x,y;
} pool[maxn*2];

bool cmpx(Node a, Node b) {
    return a.x<b.x;
}

bool cmpy(Node a, Node b) {
    return a.y<b.y;
}

vii mp[maxn*2];
int N,xa,ya,xb,yb,dist[maxn*2];

void OZBFS() {
    memset(dist,0x3f,sizeof(dist));
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(N+1);
    dist[1]=0;
    dist[N+1]=0;
    while(!dq.empty()) {
        int cur=dq.front();
        dq.pop_front();
        for(auto [nxt,w]:mp[cur]) {
            if(dist[nxt]>(dist[cur]+w)) {
                dist[nxt]=(dist[cur]+w);
                if(w) {
                    dq.push_back(nxt);
                } else {
                    dq.push_front(nxt);
                }
            }
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>xa>>ya>>xb>>yb;
    pool[1]={1,xa,ya};
    pool[N+2]={(N+2),xb,yb};
    N+=2;
    for(int i=2;i<N;i++) {
        cin>>pool[i].x>>pool[i].y;
        pool[i].id=i;
    }
    for(int i=(N+1);i<=(N*2);i++) {
        pool[i]=pool[i-N];
        pool[i].id=i;
        mp[i].pb({(i-N),1});
        mp[i-N].pb({i,1});
    }
    sort(pool+1,pool+N+1,cmpx);
    sort(pool+N+1,pool+N*2+1,cmpy);
    for(int i=2;i<=N;i++) {
        if(pool[i].x==pool[i-1].x) {
            mp[pool[i].id].pb({(pool[i-1].id),0});
            mp[pool[i-1].id].pb({(pool[i].id),0});
        }
        if(pool[i+N].y==pool[i+N-1].y) {
            mp[pool[i+N].id].pb({(pool[i+N-1].id),0});
            mp[pool[i+N-1].id].pb({(pool[i+N].id),0});
        }
    }
    OZBFS();
    cout<<min(dist[N],dist[N*2])<<endl;
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