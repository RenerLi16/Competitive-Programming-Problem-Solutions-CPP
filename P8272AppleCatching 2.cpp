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
const int maxn=2e5+10;

struct Node {
    int lb,rb,num,q;
    friend bool operator < (Node first,Node second) {
        return first.lb<second.lb || first.lb==second.lb && first.q<second.q;
    }
} pool[maxn];

map<int,int> mp;
int N,ans;

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        int qq,tt,xx,nn;
        cin>>qq>>tt>>xx>>nn;
        pool[i]={tt-xx,tt+xx,nn,qq};
    }
    sort(pool+1,pool+N+1);
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    // return;
    for(int i=1;i<=N;i++) {
        if(pool[i].q==1) {
            mp[pool[i].rb]+=pool[i].num;
        } else {
            while(!mp.empty()) {
                auto pos=mp.upper_bound(pool[i].rb);
                if(pos==mp.begin() || !pool[i].num) {
                    break;
                }
                --pos;
                auto [rcur,numcur]=*pos;
                mp.erase(rcur);
                int tmp=min(numcur,pool[i].num);
                ans+=tmp;
                numcur-=tmp;
                pool[i].num-=tmp;
                // debug(rcur,numcur,tmp);
                if(numcur>0) {
                    mp.insert({rcur,numcur});
                }
            }
        }
        // debug(pool[i].q,pool[i].lb,pool[i].rb,pool[i].num,ans);
    }
    cout<<ans<<endl;
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