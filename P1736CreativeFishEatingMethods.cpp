#include <iostream>
#include <cstring>
using namespace std;
const int maxn=2505;
int mp[maxn][maxn],f[maxn][maxn],hor[maxn][maxn],ver[maxn][maxn],N,M,ans;
void solve() {
    memset(hor,0,sizeof(hor));
    memset(ver,0,sizeof(ver));
    memset(f,0,sizeof(f));
    for(int j=1;j<=M;j++) {
        for(int i=1;i<=N;i++) {
            ver[i][j]=(mp[i][j]==1 ? 0 : (ver[i-1][j]+1));
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            hor[i][j]=(mp[i][j]==1 ? 0 : (hor[i][j-1]+1));
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(mp[i][j]==1) {
                f[i][j]=min(f[i-1][j-1],min(ver[i-1][j],hor[i][j-1]))+1;
            }
        }
    }
//    for(int i=1;i<=N;i++) {
//        for(int j=1;j<=M;j++) {
//            cout<<hor[i][j]<<" ";
//            cout<<f[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            ans=max(ans,f[i][j]);
        }
    }
}
int main() {
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>mp[i][j];
        }
    }
    solve();
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M/2;j++) {
            swap(mp[i][j],mp[i][M-j+1]);
        }
    }
    solve();
    cout<<ans<<endl;
    return 0;
}