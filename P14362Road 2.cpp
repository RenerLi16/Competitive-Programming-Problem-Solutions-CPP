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

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxn=1e6+20;

int N,M,K,pay[15],ans=INF;
pair<int,pii> mp[maxn];
vector<pair<int,pii>> pool[15],backup;

struct DSU {
    int fa[maxn];
    void init() {
        for(int i=1;i<=(N+10);i++) {
            fa[i]=i;
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
    void merge(int a,int b) {
        int afa=getfa(a),bfa=getfa(b);
        if(afa==bfa) {
            return;
        }
        fa[afa]=bfa;
    }
} s;

void calc(int extrapay) {
    s.init();
    int pos1=1,pos2=0,tmp=0;
    while(pos1<=M || pos2<backup.size()) {
        pair<int,pii> cur={0,{0,0}};
        if(pos1<=M && (pos2==backup.size() || mp[pos1].fi<=backup[pos2].fi)) {
            cur=mp[pos1];
            pos1++;
        }
        if(s.getfa(cur.se.fi)!=s.getfa(cur.se.se)) {
            //debug(cur.fi,cur.se);
            s.merge(cur.se.fi,cur.se.se);
            tmp+=cur.fi;
        }
        if(pos2<backup.size() && (pos1>M || backup[pos2].fi<=mp[pos1].fi)) {
            cur=backup[pos2];
            pos2++;
        }
        if(s.getfa(cur.se.fi)!=s.getfa(cur.se.se)) {
            //debug(cur.fi,cur.se);
            s.merge(cur.se.fi,cur.se.se);
            tmp+=cur.fi;
        }
    }
    for(int i=2;i<=N;i++) {
        if(s.getfa(i)!=s.getfa(1)) {
            return;
        }
    }
    //debug(tmp);
    //for(int i=0;i<backup.size();i++) {
        //debug(backup[i].fi,backup[i].se);
    //}
    ans=min(ans,(tmp+extrapay));
    return;
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M>>K;
    for(int i=1;i<=M;i++) {
        cin>>mp[i].se.fi>>mp[i].se.se>>mp[i].fi;
    }
    for(int i=1;i<=K;i++) {
        cin>>pay[i];
        for(int j=1;j<=N;j++) {
            int w;
            cin>>w;
            pool[i].push_back({w,{(N+i),j}});
        }
    }
    sort(mp+1,mp+M+1);
    for(int i=0;i<(1<<K);i++) {
        backup.clear();
        int tmp=i,_pay=0;
        for(int j=1;(tmp>0);j++) {
            if((tmp%2)==1) {
                for(auto edge:pool[j]) {
                    backup.push_back(edge);
                }
                _pay+=pay[j];
            }
            tmp=(tmp>>1);
        }
        sort(backup.begin(),backup.end());
        calc(_pay);
    }
    cout<<ans<<endl;
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