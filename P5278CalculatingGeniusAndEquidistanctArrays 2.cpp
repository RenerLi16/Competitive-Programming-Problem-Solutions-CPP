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
#else
#define debug(x...) 
#define systemwait
#endif

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

mt19937_64 rd(0);
const int INF=2e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=3e5+10;

struct Node {
    int l,r;
    int mn,mx,hsum;
} t[maxn*4];

int N,M,A[maxn];
int mn[maxn*4],mx[maxn*4],hsum[maxn*4];
int K,P,_mn,_mx,S,cnt;

int qpow(int x,int k) {
    int res=1LL;
    while(k) {
        if(k%2) res=(res*x)%P;
        x=(x*x)%P;
        k=(k>>1);
    }
    return res;
}

void Update(int p) {
    hsum[p]=(hsum[p<<1]+hsum[(p<<1)|1])%P;
    mn[p]=min(mn[p<<1],mn[(p<<1)|1]);
    mx[p]=max(mx[p<<1],mx[(p<<1)|1]);
}

void Build(int p,int l,int r) {
    if(l==r) {
        mn[p]=A[l];
        mx[p]=A[l];
        hsum[p]=qpow(K,A[l]);
        return;
    }
    int mid=((l+r)>>1);
    Build((p<<1),l,mid);
    Build(((p<<1)|1),mid+1,r);
    Update(p);
}

void Add(int p,int l,int r,int s) {
    if(l==r) {
        mn[p]=A[l];
        mx[p]=A[l];
        hsum[p]=qpow(K,A[l]);
        return;
    }
    int mid=((l+r)>>1);
    if(s<=mid) {
        Add((p<<1),l,mid,s);

    }else {
        Add((p<<1)|1,mid+1,r,s);
    }
    Update(p);
}

void Ask(int p,int l,int r,int s,int t) {
    if(l>=s && r<=t) {
        S=(S+hsum[p])%P;
        _mn=min(_mn,mn[p]);
        _mx=max(_mx,mx[p]);
        return;
    }
    int mid=((l+r)>>1);
    if(s<=mid) {
        Ask((p<<1),l,mid,s,t);

    }
    if(t>mid) {
        Ask((p<<1)|1,mid+1,r,s,t);
    }
}

bool IsPrime(int x) {
    for(int i=2;(i*i)<=x;i++) {
        if((x%i==0)) return false;
    }
    return true;
}

void solve() {
//--------Initiallize--------
    K=rd()%10000+10001;
    while(!IsPrime(K)) ++K;
    P=rd()%10000+1000000001;
    while(!IsPrime(P)) ++P;
//--------Input--------
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    Build(1,1,N);
    while(M--) {
        int type; cin>>type;
        if(type==2) {
            int l,r,k; cin>>l>>r>>k;
            l^=cnt,r^=cnt,k^=cnt;
            S=0;
            _mn=INF;
            _mx=-INF;
            Ask(1,1,N,l,r);
            // return;

            if(k==0) {
                if(_mn==_mx) {
                    cout<<"Yes"<<endl; ++cnt;
                } else {
                    cout<<"No"<<endl;
                }
                continue;
            }
            int res=(qpow(K,_mn)-qpow(K,_mx+k))%P*qpow((1-qpow(K,k)),P-2)%P;
            if(res<0) {
                res=(res+P);
            }
            if(_mn+k*(r-l)!=_mx || res!=S) {
                cout<<"No"<<endl;
            } else {
                cout<<"Yes"<<endl;
                cnt++;
            }
        } else {
            int x,y; cin>>x>>y;
            x^=cnt,y^=cnt;
            A[x]=y;
            Add(1,1,N,x);
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