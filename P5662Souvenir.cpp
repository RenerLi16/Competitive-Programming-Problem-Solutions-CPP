#include <iostream>
#include <cstring>
using namespace std;
const int maxn=105;
const int maxm=1e4+10;
int f[maxm],a[maxn][maxn],T,N,m;
int main() {
    cin>>T>>N>>m;
    for(int i=1;i<=T;i++) {
        for(int j=1;j<=N;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<T;i++) {
        memset(f,0,sizeof(f));
        for(int j=1;j<=N;j++) {
            for(int k=a[i][j];k<=m;k++) {
                f[k]=max(f[k],f[k-a[i][j]]+(a[i+1][j]-a[i][j]));
            }
        }
        m=max(m,f[m]+m);
    }
    cout<<m<<endl;
    return 0;
}