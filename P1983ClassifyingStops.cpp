#include <iostream>
using namespace std;
const int maxn=1145;
int g[maxn][maxn],st[maxn],Stop[maxn],f[maxn],N,M,ans;
int dfs(int x) {
	if(f[x]!=0) {
		return f[x];
	}
	int res=0;
	for(int i=1;i<=N;i++) {
		if(g[x][i]==1) {
			res=max(res,dfs(i));
		}
	}
	f[x]=res+1;
	return f[x];
}
int main() {
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		memset(st,0,sizeof(st));
		int ss;
		cin>>ss;
		for(int j=1;j<=ss;j++) {
			cin>>Stop[j];
			st[Stop[j]]=1;
		}
		for(int j=1;j<=ss;j++) {
			for(int k=Stop[1];k<Stop[ss-1];k++) {
				if(st[k]!=1) {
					g[Stop[j]][k]=1;
				}
			}
		}
	}
	for(int i=1;i<=N;i++) {
		ans=max(ans,dfs(i));
	}
	cout<<ans<<endl;
	return 0;
}