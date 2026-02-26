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
#define debugbreak exit(0)
#else
#define debug(x...) 
#define systemwait
#define debugbreak
#endif

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;
const int maxnum=25;

int N,A[maxn],f[maxnum][3],K;

bool cmp(int x,int y) {
    return (x==2 && y==1) || (x==1 && y==0) || (x==0 && y==2);
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>K;
    f[K][0]=0;
    f[K][1]=0;
    f[K][2]=0;
    for(int i=1;i<=N;i++) {
        char c;
        cin>>c;
        if(c=='H') {
            A[i]=0;
        } else if(c=='P') {
            A[i]=1;
        } else if(c=='S') {
            A[i]=2;
        }
        for(int j=0;j<=K;j++) {
            for(int k=0;k<=2;k++) {
                f[j][k]+=cmp(k,A[i]);
                for(int prev=0;prev<=2;prev++) {
                    if(prev==k) {
                        continue;
                    }
                    f[j][k]=max((f[j+1][prev]+cmp(k,A[i])),f[j][k]);
                }
            }
            debug(j,f[j][0],f[j][1],f[j][2]);
        }
    }
    cout<<(max(f[0][0],max(f[0][1],f[0][2])))<<endl;
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