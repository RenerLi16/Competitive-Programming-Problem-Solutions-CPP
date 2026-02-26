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

int N,A[maxn],Q,pos[maxn], ans[maxn];

struct FWT {
    int pre[maxn];
    void Add(int x, int pos) {
        for(;pos<=N;pos+=(pos&(-pos))) {
            pre[pos]+=x;
        }
    }
    int Ask(int pos) {
        int ret=0;
        for(;pos;pos-=(pos&(-pos))) {
            ret+=pre[pos];
        }
        return ret;
    }
} ft;

vii hls;

struct Node {
    int id, l, r;
    friend bool operator < (Node x, Node y) {
        return x.r<y.r;
    }
} qry[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        hls.pb({A[i],i});
    }
    sort(hls.begin(),hls.end());
    int tot=1;
    for(int i=0;i<N;i++) {
        if(i!=0 && hls[i].fi!=hls[i-1].fi) {
            tot++;
        }
        A[hls[i].se]=tot;
    }
    for(int i=1;i<=Q;i++) {
        cin>>qry[i].l>>qry[i].r;
        qry[i].id=i;
    }
    sort(qry+1,qry+Q+1);
    int qpos=0;
    for(int i=1;i<=N;i++) {
        if(pos[A[i]]) {
            ft.Add((-1),pos[A[i]]);
        }
        pos[A[i]]=(N-i+1);
        ft.Add(1,pos[A[i]]);
        while(qpos<Q && (qry[qpos+1].r<=i)) {
            qpos++;
            debug(qpos);
            ans[qry[qpos].id]=ft.Ask(N-qry[qpos].l+1);
        }
    }
    for(int i=1;i<=Q;i++) {
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