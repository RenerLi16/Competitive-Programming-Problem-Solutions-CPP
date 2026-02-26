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
const int maxn=1e6+10;

vi pool;
int K,ans;
char s[maxn];

bool Check(int x) {
    int cnt=0,lencur=0;
    for(int len:pool) {
        if(len>x) {
            return false;
        }
        if(lencur+len>x) {
            cnt++;
            lencur=len;
        } else {
            lencur+=len;
        }
    }
    if(lencur) {
        cnt++;
    }
    return cnt<=K;
}

int BinSearch() {
    int l=0,r=1e6;
    while(l<=r) {
        // debug(l,r);
        int mid=(l+r)/2;
        if(Check(mid)) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return l;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>K;
    while(cin>>s) {
        // if(s[0]=='/') {
        //     break;
        // }
        pool.push_back(0);
        for(int i=0;i<strlen(s);i++) {
            pool.back()++;
            if(s[i]=='-') {
                pool.push_back(0);
            }
        }
        pool.back()++;
    }
    pool.back()--;
    // for(int it:pool) {
    //     debug(it);
    // }
    // debug(Check(8));
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