#include <iostream>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int maxn=1e6+10;
int f[maxn],n,m,k,ans;
signed main() {
    cin>>n>>m>>k;
    f[0]=1;
    int cursum=0;
    for(int i=1;i<k;i++) {
        f[i]=(f[i-1]*m)%MOD;
        cursum=(cursum+f[i])%MOD;
    }
    for(int i=k;i<=n;i++) {
        f[i]=(cursum*(m-1))%MOD;
        cursum=(cursum+f[i]-f[i-k+1]+MOD)%MOD;
    }
    ans=1;
    for(int i=1;i<=n;i++) {
        ans=(ans*m)%MOD;
    }
    ans=(ans-f[n]+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}