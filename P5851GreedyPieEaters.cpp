#include<iostream>
using namespace std;
const int maxn=305;
int n,m,f[maxn][maxn],ans[maxn][maxn][maxn];
int main() {
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int w,l,r;
		cin>>w>>l>>r;
		for(int j=l;j<=r;j++) {
			ans[j][l][r]=w;
		}
	}
	for(int mid=1;mid<=n;mid++) {
		for(int l=mid;l>=1;l--) {
			for(int r=mid;r<=n;r++) {
				if(l!=1) {
					ans[mid][l-1][r]=max(ans[mid][l][r],ans[mid][l-1][r]);
				}
				if(r!=n) {
					ans[mid][l][r+1]=max(ans[mid][l][r],ans[mid][l][r+1]);
				}
			}
		}
	}
    for(int i=n;i>=1;i--) {
        for(int j=n;j>=1;j--) {
            for(int k=i;k<j;k++) {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
            }
            for(int k=i;k<=j;k++) {
                f[i][j]=max(f[i][j],(k!=i ? f[i][k-1] : 0) + (k!=j ? f[k+1][j] : 0)+ans[k][i][j]);
            }
        }
    }
	cout<<f[1][n]<<endl;
	return 0;
}