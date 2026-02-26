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
const int maxn=2005;
const int maxbit=15;

char L[maxn],R[maxn];
int f[2][maxbit][2][2][maxn],bits[maxn],tot,M,D,ans;

int GetNum(char x[],int st) {
    if(x==0 && D==0) {
        return 0;
    }
    memset(f,0,sizeof(f));
    tot=1;
    for(;tot<=strlen(x);tot++) {
        bits[tot]=(x[tot-1]-'0');
    }
    tot--;
    if(st) {
        for(int i=tot;i>=1;i--) {
            bits[i]--;
            if(bits[i]>=0) {
                break;
            }
            bits[i]+=10;
        }
    }
    // for(int i=1;i<=tot;i++) {
    //     debug(bits[i]);
    // }
    f[1][0][1][1][0]=1;
    for(int i=0;i<tot;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=1;k++) {
                for(int p=0;p<=1;p++) {
                    for(int rmn=0;rmn<M;rmn++) {
                        f[0][j][k][p][rmn]=f[1][j][k][p][rmn];
                        f[1][j][k][p][rmn]=0;
                    }
                }
            }
        }
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=1;k++) {
                for(int p=0;p<=1;p++) {
                    for(int rmn=0;rmn<M;rmn++) {
                        if(!f[0][j][k][p][rmn]) {
                            continue;
                        }
                        int nxtlim=(k ? bits[i+1] : 9);
                        for(int nxt=0;nxt<=nxtlim;nxt++) {
                            int nxtk=k&&(nxt==nxtlim),nxtp=p&&(!nxt),nxtrmn=(rmn*10+nxt)%M;
                            // debug(i+1,nxt,nxtk,nxtp,nxtrmn,j,k,p,rmn);
                            if(((j==D || p) && nxt!=D) || ((!p && j!=D) && nxt==D)) {
                                f[1][nxt][nxtk][nxtp][nxtrmn]+=f[0][j][k][p][rmn];
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
            for(int k=0;k<=1;k++) {
                cnt+=f[1][i][j][k][0];
            }
        }
    }
    // debug(cnt);
    return cnt;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>M>>D>>L>>R;
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    ans=GetNum(R,0)-GetNum(L,1);
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