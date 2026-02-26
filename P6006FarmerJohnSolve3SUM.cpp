#include <iostream>
#define int long long
using namespace std;
const int maxn=5005;
const int maxval=3e6+10;
const int SHIFT=1e6;
int f[maxn][maxn],cnt[maxval],N,Q,a[maxn];
signed main() {
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) cnt[a[j]+SHIFT]=0;
        for(int j=i+1;j<=N;j++) {
            if((-a[i]-a[j]+SHIFT)>=0) {
                f[i][j]=cnt[-a[i]-a[j]+SHIFT];
            }
            cnt[a[j]+SHIFT]++;
        }
    }
    for(int len=1;len<=N;len++) {
        for(int l=1;(l+len-1)<=N;l++) {
            int r=(l+len-1);
            f[l][r]+=(f[l+1][r]+f[l][r-1]-f[l+1][r-1]);
        }
    }
    for(int i=1;i<=Q;i++) {
        int aa,bb;
        cin>>aa>>bb;
        cout<<f[aa][bb]<<endl;
    }
    return 0;
}