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
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=4e5+10;

struct node{
    int len;
    long long a[55];
    node(){
        len=0;
        memset(a,0,sizeof(a));
    }
    node (long long s){
        len=0;
        memset(a,0,sizeof(a));
        while (s){
            a[++len]=s%1000000;
            s/=1000000;
        }
    }
    node(string s){
        len=0;
        memset(a,0,sizeof(a));
        if (s=="0") return;
        int k;
        while (s.length()){
            k=min(6,(int)s.length());
            a[++len]=atoi(s.substr(s.length()-k,k).c_str());
            s=s.substr(0,s.length()-k);
        }
    }
    node operator+(const node &k)const{
        node ans;
        ans.len=max(len,k.len);
        long long x=0;
        for (int i=1;i<=ans.len;++i){
            x+=a[i]+k.a[i];
            ans.a[i]=x%1000000;
            x/=1000000;
        }
        if (x) ans.a[++ans.len]=x;
        return ans;
    }
    node operator-(const node &k)const{
        node ans;
        ans.len=max(len,k.len);
        long long x=0;
        for (int i=1;i<=ans.len;++i){
            if (a[i]-x>=k.a[i]) {
                ans.a[i]=a[i]-x-k.a[i];
                x=0;
            }
            else {
                ans.a[i]=a[i]-x-k.a[i]+1000000;
                x=1;
            }
        }
        while (ans.len && ans.a[ans.len]==0) --ans.len;
        return ans;
    }
    node operator*(const node &k)const{
        node ans;
        if (len==0 || k.len==0) return ans;
        ans.len=len+k.len-1;
        for (int i=1;i<=len;++i)
            for (int j=1;j<=k.len;++j)
                ans.a[i+j-1]+=a[i]*k.a[j];
        long long x=0;
        for (int i=1;i<=ans.len;++i){
            x+=ans.a[i];
            ans.a[i]=x%1000000;
            x/=1000000;
        }
        if (x) ans.a[++ans.len]=x;
        return ans;
    }
    bool operator<(const node &k)const{
        if (len<k.len) return true;
        else if (len>k.len) return false;
        for (int i=len;i>=1;--i){
            if (a[i]<k.a[i]) return true;
            else if (a[i]>k.a[i]) return false;
        }
        return false;
    }
    bool operator<=(const node &k)const{
        if (len<k.len) return true;
        else if (len>k.len) return false;
        for (int i=len;i>=1;--i){
            if (a[i]<k.a[i]) return true;
            else if (a[i]>k.a[i]) return false;
        }
        return true;
    }
    bool operator>(const node &k)const{
        if (len>k.len) return true;
        else if (len<k.len) return false;
        for (int i=len;i>=1;--i){
            if (a[i]>k.a[i]) return true;
            else if (a[i]<k.a[i]) return false;
        }
        return false;
    }
    node operator/(const long long k)const{  //高精度/整形
        node ans;
        long long x=0;
        for (int i=len;i>=1;--i){
            x=x*1000000+a[i];
            ans.a[i]=x/k;
            x%=k;
            if (!ans.len && ans.a[i]) ans.len=i;
        }
        return ans;

    }
    long long operator%(const long long k)const{  //高精度%整形
        long long x=0;
        for (int i=len;i>=1;--i){
            x=x*1000000+a[i];
            x%=k;
        }
        return x;
    }
}ans,kk;
istream &operator >> (istream &in,node &k){
    string s;
    in>>s;
    k=node(s);
    return in;
}
ostream &operator << (ostream &out,node &k){
    if (k.len==0) {
        cout<<0<<endl;
        return out;
    }
    cout<<k.a[k.len];
    for (int i=k.len-1;i>=1;--i){
        cout<<k.a[i]/100000;
        cout<<k.a[i]/10000%10;
        cout<<k.a[i]/1000%10;
        cout<<k.a[i]/100%10;
        cout<<k.a[i]/10%10;
        cout<<k.a[i]%10;
    }
    cout<<endl;
    return out;
}

vector<pair<int,int>> mp[maxn];
ll N,G,rt,S,T,g[maxn],A[maxn],sum[maxn];

void DFS(int x,int _fa) {
    // debug(x,_fa);
    sum[x]=A[x];
    if(!(A[x]==0)) {
        g[x]=1;
    }
    for(int i=0;i<mp[x].size();i++) {
        int to=mp[x][i].fi,w=mp[x][i].se;
        if(to!=_fa) {
            DFS(to,x);
            // debug(sum[to]);
            // debug((abs(sum[to])+G-1)/G);
            if(g[to]==0) {
                continue;
            }
            g[x]=1;
            int tmp=sum[to];
            if(tmp<0) {
                tmp=(-tmp);
            }
            if(tmp==0) {
                ans=ans+node(w*2);
            } else {
                ans=ans+(((tmp+G-1)/G)*w*2);
            }
            sum[x]=sum[x]+sum[to];
        }
    }
}

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>G>>rt;
    for(int i=1;i<N;i++) {
        int x,y,w;
        cin>>x>>y>>w;
        mp[x].push_back({y,w});
        mp[y].push_back({x,w});
    }
    cin>>S>>T;
    for(int i=1;i<=S;i++) {
        int x,k;
        cin>>x>>k;
        A[x]=k;
    }
    for(int i=1;i<=T;i++) {
        int x,k;
        cin>>x>>k;
        A[x]=(-k);
    }
    DFS(rt,0);
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
