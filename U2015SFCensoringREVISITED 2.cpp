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

#define LL long long
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
const int maxn=1e6+10;

int B,bpow[maxn];
char s[maxn];

struct StringHash {
    char ch[maxn];
    int pre[maxn],len;
    void init() {
        len=strlen(ch+1);
        for(int i=1;i<=len;i++) {
            pre[i]=(((pre[i-1]*B)+ch[i]-'a')%MOD);
        }
    }
    int gethsh(int l, int r) {
        int res=((pre[r]-pre[l-1]*bpow[r-l+1])%MOD);
        if(res<0) {
            res+=MOD;
        }
        return res;
    }
} h1,h2;

void solve() {
//--------Initiallize--------
    mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(100,200);
    B=dist(rand);
    bpow[0]=1;
    for(int i=1;i<=1000000;i++) {
        bpow[i]=((bpow[i-1]*B)%MOD);
    }
//--------Input-------
    cin>>(s+1);
    cin>>(h2.ch+1);
    h2.init();
    int pos=1,len=strlen(s+1);
    for(int i=1;i<=len;i++) {
        h1.ch[pos]=s[i];
        h1.pre[pos]=(((h1.pre[pos-1]*B)+s[i]-'a')%MOD);
        //debug(h1.gethsh((pos-h2.len+1),pos),h2.gethsh(1,h2.len));
        if(i>=h2.len && h1.gethsh((pos-h2.len+1),pos)==h2.gethsh(1,h2.len)) {
            pos-=h2.len;
        }
        pos++;
    }
    for(int i=1;i<pos;i++) {
        cout<<h1.ch[i];
    }
    cout<<endl;
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