#include <iostream>
using namespace std;
const int maxn=1e5+10;
struct DSU {
    int fa[maxn*2],tot;//,siz[maxn*2]
    void init() {
        for(int i=1;i<=tot;i++) {
            fa[i]=i;
//            siz[i]=1;
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) {
        int fax=getfa(x),fay=getfa(y);
        fa[fax]=fay;
    }
}dsu;
int a[maxn*2],C,T,N,M,ans;
int rev(int x) {
    if(x==(2*N+3)) {
        return x;
    }
    if(x<=N) {
        return (x+N);
    }
    if(x<=2*N) {
        return (x-N);
    }
    if(x==(2*N+1)) {
        return x+1;
    }
    return x-1;
}
void solve() {
    ans=0;
    cin>>N>>M;
    dsu.tot=2*N+10;
    dsu.init();
    for(int i=1;i<=N;i++) {
        a[i]=i;
    }
    for(int i=1;i<=M;i++) {
        char op;
        int ii,jj;
        cin>>op;
        if(op=='+') {
            cin>>ii>>jj;
            a[ii]=a[jj];
        } else if(op=='-') {
            cin>>ii>>jj;
            a[ii]=rev(a[jj]);
        } else if(op=='U') {
            cin>>ii;
            a[ii]=(N*2+3);
        } else if(op=='F') {
            cin>>ii;
            a[ii]=(N*2+2);
        } else {
            cin>>ii;
            a[ii]=(N*2+1);
        }
    }
    for(int i=1;i<=N;i++) {
        dsu.merge(i,a[i]);
        dsu.merge((i+N),rev(a[i]));
    }
    for(int i=1;i<=N;i++) {
//        cout<<dsu.getfa(i)<<" "<<dsu.getfa(i+N)<<endl;
        if(dsu.getfa(i)==dsu.getfa(i+N)) {
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    cin>>C>>T;
    for(int i=1;i<=T;i++) {
        solve();
    }
    return 0;
}