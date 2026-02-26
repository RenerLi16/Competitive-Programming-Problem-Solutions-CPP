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
const int maxn=5e5+10;

int N,K,A[maxn],pre[maxn],nxt[maxn],tmp[maxn];
vi stkmim;

void Add(int l, int r, int x, int d) {
    if(l>r) {
        return;
    }
    int y=(x+(d*(r-l)));
    tmp[l]+=x;
    tmp[l+1]+=(d-x);
    tmp[r+1]+=(-y-d);
    tmp[r+2]+=y;
    return;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    int mn=(-1);
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        if(mn==(-1) || A[i]<A[mn]) {
            mn=i;
        }
    }
    for(int i=(mn+1);i<=N;i++) {
        tmp[i-mn]=A[i];
    }
    for(int i=mn;i>=1;i--) {
        A[i+N-mn]=A[i];
    }
    for(int i=1;i<=(N-mn);i++) {
        A[i]=tmp[i];
    }
    stkmim.push_back(0);
    for(int i=1;i<=N;i++) {
        while(!stkmim.empty() && (A[stkmim.back()]>A[i])) {
            stkmim.pop_back();
        }
        pre[i]=stkmim.back();
        stkmim.push_back(i);
    }
    while(!stkmim.empty()) {
        stkmim.pop_back();
    }
    stkmim.push_back(N+1);
    for(int i=N;i>=1;i--) {
        while(!stkmim.empty() && (A[stkmim.back()]>=A[i])) {
            stkmim.pop_back();
        }
        nxt[i]=stkmim.back();
        stkmim.push_back(i);
    }
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=N;i++) {
        Add(1,(i-pre[i]-1),(2*A[i]),A[i]);
        Add((i-pre[i]),N,((i-pre[i])*A[i]),0);
        if(nxt[i]<(N+1)) {
            Add((nxt[i]-i),(nxt[i]-pre[i]-1),(-A[i]),(-A[i]));
            Add((nxt[i]-pre[i]),N,(-(i-pre[i])*A[i]),0);
        }
    }
    for(int i=1;i<=N;i++) {
        tmp[i]+=tmp[i-1];
    }
    for(int i=1;i<=N;i++) {
        tmp[i]+=tmp[i-1];
    }
    for(int i=1;i<=N;i++) {
        cout<<tmp[i]<<endl;
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