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
const int maxcow=1e6+10;

map<int,int> cnt;
pair<int,pii> pool[maxn];
pii hls[maxn];
int a[maxcow],N,G,ans;

void solve() {
    // Initiallize Boundless
    cnt.clear();
    // Input
    cin>>N>>G;
    for(int i=1;i<=N;i++) {
        cin>>pool[i].first>>pool[i].second.first>>pool[i].second.second;
        hls[i]={pool[i].second.first,i};
    }
    // Initiallize Bounded
    sort(hls+1,hls+N+1);
    int tot=0;
    for(int i=1;i<=N;i++) {
        if(hls[i-1].first!=hls[i].first) {
            tot++;
        }
        pool[hls[i].second].second.first=tot;
    }
    for(int i=0;i<maxcow;i++) a[i]=G;
    cnt[G]=maxcow;
    // No fluff real stuff
    sort(pool+1,pool+N+1);
    for(int i=1;i<=N;i++) {
        debug(pool[i].first,pool[i].second);
    }
    for(int i=1;i<=N;i++) {
        auto endpnt=--cnt.end();
        int mx=endpnt->first,fm=a[pool[i].second.first],to=a[pool[i].second.first]+pool[i].second.second;
        if(fm==mx) {
            auto tmp=--cnt.end();
            if(endpnt->second==1 && (--tmp)->first>=to) {
                ans++;
            } else if(endpnt->second>1) {
                ans++;
            }
        } else if(to>=mx) {
            ans++;
        }
        cnt[fm]--;
        if(cnt[fm]==0) {
            cnt.erase(fm);
        }
        cnt[to]++;
        a[pool[i].second.first]=to;
        debug(cnt[to],*endpnt,*--cnt.end(),fm,to);
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