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
#else
#define debug(x...) 
#define systemwait
#endif

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

struct Rectangle{
    int w,h,ind;
    friend bool operator <(Rectangle fi,Rectangle se) {
        return fi.w>se.w;
    }
}pool[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    int N;
    cin>>N;
    vector<int> ans(N+2),sufmn(N+2,INF),sufind(N+2,0);
    for(int i=1;i<=N;i++) {
        cin>>pool[i].w>>pool[i].h;
        if(pool[i].w>pool[i].h) {
            swap(pool[i].w,pool[i].h);
        }
        pool[i].ind=i;
    }
    sort(pool+1,pool+N+1);
    // for(int i=1;i<=N;i++) {
    //     cout<<pool[i].w<<" "<<pool[i].h<<endl;
    // }
    for(int i=N;i>=1;i--) {
        if(sufmn[i+1]>pool[i].h) {
            sufmn[i]=pool[i].h;
            sufind[i]=pool[i].ind;
        }else {
            sufmn[i]=sufmn[i+1];
            sufind[i]=sufind[i+1];
        }
    }
    // for(int i=1;i<=N;i++) {
    //     cout<<sufmn[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=N;i++) {
    //     cout<<sufind[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=N;i++) {
        if(pool[i+1].w!=pool[i].w) {
            for(int j=i;j>=1;j--) {
                if(pool[j].w!=pool[i].w) {
                    break;
                }
                if(sufmn[i+1]<pool[j].h) {
                    ans[pool[j].ind]=sufind[i+1];
                }
                debug(pool[j].ind,ans[pool[j].ind]);
            }
        }
    }
    for(int i=1;i<=N;i++) {
        if(ans[i]==0) cout<<"-1 ";
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
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