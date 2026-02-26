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
const int maxn=2e5+10;

int N,A[maxn],cnt[maxn],Q;

struct FWT {
    int t[maxn];
    void Add(int x,int k) {
        if(!x) return;
        for(;x<=N;x+=(x&(-x))) {
            t[x]+=k;
        }
    }
    int Ask(int x) {
        int res=0;
        for(;x;x-=(x&(-x))) {
            res+=t[x];
        }
        return res;
    }
} at,asum,anum;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        cnt[i]=(i-1-at.Ask(A[i]));
        at.Add(A[i],1);
    }
    // return;
    for(int i=1;i<=N;i++) {
        anum.Add(cnt[i],1);
        asum.Add(cnt[i],cnt[i]);
    }
    // return;
    while(Q--) {
        int type,x;
        cin>>type>>x;
        if(type==1) {
            if(A[x]>A[x+1]) {
                anum.Add(cnt[x+1],-1);
                asum.Add(cnt[x+1],-cnt[x+1]);
                --cnt[x+1];
                anum.Add(cnt[x+1],1);
                asum.Add(cnt[x+1],cnt[x+1]);
                swap(A[x],A[x+1]);
                swap(cnt[x],cnt[x+1]);
            }else {
                anum.Add(cnt[x],-1);
                asum.Add(cnt[x],-cnt[x]);
                ++cnt[x];
                anum.Add(cnt[x],1);
                asum.Add(cnt[x],cnt[x]);
                swap(A[x],A[x+1]);
                swap(cnt[x],cnt[x+1]);
            }
        }else if(type==2) {
            if(x>=N) {
                cout<<0<<endl;
            }else {
                cout<<((asum.Ask(N)-asum.Ask(x))-(x*(anum.Ask(N)-anum.Ask(x))))<<endl;
            }
            // return;
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