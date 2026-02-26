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

int N,ans;

struct Node {
    pii x[3];
    int pos;
};
Node A[maxn];
vector<Node> buckets[3];

bool cmp(pii x,pii y) {
    return x.fi>y.fi;
}

bool cmp1(Node y,Node z) {
    return (y.x[y.pos].fi-y.x[y.pos+1].fi)>(z.x[z.pos].fi-z.x[z.pos+1].fi);
}

void solve() {
//--------Initiallize--------
    ans=0;
    buckets[0].clear();
    buckets[1].clear();
    buckets[2].clear();
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i].x[0].fi>>A[i].x[1].fi>>A[i].x[2].fi;
        A[i].x[0].se=0;
        A[i].x[1].se=1;
        A[i].x[2].se=2;
        A[i].pos=0;
        sort(A[i].x,A[i].x+3,cmp);
    }
    for(int i=1;i<=N;i++) {
        buckets[A[i].x[A[i].pos].se].push_back(A[i]);
    }
    for(int i=0;i<2;i++) {
        sort(buckets[0].begin(),buckets[0].end(),cmp1);
        sort(buckets[1].begin(),buckets[1].end(),cmp1);
        sort(buckets[2].begin(),buckets[2].end(),cmp1);
        while(buckets[0].size()>(N/2)) {
            buckets[0].back().pos++;
            buckets[buckets[0].back().x[buckets[0].back().pos].se].push_back(buckets[0].back());
            buckets[0].pop_back();
        }
        while(buckets[1].size()>(N/2)) {
            buckets[1].back().pos++;
            buckets[buckets[1].back().x[buckets[1].back().pos].se].push_back(buckets[1].back());
            buckets[1].pop_back();
        }
        while(buckets[2].size()>(N/2)) {
            buckets[2].back().pos++;
            buckets[buckets[2].back().x[buckets[2].back().pos].se].push_back(buckets[2].back());
            buckets[2].pop_back();
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<buckets[i].size();j++) {
            ans+=buckets[i][j].x[buckets[i][j].pos].fi;
        }
    }
    cout<<ans<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}