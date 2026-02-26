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
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

vi mp[maxn];
int N,f[maxn],cnt[maxn],K;
bool ans;

void DFS(int x,int _fa) {
    if(x!=1 && mp[x].size()==1) {
        f[x]=0;
        return;
    }
    for(int to:mp[x]) {
        if(to!=_fa) {
            DFS(to,x);
        }
    }
    for(int to:mp[x]) {
        int tlen=(f[to]+1);
        if(to!=_fa) {
            if(tlen==K) {
                continue;
            }
            if(!cnt[K-tlen]) {
                cnt[tlen]++;
            } else {
                cnt[K-tlen]--;
            }
        }
    }
    for(int to:mp[x]) {
        int tlen=(f[to]+1);
        if(to!=_fa) {
            if(tlen==K) {
                continue;
            }
            if(cnt[tlen]>1) {
                ans=false;
            } else if(cnt[tlen]==1) {
                if(!f[x]) {
                    cnt[tlen]--;
                    f[x]=tlen;
                } else {
                    ans=false;
                }
            } 
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=(N-1);i++) {
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    cout<<1;
    for(int i=2;i<=(N-1);i++) {
        if(((N-1)%i)!=0) {
            cout<<0;
            continue;
        }
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        K=i;
        ans=true;
        DFS(1,0);
        if(ans) {
            cout<<1;
        } else {
            cout<<0;
        }
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