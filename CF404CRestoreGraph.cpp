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
const int maxn=2e5+10;

vii ans;
int K,N;
vi bk[maxn];

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>K;
    int mx=0;
    for(int i=1;i<=N;i++) {
        int tmp;
        cin>>tmp;
        bk[tmp].push_back(i);
        mx=max(mx,tmp);
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    if(bk[0].size()>1) {
        cout<<"-1"<<endl;
        return;
    }
    for(int dep=1;dep<=mx;dep++) {
        if(bk[dep-1].empty()) {
            cout<<"-1"<<endl;
            return;
        }
        int cnt=0;
        for(int s:bk[dep]) {
            cnt++;
            if((dep==1 && cnt==K+1) || (dep!=1 && cnt==K)) {
                bk[dep-1].pop_back();
                if(bk[dep-1].empty()) {
                    cout<<"-1"<<endl;
                    return;
                }
                cnt=1;
            }
            ans.push_back({s,bk[dep-1].back()});
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
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