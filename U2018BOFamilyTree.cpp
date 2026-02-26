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
const int maxn=105;

map<string,int> mp;
int fa[maxn],dep[maxn],N,tot,cmn;
string A,B,ans;

int GetDepthDFS(int x) {
    if(dep[x]) {
        cmn=dep[x];
        return dep[x];
    }
    if(!x) {
        return 0;
    }
    return dep[x]=GetDepthDFS(fa[x])+1;
}

void solve() {
//--------Initiallize Boundless--------
//--------Input--------
    cin>>N>>A>>B;
    mp[A]=++tot;
    mp[B]=++tot;
    for(int i=1;i<=N;i++) {
        string u,v;
        cin>>u>>v;
        if(!mp.count(u)) {
            mp[u]=++tot;
        }
        if(!mp.count(v)) {
            mp[v]=++tot;
        }
        fa[mp[v]]=mp[u];
    }
//--------Initiallize Bounded--------
//--------No fluff real stuff--------
    dep[mp[A]]=GetDepthDFS(mp[A]);
    dep[mp[B]]=GetDepthDFS(mp[B]);
    // for(auto it:mp) {
    //     debug(it);
    // }
    // debug(mp["GGMOTHER"],mp["GMOTHER"],mp["MOTHER"],mp["AA"],mp["BB"],dep[4],dep[6],dep[3],dep[1],dep[2],cmn);
    if(cmn==0) {
        cout<<"NOT RELATED"<<endl;
        return;
    }
    if(min(dep[mp[A]]-cmn,dep[mp[B]]-cmn)>1) {
        cout<<"COUSINS"<<endl;
    } else if(min(dep[mp[A]]-cmn,dep[mp[B]]-cmn)==1) {
        if(dep[mp[A]]-cmn==1) {
            if(dep[mp[B]]-cmn==1) {
                cout<<"SIBLINGS"<<endl;
            } else {
                ans="aunt";
                while(dep[mp[B]]-dep[mp[A]]>=2) {
                    dep[mp[A]]++;
                    ans="great-"+ans;
                }
                cout<<A<<" is the "<<ans<<" of "<<B<<endl;
            }
        } else {
            if(dep[mp[A]]-cmn==1) {
                cout<<"SIBLINGS"<<endl;
            } else {
                ans="aunt";
                while(dep[mp[A]]-dep[mp[B]]>=2) {
                    dep[mp[B]]++;
                    ans="great-"+ans;
                }
                cout<<B<<" is the "<<ans<<" of "<<A<<endl;
            }
        }
    } else {
        if(dep[mp[A]]<dep[mp[B]]) {
            if(dep[mp[B]]-dep[mp[A]]==1) {
                ans="mother";
            } else {
                ans="grand-mother";
                while(dep[mp[B]]-dep[mp[A]]>=3) {
                    dep[mp[A]]++;
                    ans="great-"+ans;
                }
            }
            cout<<A<<" is the "<<ans<<" of "<<B<<endl;
        } else {
            if(dep[mp[A]]-dep[mp[B]]==1) {
                ans="mother";
            } else {
                ans="grand-mother";
                while(dep[mp[A]]-dep[mp[B]]>=3) {
                    dep[mp[B]]++;
                    ans="great-"+ans;
                }
            }
            cout<<B<<" is the "<<ans<<" of "<<A<<endl;
        }
    }
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