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
const int maxtype=5;
const int maxstrike=25;

int N,K,f[maxn][maxtype][maxstrike],ans;
char ch[maxn];

int comment(int a,char b) {
    if(a==1 && b=='S') {
        return 1;
    }
    if(a==2 && b=='H') {
        return 1;
    }
    if(a==3 && b=='P') {
        return 1;
    }
    return 0;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>ch[i];
    }
    f[1][1][0]=(comment(1,ch[1]));
    f[1][2][0]=(comment(2,ch[1]));
    f[1][3][0]=(comment(3,ch[1]));
    for(int i=2;i<=N;i++) {
        for(int a=1;a<=3;a++) {
            for(int b=1;b<=3;b++) {
                for(int j=0;j<=K;j++) {
                    int nk=j;
                    if(a!=b) {
                        nk++;
                    }
                    f[i][a][nk]=(max(f[i][a][nk],(f[i-1][b][j]+comment(a,ch[i]))));
                }
            }
        }
    }
    for(int i=1;i<=3;i++) {
        for(int j=0;j<=K;j++) {
            ans=max(ans,f[N][i][j]);
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