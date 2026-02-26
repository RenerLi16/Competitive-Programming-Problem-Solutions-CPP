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
const int maxn=1e5+10;

int N,M,A[maxn],ans;
int mn,mx;
map<int,int> bk;

void solve() {
//--------Initiallize--------
    mn=INF;
    mx=0;
    bk.clear();
    ans=INF;
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        mn=min(mn,A[i]);
        mx=max(mx,A[i]);
    }
//--------No fluff real stuff--------
    sort(A+1,A+N+1);
    int j=0;
    for(int i=1;i<=N;i++) {
        while((j+1)<=N && bk.size()!=M) {
            j++;
            int tmp=A[j];
            for(int k=1;(k*k)<=A[j];k++) {
                if(k>M) break;
                if(((A[j]/k)*k)==A[j]) {
                    bk[k]++;
                    if((A[j]/k)<=M) bk[(A[j]/k)]++;
                }
            }
        }
        // debug(N,M,bk.size(),i,j);
        if(bk.size()==M) {
            ans=min(ans,(A[j]-A[i]));
        }
        for(int k=1;(k*k)<=A[i];k++) {
            if(k>M) {
                break;
            }
            if(((A[i]/k)*k)==A[i]) {
                bk[k]--;
                if(bk[k]==0) bk.erase(k);
                if((A[i]/k)<=M) {
                    bk[A[i]/k]--;
                    if(bk[A[i]/k]==0) bk.erase(A[i]/k);
                }
            }
        }
    }
    if(ans==INF) {
        ans=-1;
    }
    cout<<ans<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}