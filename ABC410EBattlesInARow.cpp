#include <iostream>
#include <cstring>
using namespace std;
const int maxn=3005;
int f[maxn][maxn],A[maxn],B[maxn],N,H,M,ans;
int main() {
	cin>>N>>H>>M;
	for(int i=1;i<=N;i++) {
		cin>>A[i]>>B[i];
	}
	memset(f,0xFF,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=N;i++) {
		for(int h=0;h<=H;h++) {
			f[i][h]=max(f[i-1][h],0)+B[i];
			if(h>=A[i]) {
				f[i][h]=min(f[i][h],max(f[i-1][h-A[i]],0));
			}
		}
	}
	for(int i=1;i<=N;i++) {
		bool flag=false;
		for(int h=0;h<=H;h++) {
			if(f[i][h]!=(-1) && f[i][h]<=M) {
				ans=i;
				flag=true;
				break;
			}
		}
		if(flag==false) {
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}