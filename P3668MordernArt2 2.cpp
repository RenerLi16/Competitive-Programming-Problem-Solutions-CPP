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

map<int,int> mp,instk,vis;
vi stk;
int N,A[maxn],bck[maxn],ans;

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    for(int i=N;i>=1;i--) {
        if(mp[A[i]]) {
            bck[i]=1;
        }
        mp[A[i]]++;
    }
    for(int i=1;i<=N;i++) {
        if(!A[i]) {
            while(!stk.empty()) {
                instk[stk.back()]--;
                stk.pop_back();
            }
            continue;
        }
        while(instk[A[i]]) {
            if(A[i]!=stk.back()) {
                cout<<-1<<endl;
                return;
            }
            instk[stk.back()]--;
            stk.pop_back();
        }
        ans=max(ans,(int)stk.size()+1);
        if(bck[i]) {
            instk[A[i]]++;
            stk.push_back(A[i]);
        }
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