#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int maxn=305;
const int maxval=1e4+10;
int f[maxval],ww[maxn],tt[maxn],N,W,ans;
bool Check(int x) {
	memset(f,0x80,sizeof(f));
//	cout<<f[10000]<<endl;
	f[0]=0;
	for(int i=1;i<=N;i++) {
		for(int j=W;j>=0;j--) {
			if(f[j]==f[10000]) {
//				cout<<"Ha"<<endl;
				continue;
			}
			f[min(j+ww[i],W)]=max(f[min(j+ww[i],W)],(f[j]+tt[i]-ww[i]*x));
		}
	}
	if(f[W]>=0) {
		return true;
	} else {
		return false;
	}
}
int BiSearch() {
	int l=0,r=1e6+10;
	while(l<=r) {
		int mid=((l+r)/2);
		if(Check(mid)) {
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	return l-1;
}
signed main() {
	cin>>N>>W;
	for(int i=1;i<=N;i++) {
		cin>>ww[i]>>tt[i];
		tt[i]=(tt[i]*1000);
	}
	ans=BiSearch();
	cout<<ans<<endl;
	return 0;
}