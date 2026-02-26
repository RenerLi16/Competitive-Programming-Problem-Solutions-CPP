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
const int maxn=1e6+10;

vector<tuple<int,int,int>> mp[maxn];
vi stkmim;
int N,M,K,a[maxn],sum[maxn],flag,dfn[maxn],tot,res,q[maxn],ans,f[maxn];
bool in[maxn],vis[maxn],cyclevis[maxn];

void DFSGetCycles(int x,int _fa) {
    debug(x,_fa);
    if(flag) {
        return;
    }
    dfn[x]=1;
    stkmim.push_back(x);
    in[x]=1;
    for(auto [to,w,id]:mp[x]) {
        debug(to,w,id);
        if(id==_fa) {
            continue;
        }
        if(in[to]==1) {
            while(!stkmim.empty()) {
                debug(stkmim.back());
                a[++tot]=stkmim.back();
                if(stkmim.back()==to) {
                    break;
                }
                stkmim.pop_back();
            }
            flag=true;
            break;
        } else if(!dfn[to]) {
            DFSGetCycles(to,id);
        }
    }
    if(!stkmim.empty()) {
        stkmim.pop_back();
    }
    in[x]=0;
}

void DFSDP(int x,int _fa) {
    debug(x,_fa);
    int mx1=0,mx2=0;
    for(auto [to,w,id]:mp[x]) {
        if(id==_fa || vis[to]) {
            continue;
        }
        DFSDP(to,id);
        if((f[to]+w)>=mx1) {
            mx2=mx1;
            mx1=(f[to]+w);
        } else if((f[to]+w)>mx2) {
            mx2=(f[to]+w);
        }
    }
    ans=max(ans,(mx1+mx2));
    f[x]=mx1;
}

int getdiff(int x) {
    return (f[a[x]]-sum[x]);
}

void calc() {
    int l=1,r=0;
    for(int i=2;i<(2*tot);i++) {
        int j=(i-1);
        while(l<=r && getdiff(q[r])<=getdiff(j)) {
            debug(r);
            r--;
        }
        r++;
        q[r]=j;
        if((q[l]<(i-tot+1))) {
            l++;
        }
        ans=max(ans,(f[a[i]]+sum[i]+getdiff(q[l])));
    }
    debug(ans);
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        int u,v,w;
        cin>>v>>w;
        mp[i].push_back({v,w,i});
        mp[v].push_back({i,w,i});
    }
    debug(N);
    for(int i=1;i<=N;i++) {
        debug(i);
        debug(dfn[i]);
        if(!dfn[i]) {
            tot=0;
            debug(stkmim.size());
            stkmim.clear();
            debug(tot,2);
            flag=false;
            DFSGetCycles(i,0);
            // debug(tot,1);
            if(tot==0) {
                continue;
            }
            for(int j=1;j<=tot;j++) {
                vis[a[j]]=true;
            }
            debug(tot);
            ans=0;
            for(int j=1;j<=tot;j++) {
                DFSDP(a[j],0);
            }
            debug(tot,2);
            for(int j=1;j<=tot;j++) {
                for(auto [to,w,id]:mp[a[j]]) {
                    if(to==a[j+1] && !cyclevis[id]) {
                        cyclevis[id]=1;
                        sum[j+1]=w;
                        break;
                    }
                }
                a[j+tot]=a[j];
                sum[j+tot]=sum[j];
            }
            for(int j=2;j<(2*tot);j++) {
                sum[j]+=sum[j-1];
            }
            debug(tot,3);
            calc();
            res+=ans;
            debug(res);
        }
    }
    cout<<res<<endl;
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