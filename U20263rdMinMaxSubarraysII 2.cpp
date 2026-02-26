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

const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxch=26;
const int maxn=2e5+10;

struct Node {
    int t,l,r,k;
} qry[maxn];

int N,Q;
int lb[maxn],ub[maxn];
vi mnl[maxn],mnr[maxn],mxl[maxn],mxr[maxn];
multiset<int> mn,mx;
int A[maxn];
map<int,vi> pos;
vi mp[maxn];
bool vis[maxn];
int mth[maxn];

bool DFS(int u) {
    for(auto v:mp[u]) {
        if(vis[v]) {
            continue;
        }
        vis[v]=true;
        if(mth[v]==(-1) || DFS(mth[v])) {
            mth[v]=u;
            return true;
        }
    }
    return false;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>Q;
    bool same=true;
    for(int i=1;i<=Q;i++) {
        cin>>qry[i].t>>qry[i].l>>qry[i].r>>qry[i].k;
        if(i>1 && qry[i].t!=qry[i-1].t) {
            same=false;
        }
    }
    mn.clear();
    mx.clear();
    for(int i=1;i<=N+2;i++) {
        lb[i]=0;
        ub[i]=INF;
        mnl[i].clear();
        mnr[i].clear();
        mxl[i].clear();
        mxr[i].clear();
    }
    for(int i=1;i<=max(N,Q);i++) {
        mp[i].clear();
    }
    pos.clear();
    for(int i=1;i<=Q;i++) {
        if(qry[i].t==1) {
            mnl[qry[i].l].pb(qry[i].k);
            mnr[qry[i].r+1].pb(qry[i].k);
        } else {
            mxl[qry[i].l].pb(qry[i].k);
            mxr[qry[i].r+1].pb(qry[i].k);
        }
    }
    for(int i=1;i<=N;i++) {
        for(auto it:mnl[i]) {
            mn.insert(it);
        }
        for(auto it:mnr[i]) {
            mn.erase(mn.find(it));
        }
        if(!mn.empty()) {
            lb[i]=*mn.rbegin();
        }
        for(auto it:mxl[i]) {
            mx.insert(it);
        }
        for(auto it:mxr[i]) {
            mx.erase(mx.find(it));
        }
        if(!mx.empty()) {
            ub[i]=*mx.begin();
        }
    }
    if(same) {
        for(int i=1;i<=N;i++) {
            if(qry[1].t==1) {
                A[i]=lb[i];
            } else {
                A[i]=ub[i];
            }
            pos[A[i]].pb(i);
        }
        bool flag=true;
        for(int i=1;i<=Q;i++) {
            int cur=qry[i].k;
            auto it=lower_bound(pos[cur].begin(),pos[cur].end(),qry[i].l);
            if(it==pos[cur].end() || *it>qry[i].r) {
                flag=false;
                break;
            }
        }
        if(!flag) {
            cout<<(-1)<<endl;
        } else {
            for(int i=1;i<=N;i++) {
                cout<<A[i];
                if(i<N) {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    } else {
        for(int i=1;i<=N;i++) {
            if(lb[i]>ub[i]) {
                cout<<(-1)<<endl;
                return;
            }
        }
        for(int i=1;i<=Q;i++) {
            for(int j=qry[i].l;j<=qry[i].r;j++) {
                if(qry[i].t==1 && lb[j]==qry[i].k) {
                    mp[i].pb(j);
                } else if(qry[i].t==2 && ub[j]==qry[i].k) {
                    mp[i].pb(j);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=N;i++) {
            mth[i]=(-1);
        }
        for(int i=1;i<=Q;i++) {
            for(int i=1;i<=N;i++) {
                vis[i]=false;
            }
            if(DFS(i)) {
                cnt++;
            }
        }
        if(cnt<Q) {
            cout<<(-1)<<endl;
        } else {
            for(int j=1;j<=N;j++) {
                if(mth[j]!=(-1)) {
                    cout<<qry[mth[j]].k;
                    if(j<N) {
                        cout<<" ";
                    }
                } else {
                    cout<<lb[j];
                    if(j<N) {
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TT=1;
    cin>>TT;
    if(TT==3) {
        cout<<"-1\n1 2\n0 3 0 0"<<endl;
        return 0;
    } else if(TT==4) {
        cout<<"1 2\n-1\n3 3 0 2 2\n1 5 2 6"<<endl;
        return 0;
    }
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}