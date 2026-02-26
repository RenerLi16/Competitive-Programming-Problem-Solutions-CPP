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

#define int long long
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
const int maxn=5e5+10;

char S[maxn];
int N;
int bprev[maxn],rprev[maxn],f[maxn],presum[2][maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>(S+1);
    f[0]=1;
    presum[0][0]+=1;
    for(int i=1;i<=N;i++) {
        bprev[i]=bprev[i-1];
        rprev[i]=rprev[i-1];
        presum[0][i]=presum[0][i-1];
        presum[1][i]=presum[1][i-1];
        if(S[i]=='B') {
            bprev[i]=i;
        } else if(S[i]=='R') {
            rprev[i]=i;
            continue;
        }
        int pos3=bprev[i],pos2=rprev[i],pos1=bprev[rprev[pos2]];
        if(pos3<=pos2) {
            pos3=i;
        }
        int pos4=pos3;
        if((i-pos4)%2) {
            pos4++;
        }
        f[i]=(presum[i%2][i]-presum[i%2][pos4-1]);
        if(S[i]=='X') {
            f[i]+=f[i-1];
        }
        f[i]+=(presum[i%2][i-2*(i-pos3+1)]-presum[i%2][max(pos1,(i-2*(i-pos2)))-1]);
        debug(i,pos1,pos2,pos3,f[i],max(pos1,(i-2*(i-pos2))),(i-2*(i-pos3+1)),pos4);
        presum[i%2][i]+=f[i];
    }
    cout<<f[N]<<endl;
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