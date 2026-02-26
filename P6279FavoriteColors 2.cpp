#include <iostream>
#include <queue>
using namespace std;
const int maxn=2e5+10;
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
	void merge(int x,int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		if(siz[yfa]<siz[xfa]) {
			swap(xfa,yfa);
		}
		siz[yfa]+=siz[xfa];
		fa[xfa]=yfa;
	}
} dd;
int N,M,ans[maxn],cnttot,vis[maxn];
vector<int> g[maxn];
void BFS() {
	queue<int> q;
	for(int i=1;i<=N;i++) {
		q.push(i);
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]++;
		if(vis[g[u][0]]<4) {
			q.push(g[u][0]);
		}
		for(int i=1;i<g[u].size();i++) {
			if(dd.getfa(g[u][i])==dd.getfa(g[u][i-1])) {
				continue;
			}
			if(vis[g[u][i]]<4) {
				q.push(g[u][i]);
			}
			dd.merge(g[u][i-1],g[u][i]);
		}
	}
}
int main() {
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
		g[uu].push_back(vv);
	}
	dd.tot=N;
	dd.init();
	BFS();
	for(int i=1;i<=N;i++) {
		if(ans[dd.getfa(i)]==0) {
			cnttot++;
			ans[dd.getfa(i)]=cnttot;
		}
		cout<<ans[dd.getfa(i)]<<endl;
	}
	return 0;
}