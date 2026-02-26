#include <iostream>
using namespace std;
const int INF=1e9+7;
const int MOD=1e9+7;
const int maxn=105;
const int maxh=1005;
int h[maxn],f[maxn][maxh],n,kmax=INF,ans;
void solve(int k) {
    for(int i=1;i<=n;i++) {
        h[i]-=k;
    }
    memset(f,0,sizeof(f));
    f[1][0]=1;
    for(int id=1;id<n;id++) {
        for(int j=0;j<=h[id];j++) {
            f[id][j]=(f[id][j-1]+f[id][j])%MOD;
            if(h[id+1]>=j) {
                f[id+1][0]=(f[id+1][0]+f[id][j])%MOD;
                f[id+1][(h[id+1]-j)+1]=(f[id+1][(h[id+1]-j)+1]-f[id][j])%MOD;
            }
        }
    }
    ans=(ans+f[n][0])%MOD;
    for(int i=1;i<=n;i++) {
        h[i]+=k;
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
        kmax=min(kmax,h[i]);
    }
    if(n%2==1) {
        for(int i=0;i<=kmax;i++) {
            solve(i);
        }
    } else {
        solve(0);
    }
    cout<<ans<<endl;
    return 0;
}