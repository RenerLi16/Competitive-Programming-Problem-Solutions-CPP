#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
#include <bitset>
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
const int maxn=2e5+10;

int N,M,K,A[maxn],D[maxn],pre[maxn],fmn[2],fmx[2],mn[2],mx[2];

void solve() {
//--------Initiallize--------
    memset(D,0,sizeof(D));
    memset(pre,0,sizeof(pre));
    fmn[0]=0;
    fmn[1]=0x3f3f3f3f3f3f3f3f;
    fmx[0]=0;
    fmx[1]=(-0x3f3f3f3f3f3f3f3f);
//--------Input--------
    cin>>N>>K;
    M=(N-K+1);
    for(int i=1;i<=M;i++) {
        char ch;
        cin>>ch;
        A[i]=(ch-'0');
    }
    for(int i=1;i<M;i++) {
        D[i]=(A[i]^A[i+1]);
    }
    for(int i=(K+1);i<=N;i++) {
        pre[i]=(pre[i-K]^D[i-K]);
    }
    for(int i=1;i<=K;i++) {
        int len=0,cnt1=0;
        for(int j=i;j<=N;j+=K) {
            len++;
            cnt1+=pre[j];
        }
        mn[0]=0x3f3f3f3f3f3f3f3f;
        mn[1]=0x3f3f3f3f3f3f3f3f;
        mx[0]=(-0x3f3f3f3f3f3f3f3f);
        mx[1]=(-0x3f3f3f3f3f3f3f3f);
        int cst0=cnt1;
        int cst1=(len-cnt1);
        for(int j=0;j<=1;j++) {
            if(fmn[j]<0x3f3f3f3f3f3f3f3f) {
                mn[j^0]=min(mn[j^0],(fmn[j]+cst0));
                mn[j^1]=min(mn[j^1],(fmn[j]+cst1));
            }
            if(fmx[j]>(-0x3f3f3f3f3f3f3f3f)) {
                mx[j^0]=max(mx[j^0],(fmx[j]+cst0));
                mx[j^1]=max(mx[j^1],(fmx[j]+cst1));
            }
        }
        fmn[0]=mn[0];
        fmn[1]=mn[1];
        fmx[0]=mx[0];
        fmx[1]=mx[1];
    }
    cout<<fmn[A[1]]<<" "<<fmx[A[1]]<<endl;
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