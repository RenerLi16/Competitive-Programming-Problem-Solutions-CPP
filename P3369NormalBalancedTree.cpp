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

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

vector<pii> qry;
int M,tot,N,B[maxn],Bsiz,rt;

struct DSXDS {
    #define lson ls[x]
    #define rson rs[x]
    #define mid ((l+r)/2)
    int ls[maxn*32],rs[maxn*32],cnt[maxn*32];
    void Update(int x) {
        cnt[x]=(cnt[lson]+cnt[rson]);
    }
    void Add(int &x,int l,int r,int s,int k) {
        if(x==0) {
            x=(++tot);
        }
        if(l==r) {
            cnt[x]+=k;
            return;
        }
        if(s<=mid) {
            Add(lson,l,mid,s,k);
        }
        else {
            Add(rson,(mid+1),r,s,k);
        }
        Update(x);
    }
    int Ask(int x,int l,int r,int s,int t) {
        if(!x) {
            return 0;
        }
        if(l>=s && r<=t) {
            return cnt[x];
        }
        int res=0;
        if(s<=mid) {
            res+=Ask(lson,l,mid,s,t);
        }
        if(t>mid) {
            res+=Ask(rson,(mid+1),r,s,t);
        }
        return res;
    }
    int Kth(int x,int l,int r,int k) {
        if(l==r) {
            return l;
        }
        if(cnt[lson]>=k) {
            return Kth(lson,l,mid,k);
        }       else {
            k-=cnt[lson];
            return Kth(rson,(mid+1),r,k);
        }
    }
} xt;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    while(N--) {
        int type;
        int x;
        cin>>type>>x;
        qry.push_back({type,x});
        if(type!=4) {
            B[++Bsiz]=x;
        }
    }
    sort(B+1,B+Bsiz+1);
    M=unique(B+1,B+Bsiz+1)-B-1;
    for(auto [type,x]:qry) {
        if(type==4) {
            cout<<B[xt.Kth(rt,1,M,x)]<<endl;
        }
        x=lower_bound(B+1,B+M+1,x)-B;
        if(type==1) {
            xt.Add(rt,1,M,x,1);
        } else if(type==2) {
            xt.Add(rt,1,M,x,(-1));
        } else if(type==3) {
            cout<<xt.Ask(rt,1,M,1,(x-1))+1<<endl;
        } else if(type==5) {
            int cnt=xt.Ask(rt,1,M,1,(x-1));
            cout<<B[xt.Kth(rt,1,M,cnt)]<<endl;
        } else if(type==6) {
            int cnt=xt.Ask(rt,1,M,1,x);
            cout<<B[xt.Kth(rt,1,M,(cnt+1))]<<endl;
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