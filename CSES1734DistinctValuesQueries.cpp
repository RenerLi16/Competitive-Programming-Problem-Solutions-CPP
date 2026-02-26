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
const int maxn=2e5+10;

struct FWT {
    int siz,c[maxn];
    void Add(int pos,int x) {
        for(int i=pos;i<=siz;i+=(i&-i)) {
            c[i]+=x;
        }
    }
    int Ask(int pos) {
        if(pos==0) {
            return 0;
        }
        int tmp=0;
        for(int i=pos;i>0;i-=(i&-i)) {
            tmp+=c[i];
        }
        return tmp;
    }
} ft;

int N,Q,A[maxn],ans[maxn];
vii hls;
tuple<int,int,int> pool[maxn];
map<int,int> mp;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        hls.push_back({A[i],i});
    }
    sort(hls.begin(),hls.end());
    int tmp=0;
    for(int i=0;i<N;i++) {
        if(i==0 || hls[i].fi!=hls[i-1].fi) {
            tmp++;
        }
        A[hls[i].se]=tmp;
    }
    //for(int i=1;i<=N;i++) {
        //cout<<A[i]<<" ";
    //}
    //cout<<endl;
    for(int i=1;i<=Q;i++) {
        int x,y;
        cin>>x>>y;
        pool[i]={y,x,i};
    }
    sort(pool+1,pool+Q+1);
    ft.siz=N;
    int pos=1;
    for(int i=1;i<=Q;i++) {
        auto [r,l,id]=pool[i];
        for(;pos<=r;pos++) {
            if(mp.count(A[pos])!=0) {
                ft.Add(mp[A[pos]],(-1));
            }
            ft.Add(pos,1);
            mp[A[pos]]=pos;
        }
        ans[id]=(ft.Ask(r)-ft.Ask(l-1));
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