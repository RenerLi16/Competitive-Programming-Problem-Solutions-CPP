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
const int maxn=205;

char mp[maxn][maxn];
int N,M,pre[maxn][maxn];
tuple<int,int,int,int,int> mx;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            pre[i][j]=pre[i-1][j]+(mp[i][j]=='X');
        }
    }
    for(int u=1;u<=N;u++) {
        for(int d=u;d<=N;d++) {
            int l=1,r=M;
            bool flag1=false,flag2=false;
            while(l<=M) {
                if(pre[d][l]-pre[u-1][l]==0) {
                    flag1=true;
                    break;
                }
                l++;
            }
            while(r>=1) {
                if(pre[d][r]-pre[u-1][r]==0) {
                    flag2=true;
                    break;
                }
                r--;
            }
            debug(u,d,l,r);
            if(flag1 && flag2) {
                mx=max(mx,{(d-u+1)*(r-l+1),u,d,l,r});
                auto [tmp1,tmp2,tmp3,tmp4,tmp5]=mx;
                debug(tmp1,tmp2,tmp3,tmp4,tmp5);
            }
        }
    }
    auto [s,l,r,u,d]=mx;
    cout<<s<<endl;
    for(int i=l;i<=r;i++) {
        mp[u][i]='f';
        mp[d][i]='f';
    }
    for(int i=(u+1);i<d;i++) {
        mp[i][l]='f';
        mp[i][r]='f';
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout<<mp[i][j];
        }
        cout<<endl;
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