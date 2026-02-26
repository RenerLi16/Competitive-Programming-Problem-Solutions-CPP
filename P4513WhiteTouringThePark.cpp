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
const int maxn=5e5+10;

int N,M;

struct Node {
    int l,r;
    int lm,rm,sm,mm;
} t[maxn*4];

void Calc(int k) {
    int kk=k<<1;
    t[k].sm=(t[kk].sm+t[kk+1].sm);
    t[k].lm=max(t[kk].lm,(t[kk].sm+t[kk+1].lm));
    t[k].rm=max(t[kk+1].rm,(t[kk+1].sm+t[kk].rm));
    t[k].mm=max(max(t[kk].mm,t[kk+1].mm),(t[kk].rm+t[kk+1].lm));
}

void Create(int k,int l,int r) {
    t[k].l=l;
    t[k].r=r;
    if(l==r) {
        int x;
        cin>>x;
        t[k].lm=t[k].rm=t[k].mm=t[k].sm=x;
        return;
    }
    int mid=((l+r)/2);
    Create((k<<1),l,mid);
    Create(((k<<1)|1),(mid+1),r);
    Calc(k);
}

void Add(int k,int x,int data) {
    if(t[k].l==t[k].r && t[k].l==x) {
        t[k].lm=t[k].rm=t[k].mm=t[k].sm=data;
        return;
    }
    int mid=((t[k].l+t[k].r)>>1);
    if(x<=mid) Add((k<<1),x,data);
    else Add(((k<<1)|1),x,data);
    Calc(k);
}

Node Ask(int k,int l,int r) {
    if(t[k].l>=l && t[k].r<=r) {
        return t[k];
    }
    int mid=((t[k].l+t[k].r)>>1);
    if(r<=mid) return Ask((k<<1),l,r);
    if(l>mid) return Ask(((k<<1)|1),l,r);
    Node ans1=Ask((k<<1),l,r),ans2=Ask(((k<<1)|1),l,r),ans;
    ans.sm=(ans1.sm+ans2.sm);
    ans.lm=max(ans1.lm,(ans1.sm+ans2.lm));
    ans.rm=max(ans2.rm,(ans2.sm+ans1.rm));
    ans.mm=max(max(ans1.mm,ans2.mm),(ans1.rm+ans2.lm));
    return ans;

}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>M;
//--------No fluff real stuff--------
    Create(1,1,N);
    for(int i=1;i<=M;i++) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==2) {
            Add(1,x,y);
        } else {
            if(x>y) swap(x,y);
            Node p=Ask(1,x,y);
            cout<<p.mm<<endl;
        }
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