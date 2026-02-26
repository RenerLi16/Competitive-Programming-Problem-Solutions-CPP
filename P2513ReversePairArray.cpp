#include <iostream>
#define ll long long
using namespace std;
const int MOD=1e9+7;
const int maxn=1005;
const int maxk=1e4+10;
ll f[maxn][maxk],n,k;
int MODsubtract(ll x, ll y) {
    if(x<y) {
        x+=MOD;
    }
    return x-y;
}
int main() {
    cin>>n>>k;
    f[1][0]=1LL;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=k+1;j++) {
            f[i][j]=MODsubtract(f[i-1][j],f[i-1][max(1,(j-(i-1)))-1]);/*
            for(int curk=0;curk<=min(j,(i-1));curk++) {
                (f[i][j]+=f[i-1][j-curk])%MOD;
            }*/
        }
        for(int j=1;j<=k+1;j++) {
            f[i][j]=(f[i][j-1]+f[i][j])%MOD;
        }
    }
    cout<<(MODsubtract(f[n][k+1],f[n][k]))<<endl;
    return 0;
}