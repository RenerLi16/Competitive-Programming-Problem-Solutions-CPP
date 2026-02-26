#include <iostream>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int maxn=5005;
int f[maxn][maxn][2],presum[maxn][maxn][2],n,k,ans;
signed main() {
    cin>>n>>k;
    for(int i=0;i<=n;i++) {
        f[i][i][0]=1;
        f[i][i][1]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            f[i][j][0]=(f[i][j][0]+(presum[i-j][i-j][1]-presum[i-j][j][1]))%MOD;
            presum[i][j][0]=(presum[i][j-1][0]+f[i][j][0])%MOD;
            f[i][j][1]=(f[i][j][1]+(presum[i-j][min(j-1,i-j)][0]-presum[i-j][0][0])+MOD)%MOD;
            presum[i][j][1]=(presum[i][j-1][1]+f[i][j][1])%MOD;
        }
    }
    for(int i=1;i<=n;i++) {
        ans=(ans+f[n][i][0]+f[n][i][1])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}