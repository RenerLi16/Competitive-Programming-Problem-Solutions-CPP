#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
struct DSU {
	int fa[maxn],siz[maxn],tot;
	void init() {
		for(int i=1;i<=tot;i++) {
			fa[i]=i;
			siz[i]=1;
		}
	}
	int getfa(int x) {
		return (fa[x]==x ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x, int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		siz[yfa]=(siz[yfa]+siz[xfa]);
		fa[xfa]=yfa;
	}
} dd;
struct WormHoleSortEdge {
	int a,b,w;
	friend bool operator < (WormHoleSortEdge first, WormHoleSortEdge second) {
		return first.w>second.w;
	}
} pool[maxn];
int P[maxn],N,M,ans,mxval,mnval=0x3f3f3f3f;
bool Check(int lbound) {
//	cout<<lbound<<endl;
	dd.init();
	for(int i=1;i<=M;i++) {
		if(pool[i].w>=lbound) {
			dd.merge(pool[i].a,pool[i].b);
		} else {
//			break;
		}
	}
	for(int i=1;i<=N;i++) {
		if((dd.getfa(i))!=(dd.getfa(P[i]))) {
			return false;
		}
	}
//	cout<<"F?"<<endl;
	return true;
}
int BiSearch() {
	int l=mnval,r=mxval;
	while(l<r) {
//		cout<<l<<" "<<r<<endl;
		int mid=((l+r+1)/2);
		if(Check(mid)) {
			l=mid;
		} else {
			r=mid-1;
		}
	}
	return l;
}
int main() {
	cin>>N>>M;
	bool flag=false;
	for(int i=1;i<=N;i++) {
		cin>>P[i];
		if(P[i]!=i) {
			flag=true;
		}
	}
	for(int i=1;i<=M;i++) {
		cin>>pool[i].a>>pool[i].b>>pool[i].w;
		mxval=max(mxval,pool[i].w);
		mnval=min(mnval,pool[i].w);
	}
	if(flag==false) {
		cout<<-1<<endl;
		return 0; 
	}
//	sort(pool+1,pool+M+1);
	dd.tot=N;
	ans=BiSearch();
	cout<<ans<<endl;
	return 0;
}