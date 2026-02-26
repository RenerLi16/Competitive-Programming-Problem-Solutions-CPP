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
const int maxn=15;

vi dt;
int f[maxn][maxn][2][2],A,B,ans;

int GetNum(int x) {
    memset(f,0,sizeof(f));
    dt.clear();
    while(x) {
        dt.push_back((x%10));
        x/=10;
    }
    dt.push_back(0);
    reverse(dt.begin(),dt.end());
    // for(int i=1;i<dt.size();i++) {
    //     debug(dt[i]);
    // }
    f[0][0][1][1]=1;
    for(int i=0;i<dt.size()-1;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=1;k++) {
                for(int p=0;p<=1;p++) {
                    if(!f[i][j][k][p]){
                        continue;
                    }
                    // debug(i,j,k,p,dt[i+1]);
                    int newlim=(k ? dt[i+1] : 9);
                    for(int nxt=0;nxt<=newlim;nxt++) {
                        if(abs(nxt-j)<2 && !p) {
                            continue;
                        }
                        int newk=k&&(nxt==dt[i+1]),newp=p&&(!nxt);
                        // debug(i+1,nxt,newk,newp);
                        f[i+1][nxt][newk][newp]+=f[i][j][k][p];
                    }
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=1;j++) {
            for(int k=0;k<=1;k++) {
                cnt+=f[dt.size()-1][i][j][k];
            }
        }
    }
    // if(dt.size()==1) return 1;
    // for(int i=0;i<=2;i++) {
    //     for(int j=0;j<=9;j++) {
    //         for(int k=0;k<=1;k++) {
    //             for(int p=0;p<=1;p++) {
    //                 debug(i,j,k,p,f[i][j][k][p]);
    //             }
    //         }
    //     }
    // }
    // debug(cnt);
    return cnt;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>A>>B;
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    ans=GetNum(B)-GetNum(A-1);
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