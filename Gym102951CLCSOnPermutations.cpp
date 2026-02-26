#include <iostream>
using namespace std;
const int maxn=1e5+10;
int pos[maxn],n,a[maxn],mx[maxn],f[maxn],ans;
int LB(int x) {
    return x&(-x);
}
int SingleChange(int id, int x) {
    for(;id<=n;id+=LB(id)) {
        mx[id]=max(mx[id],x);
    }
}
int GetMax(int id) {
    int ret=0;
    for(;id;id-=LB(id)) {
        ret=max(ret,mx[id]);
    }
    return ret;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        pos[x]=i;
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        a[i]=pos[x];
    }
    for(int i=1;i<=n;i++) {
        f[i]=GetMax(a[i]-1)+1;
        SingleChange(a[i],f[i]);
    }
    for(int i=1;i<=n;i++) {
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}