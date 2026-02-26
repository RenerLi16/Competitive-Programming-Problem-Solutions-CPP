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
#define fi first
#define se second

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e4+10;

pair<int,int> Seg[maxn];
int N;

struct FWT {
    int t[maxn<<1];
    void Add(int x,int k) {
        if(!x) return;
        for(;x<=(2*N);x=(x+(x&(-x)))) {
            t[x]+=k;
        }
    }
    int Ask(int x) {
        int res=0;
        for(;x;x=(x-(x&(-x)))) {
            res+=t[x];
        }
        return res;
    }
} at;

bool cmp(pii first,pii second) {
    return first.se<second.se || (first.se==second.se && first.fi<second.fi);
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=(N<<1);i++) {
        int x;
        cin>>x;
        if(!Seg[x].fi) {
            Seg[x].fi=i;
        } else if(!Seg[x].se) {
            Seg[x].se=i;
        }
    }
    sort(Seg+1,Seg+N+1,cmp);
    int sum=0;
    for(int i=1;i<=N;i++) {
        sum=(sum+at.Ask(Seg[i].fi));
        debug(i,Seg[i],at.Ask(Seg[i].fi));
        debug(at.Ask(Seg[i].fi-1),at.Ask(5));
        at.Add(Seg[i].fi,1);
        at.Add((Seg[i].se+1),(-1));
    }
    cout<<sum<<endl;
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