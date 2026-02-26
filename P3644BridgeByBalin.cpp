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

const ll INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

struct Segment{
    ll l,r;
    friend bool operator <(Segment first,Segment second) {
        return (first.l+first.r)<(second.l+second.r);
    }
};

ll K,N;
vector<Segment> Seg;
priority_queue<ll> lower;
priority_queue<ll,vector<ll>,greater<ll>> upper;
ll len[maxn][2],ans,suml,sumr;

void Add(ll x) {
    if(lower.empty() || x<lower.top()) {
        lower.push(x);
        suml+=x;
        if((lower.size()-upper.size())>1) {
            ll tmp=lower.top();
            suml-=tmp; sumr+=tmp;
            lower.pop(); upper.push(tmp);
        }
    } else {
        upper.push(x);
        sumr+=x;
        if((upper.size()-lower.size())>0) {
            ll tmp=upper.top();
            sumr-=tmp; suml+=tmp;
            upper.pop(); lower.push(tmp);
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>K>>N;
    for(ll i=1;i<=N;i++) {
        char p,q;
        ll x,y;
        cin>>p>>x>>q>>y;
        if(p!=q) {
            if(x>y) {
                swap(x,y);
            }
            Seg.push_back({x,y});
        } else {
            if(x>y) {
                swap(x,y);
            }
            ans=(ans+(y-x));
        }
    }
    sort(Seg.begin(),Seg.end());
    if(K==1) {
        for(Segment it:Seg) {
            Add(it.l),Add(it.r);
        }
        ll pmid=lower.top();
        debug(pmid);
        for(Segment it:Seg) {
            ans+=abs(pmid-it.l);
            ans+=abs(pmid-it.r);
        }
        ans=(ans+Seg.size());
        cout<<ans<<endl;
    } else {
        for(ll i=0;i<Seg.size();i++) {
            Add(Seg[i].l),Add(Seg[i].r);
            len[i][0]=(lower.top()*lower.size()-suml+sumr-lower.top()*upper.size());
        }
        while(!upper.empty()) upper.pop();
        while(!lower.empty()) lower.pop();
        suml=0; sumr=0;
        for(ll i=(Seg.size()-1);i>=0;i--) {
            Add(Seg[i].l),Add(Seg[i].r);
            len[i][1]=(lower.top()*lower.size()-suml+sumr-lower.top()*upper.size());
        }
        ll mn=INF,tot=Seg.size();
        tot--;
        for(ll i=0;i<tot;i++) {
            mn=min((len[i][0]+len[i+1][1]),mn);
        }
        if(tot<=0) mn=0;
        ans=(ans+mn+Seg.size());
        cout<<ans<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll TT=1;
    //cin>>TT;
    for(ll i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}