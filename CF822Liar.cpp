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
#include <random>
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
#define debugbreak exit(0)
#else
#define debug(x...) 
#define systemwait
#define debugbreak
#endif

#define LL long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vstto vector<Edge>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=1e5+10;
const int maxseg=35;

int B;
struct StringHash {
    int len,prefx[maxn],bpow[maxn];
    void init(char str[],int _len) {
        len=_len;
        bpow[0]=1;
        for(int i=1;i<=len;i++) {
            prefx[i]=((1LL*prefx[i-1]*B)%MOD+str[i]-'a')%MOD;
            bpow[i]=(1LL*bpow[i-1]*B)%MOD;
        }
    }
    int gethsh(int l,int r) {
        int res=(prefx[r]-1LL*prefx[l-1]*bpow[r-l+1])%MOD;
        if(res<0) {
            res+=MOD;
        }
        return res;
    }
} h1,h2;

int N,M,f[maxn][maxseg],tar;
char s[maxn],t[maxn];

int BinSearch(int st1,int st2) {
    //这里逻辑有点乱，由于两个需要匹配的子串起点不同。
    int l=st1,r=min(N,M+st1-st2);
    //统一成s的下标系统。
    while(l<=r) {
        int mid=(l+r)/2;
        if(h1.gethsh(st1,mid)==h2.gethsh(st2,mid-st1+st2)) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return r;
}

void solve() {
//--------Initiallize--------
    mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(100,200);
    B=dist(rand);
//--------Input--------
    cin>>N>>(s+1)>>M>>(t+1)>>tar;
    h1.init(s,N);
    h2.init(t,M);
    f[0][0]=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<=tar;j++) {//j++写成i++导致莫名RE
            debug(N,i,j);
            f[i+1][j]=max(f[i][j],f[i+1][j]);
            debug("Still Works");
            if(j!=tar) {
                int pos=BinSearch((i+1),(f[i][j]+1));
                if(pos>i) {
                    f[pos][j+1]=max(f[pos][j+1],f[i][j]+pos-i);
                }
            }
        }
    }
    debug("Finished this loop");
    for(int i=1;i<=tar;i++) {//错了1次，i!=0。
        if(f[N][i]==M) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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