#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int maxn=2e5+10;
const int maxval=1e6+10;
int f[maxn],lastv[maxval],sum[maxn],n,a[maxn],TTT;
void solve() {
    memset(lastv,0,sizeof(lastv));
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+(a[i]==a[i-1] ? a[i] : 0);
        int lst=lastv[a[i]];
        lastv[a[i]]=i;
        f[i]=f[i-1];
        if(lst>0 && lst==i-1) {
            f[i]=f[i-1]+a[i];
        } else if(lst>0) {
            f[i]=max(f[i],f[lst+1]+sum[i-1]-sum[lst+1]+a[i]);
        }
    }
    cout<<f[n]<<endl;
    return;
}
signed main() {
    cin>>TTT;
    while(TTT--) {
        solve();
    }
    return 0;
}