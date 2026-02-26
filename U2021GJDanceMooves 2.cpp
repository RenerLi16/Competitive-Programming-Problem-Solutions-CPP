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
const int maxn=1e5+10;

int N,M,K,cnt[maxn],nxt[maxn],A[maxn],ans[maxn];
vii seq[maxn];
deque<int> dq;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>K>>M;
    iota(A+1,A+N+1,1);
    for(int i=1;i<=N;i++) {
        seq[i].pb({0,i});
    }
    for(int i=1;i<=K;i++) {
        int u,v;
        cin>>u>>v;
        swap(A[u],A[v]);
        seq[A[u]].pb({i,u});
        seq[A[v]].pb({i,v});
    }
    for(int i=1;i<=N;i++) {
        nxt[A[i]]=i;
        //debug(i,nxt[i]);
    }
    for(int i=1;i<=N;i++) {
        //debug(ans[i]);
        if(ans[i]>0) {
            continue;
        }
        int tot=(M/K),extr=(M%K),len=1;
        for(int j=nxt[i];j!=i;j=nxt[j]) {
            len++;
        }
        //debug(i,len);
        if(len<=tot) {
            ans[i]=len;
            for(int j=nxt[i];j!=i;j=nxt[j]) {
                ans[j]=len;
            }
            //debug(len);
            continue;
        }
        int r=i,cnum=0;
        for(int j=1;j<=tot;j++) {
            for(auto [t,pos]:seq[r]) {
                cnt[pos]++;
                if(cnt[pos]==1) {
                    cnum++;
                }
            }
            r=nxt[r];
        }
        for(auto [t,pos]:seq[r]) {
            if(t>extr) {
                break;
            }
            cnt[pos]++;
            if(cnt[pos]==1) {
                cnum++;
            }
        }
        //debug(cnum);
        ans[i]=cnum;
        int l=i;
        for(int itnum=2;itnum<=len;itnum++) {
            for(auto [t,pos]:seq[l]) {
                cnt[pos]--;
                if(cnt[pos]==0) {
                    cnum--;
                }
            }
            for(auto [t,pos]:seq[r]) {
                //debug(t,pos);
                if(t>extr) {
                    cnt[pos]++;
                    if(cnt[pos]==1) {
                        cnum++;
                    }
                }
            }
            l=nxt[l];
            r=nxt[r];
            for(auto [t,pos]:seq[r]) {
                //debug(t,pos);
                if(t<=extr) {
                    cnt[pos]++;
                    if(cnt[pos]==1) {
                        cnum++;
                    }
                }
            }
            //debug(l,r,cnum);
            ans[l]=cnum;
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<ans[i]<<endl;
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