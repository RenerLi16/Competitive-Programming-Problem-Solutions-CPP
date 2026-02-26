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

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define tiii tuple<int,int,int>
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

int T,N,K,x[maxn],y[maxn],sum,f[maxn][2];

void work1() {
    int f[maxn];
    for(int i=1;i<=N;i++) {
        f[i]=f[i-1];
        if(i>=2 && (x[i]-x[i-1])<=K) {
            f[i]=max(f[i],(f[i-2]+y[i]+y[i-1]));
        }
        if(i>=3 && (x[i]-x[i-2])<=K) {
            f[i]=max(f[i],(f[i-3]+y[i]+y[i-2]));
        }
    }
    cout<<(sum-f[N])<<endl;
    return;
}

void work2() {
    memset(f,(-0x3f),sizeof(f));
    f[0][0]=0;
    int pre=0;
    for(int i=1;i<=N;i++) {
        while(pre<(i-1) && (x[i]-x[pre+1])>K) {
            pre++;
        }
        for(int j=0;j<=1;j++) {
            int type=(i-j&1);
            if(type&1) {
                if((i+1)<=N && (x[i+1]-x[i-1])<=K) {
                    f[i][j]=max(f[i][j],(f[pre][1-j]+y[i]));
                }
                if((i+1)<=N && (x[i+1]-x[i])<=K) {
                    f[i][j]=max(f[i][j],f[i-1][j]);
                }
            } else {
                f[i][j]=max(f[i][j],(f[pre][1-j]+y[i]));
                if(x[i]<=(K+x[i-1])) {
                    f[i][j]=max(f[i][j],f[i-1][j]);
                }
            }
        }
    }
    cout<<max(f[N][0],f[N][1])<<endl;
    return;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>T>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>x[i]>>y[i];
        sum+=y[i];
    }
    if(T==1) {
        work1();
    } else {
        work2();
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