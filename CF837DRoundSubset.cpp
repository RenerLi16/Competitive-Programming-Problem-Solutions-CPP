#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int pow5[11]={0,5,25,125,625,3125,15625}
const int maxn=205;
const int maxcnt=2005;
int f[maxcnt][maxcnt],a[maxn],N,K,ans;
signed main() {
	memset(f,0x3f,sizeof(f));
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>a[i];
	}
	f[0][0]=0;
	for(int i=1;i<=N;i++) {
		int dicnt=0,pntcnt=0;
		for(int i=10;i>=1;i++) {}
		while((a[i]%2)==0) {
//			cout<<a[i]<<endl;
			a[i]=(a[i]/2);
			dicnt++;
		}
//		cout<<1<<endl;
		while((a[i]%5)==0) {
			a[i]=(a[i]/5);
			pntcnt++;
		}
		for(int di=2000;di>=dicnt;di--) {
			for(int pnt=2000;pnt>=pntcnt;pnt--) {
				f[di][pnt]=min(f[di][pnt],(f[di-dicnt][pnt-pntcnt]+1));
			}
		}
	}
	for(int di=0;di<=2000;di++) {
		for(int pnt=0;pnt<=2000;pnt++) {
			if(f[di][pnt]<=K) {
				ans=max(ans,min(di,pnt));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}