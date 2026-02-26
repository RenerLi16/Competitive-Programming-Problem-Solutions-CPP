#include <iostream>
#define int long long
using namespace std;
const int maxn=55;
int f[maxn][maxn][maxn][maxn],a[maxn],N;
signed main() {
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=N;i++) {
        f[i][i][a[i]][a[i]]=1;
        f[i][i][a[i]-1][a[i]]=1;
        f[i][i][a[i]][a[i]+1]=1;//Think carefully why we need these 2.
    }
    for(int len=2;len<=N;len++) {
        for(int sl=1;(sl+len-1)<=N;sl++) {
            int sr=(sl+len-1);
            for(int range=2;range<=50;range++) {
                for(int vl=1;(vl+range-1)<=50;vl++) {
                    int vr=(vl+range-1);
                    f[sl][sr][vl][vr]=max(f[sl][sr][vl+1][vr],f[sl][sr][vl][vr-1]);
                    f[sl][sr][vl][vr]=max(f[sl][sr][vl][vr],f[sl+1][sr][vl][vr]+(a[sl]==vl));
                    f[sl][sr][vl][vr]=max(f[sl][sr][vl][vr],f[sl][sr-1][vl][vr]+(a[sr]==vr));
//                    if((sr-sl)>=2)
                    f[sl][sr][vl][vr]=max(f[sl][sr][vl][vr],f[sl+1][sr-1][vl][vr]+((a[sl]==vr)+(a[sr]==vl)));
                }
            }
        }
    }
    cout<<f[1][N][1][50]<<endl;
    return 0;
}