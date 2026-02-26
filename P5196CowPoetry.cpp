#include <iostream>
#include <algorithm>
//#define int long long
using namespace std;
const int MOD=1e9+7;
const int maxn=5005;
const int maxlen=5005;
long long f[maxlen],s[30],len[maxn],tp[maxn],tps[maxn],N,M,K,sum,ans=1;
long long QuickPower(long long x, long long k) {
	long long res=1;
	while(k) {
		if((k%2)==1) {
			res=(res*x)%MOD;
		}
		x=(x*x)%MOD;
		k=(k/2);
	}
	return res;
}
bool cmp(long long first, long long second) {
	return first>second;
}
int main() {
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++) {
		cin>>len[i]>>tp[i];
	}
	f[0]=1;
	for(int j=0;j<=K;j++) {
		for(int i=1;i<=N;i++) {
			if(j>=len[i]) {
				f[j]=(f[j]+f[j-len[i]])%MOD;
			}
		}
	}
//	for(int i=0;i<=K;i++) {
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=M;i++) {
		char cc;
		cin>>cc;
		s[(cc-'A')+1]++;
	}
	for(int i=1;i<=N;i++) {
		tps[tp[i]]=(tps[tp[i]]+f[(K-len[i])])%MOD;
	}
//	cout<<QuickPower(5,2)<<endl;
	sort(s+1,s+26+1,cmp);
	sort(tps+1,tps+N+1,cmp);
//	for(int i=1;i<=N;i++) {
//		cout<<tps[i]<<" "<<endl;
//	}
//	return 0; 
	for(int i=1;i<=26;i++) {
//		cout<<s[i]<<endl;
		sum=0;
		if(s[i]==0) {
			break;
		}
		for(int j=1;j<=N;j++) {
			if(tps[j]==0) {
				break;
			}
			sum=(sum+QuickPower(tps[j],s[i]))%MOD;
		}
//		cout<<sum<<endl;
		ans=(ans*sum)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}