#include <bits/stdc++.h>
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
const int P=1e9+7;
//const int P=998244353;
const int maxn=751;

int R,C,mp[maxn][maxn],tot,ans,f[maxn],K;
int rt[maxn*maxn];//表示每棵线段树的根

struct DSXDS{
    #define lson (ls[x])
    #define rson (rs[x])
    #define mid ((l+r)/2)
    //int ls[maxn<<2],rs[maxn<<2],sum[maxn];//这样开数组内存爆了
    int ls[750*750*10],rs[750*750*10],sum[750*750*10];//总共插入750*750次，每次插入新增log2（750）=10个点
    void Update(int x) {
        sum[x]=(sum[lson]+sum[rson])%P;//没取模
    }
    void Add(int &x,int l,int r,int s,int k) {
        if(!x) x=(++tot);
        if(l==r) {
            (sum[x]+=k)%=P;
            return;
        }
        if(s<=mid) {
            Add(lson,l,mid,s,k);
        }
        else  {
            Add(rson,(mid+1),r,s,k);
        }
        Update(x);
    }
    void Ask(int x,int l,int r,int s,int t) {
        if (s>t || !x) return;//特判s>t，因为j会for到1，此时查询范围是[1~0]
        if(l>=s && r<=t) {
            (ans+=sum[x])%=P;
            return;//没写return
        }
        if(s<=mid) {
            Ask(lson,l,mid,s,t);
        }
        if(t>mid) {
            Ask(rson,(mid+1),r,s,t);
        }
    }
} xt;

void solve() {
//--------Initiallize---------
//--------Input--------
    cin>>R>>C>>K;//读入三个数字
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=R;i++) {
        for(int j=C;j>=1;j--) {
            ans=0;
            xt.Ask(rt[mp[i][j]],1,C,1,(j-1));
            int t=ans;
            ans=0;
            xt.Ask(rt[0],1,C,1,(j-1));
            f[j]=(ans-t)%P;
            if (i==1 && j==1) f[j]=1;//起点位置初始化
           // cout<<i<<' '<<j<<' '<<f[j]<<"\n";
            xt.Add(rt[mp[i][j]],1,C,j,f[j]);//这里应该是单点加吧
            xt.Add(rt[0],1,C,j,f[j]);//0线段树没更新
        }
    }
    cout<<(f[C]+P)%P<<endl;
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
