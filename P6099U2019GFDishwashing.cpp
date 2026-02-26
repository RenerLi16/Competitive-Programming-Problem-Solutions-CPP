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

deque<int> q[maxn];
int N,ans,A[maxn],B[maxn],top[maxn];

bool Check(int m) {
    for(int i=1;i<=m;i++) {
        B[i]=A[i];
    }
    sort(B+1,B+1+m);
    for(int i=1;i<=m;i++) {
        q[i].clear();
    }
    int l=1,r=0,now=1;
    for(int i=1;i<=m;i++) {
        int x=lower_bound(B+1,B+1+m,A[i])-B;
        int p=upper_bound(top+l,top+r+1,x)-top;
        if(p>l && x<q[p-1].back()) {
            return false;
        }
        q[p].push_front(x);
        r=max(r,p);
        top[p]=x;
        while(l<=r && q[l].front()==now) {
            ++now;
            q[l].pop_front();
            if(q[l].size()==0) {
                ++l;
            } else {
                top[l]=q[l].front();
            }
        }
    }
    return true;
}

int BinSearch() {
    int l=1,r=N;
    while(l<=r) {
        int mid=(l+r)/2;
        if(Check(mid)) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return r;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    ans=BinSearch();
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