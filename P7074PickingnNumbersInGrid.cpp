#include <iostream>
#define ll long long
using namespace std;
const ll INF=1e18+7;
const int maxn=1005;
ll f[maxn][maxn][2],mp[maxn][maxn],n,m;
int main() {
    cin>>n>>m;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            cin>>mp[i][j];
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            for(ll st=0;st<=1;st++) {
                f[i][j][st]=-INF;
            }
        }
    }
    f[1][1][1]=mp[1][1];
    for(ll j=1;j<=m;j++) {
        for(ll i=1;i<=n;i++) {
            if(j>1) {
                f[i][j][1]=max(f[i][j][1],f[i][j-1][0]+mp[i][j]);
                f[i][j][1]=max(f[i][j][1],f[i][j-1][1]+mp[i][j]);
            }
            if((i-1)>=1) {
                f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+mp[i][j]);
            }
        }
        for(ll i=n;i>=1;i--) {
            if(j>1) {
                f[i][j][0]=max(f[i][j][0],f[i][j-1][0]+mp[i][j]);
                f[i][j][0]=max(f[i][j][0],f[i][j-1][1]+mp[i][j]);
            }
            if((i+1)<=n) {
                f[i][j][0]=max(f[i][j][0],f[i+1][j][0]+mp[i][j]);
            }
        }
    }
//    for(int st=0;st<=1;st++) {
//        for(int i=1;i<=n;i++) {
//            for(int j=1;j<=m;j++) {
//                cout<<f[i][j][st]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
    cout<<(max(f[n][m][0],f[n][m][1]))<<endl;
    return 0;
}