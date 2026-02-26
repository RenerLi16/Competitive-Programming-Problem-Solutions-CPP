#include <iostream>
#include <vector>
using namespace std;
const int INF=1e9+7;
const int maxn=105;
int a[maxn],n,ans;
vector<vector<vector<int>>> f;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    /*n=6;
    a[1]=1;
    a[2]=1;
    a[3]=2;
    a[4]=0;
    a[5]=0;
    a[6]=1;*/
    f.resize(n+1);
    for(int i=0;i<=n;i++) {
        f[i].resize(n+1);
        for(int j=0;j<=n;j++) {
            f[i][j].resize(n+1);
            for(int p=0;p<=n;p++) {
                f[i][j][p]=INF;
            }
        }
    }
    f[1][1][0]=(a[1]==0 ? 0 : 1);
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            for(int cur=0;cur<n-1;cur++) {
                f[i+1][j][cur+1]=min(f[i+1][j][cur+1],(a[i+1]==cur+1 ? f[i][j][cur] : (f[i][j][cur]+1)));
                f[i+1][j+1][0]=min(f[i+1][j+1][0],(a[i+1]==0 ? f[i][j][cur] : (f[i][j][cur]+1)));
            }
        }

    }
    for(int i=1;i<=n;i++) {
        ans=INF;
        for(int last=0;last<n;last++) {
            ans=min(ans,f[n][i][last]);
        }
        cout<<ans<<endl;
    }
    return 0;
}