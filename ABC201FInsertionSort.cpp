#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
struct Fenwick {
    int sz;
    ll t[maxn];
    int lowbit(int id) {
        return (id&(-id));
    }
    void insert(int x, ll k) {
        for(;x<=sz;x+=(lowbit(x))) {
            t[x]=min(t[x],k);
        }
    }
    ll query(int x) {
        ll ret=INF;
        for(;x;x-=(lowbit(x))) {
            ret=min(ret,t[x]);
        }
        return ret;
    }
} fw;
struct Node {
    ll A,B,C;
    void reorder() {
        B=min(B,A);
        C=min(C,A);
    }
} op[maxn];
int a[maxn],pos[maxn],n,s;
ll f[maxn],sum[maxn],ans=INF;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>op[i].A>>op[i].B>>op[i].C;
        op[i].reorder();
        sum[i]=sum[i-1]+op[i].A;
    }
    memset(fw.t,0x3f,sizeof(fw.t));
    fw.sz=n;
    ll tmp=0;
    for(int i=1;i<=n;i++) {
        f[i]=min(tmp,fw.query(pos[i])+sum[i-1]);
        tmp+=op[i].B;
        fw.insert(pos[i],f[i]-sum[i]);
    }
    tmp=0;
    for(int i=n;i>=1;i--) {
        ans=min(ans,f[i]+tmp);
        tmp+=op[i].C;
    }
    cout<<ans<<endl;
    return 0;
}