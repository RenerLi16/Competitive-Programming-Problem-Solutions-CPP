#include <iostream>
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
		if(fa[x]==x) {
			return x;
		}
		fa[x]=getfa(fa[x]);
		return fa[x];
		return (fa[x]==x ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x, int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		siz[yfa]+=siz[xfa];
		fa[xfa]=yfa;
	}
} dd;
struct CowTubeEdge {
	int u,v,w;
	friend bool operator < (CowTubeEdge first, CowTubeEdge second) {
		return first.w>second.w;
	}
} pool[maxn];
struct QueryNode {
	int id,lbound,v,ans;
	friend bool operator < (QueryNode first, QueryNode second) {
		return first.lbound>second.lbound;
	}
} q[maxn];
int N,Q,pos=1;
int main() {
	cin>>N>>Q;
	for(int i=1;i<N;i++) {
		cin>>pool[i].u>>pool[i].v>>pool[i].w;
	}
	for(int i=1;i<=Q;i++) {
		cin>>q[i].lbound>>q[i].v;
		q[i].id=i;
	}
	sort(pool+1,pool+N);
	sort(q+1,q+Q+1);
	dd.tot=N;
	dd.init();
	for(int i=1;i<=Q;i++) {
		while(pos<N && pool[pos].w>=q[i].lbound) {
			dd.merge(pool[pos].u,pool[pos].v);
			pos++;
		}
//		cout<<pos<<endl;
		q[i].ans=(dd.siz[dd.getfa(q[i].v)]-1);
	}
	sort(q+1,q+Q+1,[](QueryNode first, QueryNode second){
		return first.id<second.id;
	});
	for(int i=1;i<=Q;i++) {
		cout<<q[i].ans<<endl;
	}
	cout<<endl;
	return 0;
}