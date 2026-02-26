#include <iostream>
using namespace std;
const int maxn=2e5+10;
int f[maxn],g[maxn],tot,N,X,a[maxn],ans;
int getpos(int x) {
    int l=1,r=tot;
    while(l<=r) {
        int mid=(l+r)/2;
        if(g[mid]>x) {
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return l;
}
int main() {
    cin>>N>>X;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
        f[i]=(lower_bound(g+1,g+tot+1,a[i])-g);
        tot=max(tot,f[i]);
        g[f[i]]=a[i];
    }
//:]    cout<<1<<endl;
//    return 0;
//    for(int i=1;i<=tot;i++) {
//        cout<<g[i]<<" ";
//    }
//    cout<<endl;
    tot=0;
    for(int i=N;i>=1;i--) {
        ans=max(ans,f[i]+getpos(a[i]-X)-1);
        int pos=getpos(a[i]);
        tot=max(tot,pos);
        g[pos]=a[i];
    }
    cout<<ans<<endl;
    return 0;
}