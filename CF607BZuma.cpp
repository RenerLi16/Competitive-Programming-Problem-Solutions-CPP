#include <iostream>
//#define TEST
using namespace std;
const int INF=1e9+7;
const int maxn=505;
int n,a[maxn],f[maxn][maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            f[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++) {
        f[i][i]=1;
    }
    for(int len=2;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            int r=l+len-1;
            if(a[l]==a[r]) {
                f[l][r]=(l+1==r ? 1 : f[l+1][r-1]);
            }
            for(int k=l;k<r;k++) {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
            }
        }
    }
    #ifdef TEST
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    #endif
    cout<<f[1][n]<<endl;
    return 0;
}