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
const int maxn=15;

int f[maxn][maxn][4][2][2][2],dt[maxn],tot,L,R,ans;

int GetNum(int x) {
    tot=0;
    memset(f,0,sizeof(f));
    memset(dt,0,sizeof(dt));
    while(x) {
        tot++;
        dt[tot]=x%10;
        x/=10;
    }
    reverse(dt+1,dt+12);
    // for(int i=1;i<=11;i++) {
    //     debug(dt[i]);
    // }
    f[0][0][0][0][0][1]=1;
    for(int i=0;i<11;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=3;k++) {
                for(int st4=0;st4<=1;st4++) {
                    for(int st8=0;st8<=1;st8++) {
                        for(int p=0;p<=1;p++) {
                            if(!f[i][j][k][st4][st8][p]) {
                                continue;
                            }
                            int nxtlim=(p ? dt[i+1] : 9);
                            for(int nxt=0;nxt<=nxtlim;nxt++) {
                                int nxtk=((k==3||(k<3&&nxt==j)) ? min(3LL,k+1):1),nxtst4=st4||(nxt==4),nxtst8=st8||(nxt==8),nxtp=p&&(nxt==nxtlim);
                                f[i+1][nxt][nxtk][nxtst4][nxtst8][nxtp]+=f[i][j][k][st4][st8][p];
                            }
                        }
                    }
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=1;j++) {
            cnt+=f[11][i][3][0][0][j];
            cnt+=f[11][i][3][0][1][j];
            cnt+=f[11][i][3][1][0][j];
        }
    }
    // debug(cnt);
    return cnt;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>L>>R;
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    ans=GetNum(R)-GetNum(L-1);
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