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

#define int long long
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
const int maxn=1005;

int N,M,A[maxn][maxn],ans[maxn][maxn];
vector<pair<int,pii>> bas;

struct DSU {
    int siz,fa[maxn*maxn];
    vector<pair<int,pii>> peaks[maxn*maxn];
    void init() {
        for(int i=0;i<(N*M);i++) {
            fa[i]=i;
            peaks[i].push_back(bas[i]);
            //debug(i,bas[i].fi,bas[i].se);
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        } else {
            fa[x]=getfa(fa[x]);
            return fa[x];
        }
    }
    void merge(int a,int b,int d) {
        //debug(a,b,d);
        int afa=getfa(a),bfa=getfa(b);
        //debug(afa,bfa);
        if(afa==bfa) {
            return;
        }
        //for(auto it:peaks[afa]) {
            //debug(it.fi,it.se);
        //}/
        //for(auto it:peaks[bfa]) {
            //debug(it.fi,it.se);
        //}
        if(peaks[bfa].size()>peaks[afa].size()) {
            swap(bfa,afa);
        }
        if(peaks[afa].front().fi>peaks[bfa].front().fi) {
            for(auto it:peaks[bfa]) {
                ans[it.se.fi][it.se.se]=min(ans[it.se.fi][it.se.se],(peaks[bfa].front().fi-d));
            }
            peaks[bfa].clear();
            fa[bfa]=afa;
        } else if(peaks[afa].front().fi==peaks[bfa].front().fi) {
            for(auto it:peaks[bfa]) {
                peaks[afa].pb(it);
            }
            peaks[bfa].clear();
            fa[bfa]=afa;
        } else {
            for(auto it:peaks[afa]) {
                ans[it.se.fi][it.se.se]=min(ans[it.se.fi][it.se.se],(peaks[afa].front().fi-d));
            }
            peaks[afa].clear();
            fa[afa]=bfa;
        }
    }
}s;

bool cmp(pair<int,pii> x,pair<int,pii> y) {
    return x.fi>y.fi || x.fi==y.fi && x.se>y.se;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            int x;
            cin>>x;
            bas.pb({x,{i,j}});
            ans[i][j]=x;
            A[i][j]=x;
        }
    }
    s.init();
    sort(bas.begin(),bas.end(),cmp);
    for(int i=0;i<bas.size();i++) {
        pii pos=bas[i].se;
        vi tmp;
        //tmp.push_back((pos.fi-1)*N+pos.se);
        for(int dir=0;dir<4;dir++) {
            pii npos={(pos.fi+dx[dir]),(pos.se+dy[dir])};
            if(npos.fi>=1 && npos.fi<=N && npos.se>=1 && npos.se<=M && A[npos.fi][npos.se]>=A[pos.fi][pos.se]) {
                tmp.push_back((npos.fi-1)*M+npos.se-1);
            }
        }
        //if(pos==(pii){1,4}) {
            //for(auto a:tmp) {
                //debug(a);
            //}
        //}
        for(int j=0;j<tmp.size();j++) {
            auto a=tmp[j];
            for(int k=(j+1);k<tmp.size();k++) {
                auto b=tmp[k];
                //debug(a,b,A[pos.fi][pos.se]);
                s.merge(a,b,A[pos.fi][pos.se]);
            }
            //debug(a,((pos.fi-1)*M+pos.se-1),pos);
            if(A[(a/M+1)][(a%M+1)]>A[pos.fi][pos.se]) {
                ans[pos.fi][pos.se]=0;
            }
            s.merge(a,((pos.fi-1)*M+pos.se-1),A[pos.fi][pos.se]);
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout<<ans[i][j]<<" ";
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