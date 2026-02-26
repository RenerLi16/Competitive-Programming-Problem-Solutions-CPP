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

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e4+10;

pii pool[maxn];
int N;
int mn[maxn],mx[maxn],s=INF;

bool cmpx(pii first,pii second) {
    return first.first<second.first;
}

bool cmpy(pii first,pii second) {
    return first.second<second.second;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>pool[i].first>>pool[i].second;
    }
    sort(pool+1,pool+N+1,cmpx);
    memset(mx,0,sizeof(mx));
    memset(mn,0x3f,sizeof(mn));
    mx[N]=pool[N].second;
    mn[N]=pool[N].second;
    for(int i=(N-1);i>=1;i--) {
        mx[i]=max(pool[i].second,mx[i+1]);
        mn[i]=min(pool[i].second,mn[i+1]);
    }
    int tmpmn=pool[1].second,tmpmx=pool[1].second;
    for(int i=1;i<N;i++) {
        tmpmx=max(pool[i].second,tmpmx);
        tmpmn=min(pool[i].second,tmpmn);
        s=min(s,(tmpmx-tmpmn)*(pool[i].first-pool[1].first)+(mx[i+1]-mn[i+1])*(pool[N].first-pool[i+1].first));
    }
    debug(s);
    sort(pool+1,pool+N+1,cmpy);
    memset(mx,0,sizeof(mx));
    memset(mn,0x3f,sizeof(mn));
    mx[N]=pool[N].first;
    mn[N]=pool[N].first;
    for(int i=(N-1);i>=1;i--) {
        mx[i]=max(pool[i].first,mx[i+1]);
        mn[i]=min(pool[i].first,mn[i+1]);
    }
    tmpmn=pool[1].first,tmpmx=pool[1].first;
    for(int i=1;i<N;i++) {
        tmpmx=max(pool[i].first,tmpmx);
        tmpmn=min(pool[i].first,tmpmn);
        s=min(s,(tmpmx-tmpmn)*(pool[i].second-pool[1].second)+(mx[i+1]-mn[i+1])*(pool[N].second-pool[i+1].second));
    }
    debug(s);
    int sum=(mx[1]-mn[1])*(pool[N].second-pool[1].second);
    cout<<(sum-s)<<endl;
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