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
const int maxn=1e5+10;

int N,Q,h[maxn];
int t[2][maxn];

void Add(int p,int x,int k) {
    for(;x<=N;x=(x+(x&(-x)))) {
        t[p][x]=(t[p][x]+k);
    }
}

int Ask(int p,int x) {
    int res=0;
    for(;x;x=(x-(x&(-x)))) {
        res=(res+t[p][x]);
    }
    return res;
}

int GetSum(int p) {
    return ((p+1)*Ask(0,p)-Ask(1,p));
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>h[i];
        Add(0,i,(h[i]-h[i-1]));
        Add(1,i,(i*(h[i]-h[i-1])));
    }
    while(Q--) {
        int type,x,y;
        cin>>type;
        if(type==1) {
            int k;
            cin>>x>>y>>k;
            Add(0,x,k); Add(0,(y+1),(-k));
            Add(1,x,x*k); Add(1,(y+1),((y+1)*(-k)));
        }else {
            cin>>x>>y;
            cout<<(GetSum(y)-GetSum(x-1))<<endl;
        }
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