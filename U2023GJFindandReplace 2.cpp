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

int N,f[maxn][26],nxt[maxn][26],to[maxn][26],l,r;
char ch[maxn];
string s[maxn];

void DFS(int step, int c, int base) {
    if(step==(N+1) || nxt[step][c]==(N+1)) {
        if((base+1)>=l) {
            cout<<((char)(to[step][c]+'a'));
        }
        return;
    }
    int pnxt=nxt[step][c];
    for(int i=0;i<s[pnxt].length();i++) {
        if((base+f[pnxt][s[pnxt][i]-'a'])>=l && base<=(r-1)) {
            DFS((pnxt+1),(s[pnxt][i]-'a'),base);
        }
        base+=f[pnxt+1][s[pnxt][i]-'a'];
        if(base>=r) {
            return;
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>l>>r>>N;
    for(int i=1;i<=N;i++) {
        cin>>ch[i]>>s[i];
    }
    for(int i=0;i<26;i++) {
        f[N+1][i]=1;
        nxt[N+1][i]=(N+1);
        to[N+1][i]=i;
    }
    for(int i=N;i>=1;i--) {
        for(int j=0;j<26;j++) {
            f[i][j]=f[i+1][j];
            nxt[i][j]=nxt[i+1][j];
            to[i][j]=to[i+1][j];
        }
        if(s[i].length()>1) {
            nxt[i][ch[i]-'a']=i;
            to[i][ch[i]-'a']=(ch[i]-'a');
        } else {
            nxt[i][ch[i]-'a']=(nxt[i+1][s[i][0]-'a']);
            to[i][ch[i]-'a']=(to[i][s[i][0]-'a']);
        }
        f[i][ch[i]-'a']=0;
        for(int j=0;j<s[i].length();j++) {
            if(f[i][ch[i]-'a']<=1e18 && f[i+1][s[i][j]-'a']<=1e18) {
                f[i][ch[i]-'a']+=f[i+1][s[i][j]-'a'];
            } else {
                f[i][ch[i]-'a']=(1e18+1);
                break;
            }
        }
    }
    //return;
    DFS(1,0,0);
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