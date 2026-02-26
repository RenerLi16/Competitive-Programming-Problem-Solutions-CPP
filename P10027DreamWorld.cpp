#include <iostream>
using namespace std;
const int maxn=105;
int n,m,k,mod,s,f[maxn][maxn][maxn],g[maxn][maxn][maxn],ctm[maxn][maxn],ans;
int main() {
    cin>>n>>m>>k>>mod>>s;
    for(int i=1;i<=s;i++) {
        int x,y;
        cin>>x>>y;
        ctm[x][y]=1;
    }
    //init
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(ctm[i][j]) {
                continue;
            }
            g[i][j][0]=1;
        }
    }
    for(int num=0;num<=k;num++) {
        f[1][1][num]=1;
    }
    //DP
    for(int num=0;num<=k;num++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(ctm[i][j]) {
                    continue;
                }
                if(i>1) {
                    f[i][j][num]+=f[i-1][j][num];
                }
                if(j>1) {
                    f[i][j][num]+=f[i][j-1][num];
                }
                for(int lastsz=1;lastsz<num;lastsz++) {
                    g[i][j][num]+=(g[i+1][j][lastsz]+g[i][j+1][lastsz])*g[i][j][num-lastsz-1];
                    f[i][j][num]+=f[i][j][num-lastsz]*g[i][j][lastsz];
                }
                for(int kk=1;kk<=num;kk++) {
                    f[i][j][num]+=f[i][j][num-kk]*g[i][j][kk];
                }
            }
        }
    }
    for(int num=0;num<=k;num++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<f[i][j][num]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=1;i<=k;i++) {
        ans+=f[n][m][i];
    }
    cout<<ans<<endl;
    return 0;
}