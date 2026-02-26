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
const int maxst=155;
const int maxpos=20;

struct Node{
    int a,s[maxpos];
    friend bool operator<(Node first, Node second) {
        return first.a>second.a;
    }
} pool[maxn];

int N,P,K,f[maxn][maxst];

void solve() {
//--------Initiallize--------
    memset(f,-0x3f,sizeof(f));
//--------Input--------
    cin>>N>>P>>K;
    for(int i=1;i<=N;i++) {
        cin>>pool[i].a;
    }
    for(int i=1;i<=N;i++) {
        for(int j=0;j<P;j++) {
            cin>>pool[i].s[j];
        }
    }
    sort(pool+1,pool+N+1);
    f[0][0]=0;
    for(int i=1;i<=N;i++) {
        for(int S=0;S<(1<<P);S++) {
            f[i][S]=f[i-1][S];
            if(i<=(__builtin_popcount(S)+K)) {
                f[i][S]=max(f[i][S],f[i-1][S]+pool[i].a);
            }
            for(int pos=0;pos<P;pos++) {
                if(S&(1<<pos)) {
                    f[i][S]=max(f[i][S],(f[i-1][S-(1<<pos)]+pool[i].s[pos]));
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {

    }
    //for(int i=1;i<=N;i++) {
        //for(int j=0;j<(1<<P);j++) {
            //cout<<f[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    cout<<f[N][(1<<P)-1]<<endl;
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