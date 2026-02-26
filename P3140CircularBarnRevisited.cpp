#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int INF=1e9+7;
const int maxn=105;
const int maxk=8;
int f[maxn*2][maxk],a[maxn*2],n,k,ans=INF;
int solve(int s) {
    memset(f,0x3f,sizeof(f));
    f[s-1][0]=0;
    for(int i=s;i<=s+n-1;i++) {
        for(int j=1;j<=k;j++) {
            int cursum=0;
            for(int l=i;l>=s;l--) {
                cursum+=((i-l)*a[l]);
                f[i][j]=min(f[l-1][j-1]+cursum,f[i][j]);
            }
        }
    }
    return f[s+n-1][k];
}
signed main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[n+i]=a[i];
    }
    reverse(a+1,a+2*n+1);
    for(int i=1;i<=n;i++) {
        ans=min(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}