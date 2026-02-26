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

#define ll long long
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

struct Node {
    int val,id;
    friend bool operator < (Node first,Node second) {
        return first.val<second.val;
    }
} pool[maxn];

set<int> pikd;
multiset<int> dist;
int N,B;
map<int,int>ans;

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>B;
    for(int i=1;i<=N;i++) {
        cin>>pool[i].val;
        pool[i].id=i;
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    sort(pool+2,pool+N);
    pikd.insert(1);
    pikd.insert(N);
    dist.insert(N-1);
    ans[0]=N-1;
    for(int i=2;i<N;i++) {
        auto pos=pikd.upper_bound(pool[i].id);
        auto posr=pos,posl=--pos;
        debug(pool[i].val,pool[i].id,*posl,*posr,*dist.lower_bound(*posr-*posl));
        dist.erase(dist.lower_bound(*posr-*posl));
        dist.insert(*posr-pool[i].id);
        dist.insert(pool[i].id-*posl);
        pikd.insert(pool[i].id);
        ans[pool[i].val]=*--dist.end();
    }
    for(auto it:ans) {
        debug(it);
    }
    for(int i=1;i<=B;i++) {
        int ss,dd;
        cin>>ss>>dd;
        auto pos=ans.lower_bound(ss);
        if((pos->first)!=ss || pos==ans.end()) {
            pos--;
        }
        cout<<((pos->second)<=dd ? 1 : 0)<<endl;
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