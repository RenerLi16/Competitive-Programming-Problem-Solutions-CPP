#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define int long long
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
int deg[maxn],vis[maxn],N,M,ans;
vector<int> g[maxn],indx;
set<pair<int,int>> s;
signed main() {
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
		g[uu].push_back(vv);
		g[vv].push_back(uu);
		deg[uu]++;
		deg[vv]++;
	}
//	for(int i=1;i<=N;i++) {
//		cout<<deg[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=N;i++) {
		s.insert({deg[i],i});
	}
	while(!s.empty()) {
		auto [degg,id]=*s.begin();
		s.erase(s.begin());
		indx.push_back(id);
		vis[id]=1;
		for(auto to:g[id]) {
			if(vis[to]) {
				continue;
			}
			s.erase({deg[to],to});
			deg[to]--;
			s.insert({deg[to],to});
		}
	}
//	for(auto it:indx) {
//		cout<<it<<" ";
//	}
//	cout<<endl;
	reverse(indx.begin(),indx.end());
	memset(deg,0,sizeof(deg));
	memset(vis,0,sizeof(vis));
	dd.tot=N;
	dd.init();
	for(auto cur:indx) {
		vis[cur]=1;
		for(auto to:g[cur]) {
			if(!vis[to]) {
				continue;
			}
			deg[cur]++;
			dd.merge(cur,to);
		}
//		cout<<(dd.getfa(cur))<<" "<<(dd.siz[dd.getfa(cur)])<<" "<<deg[cur]<<endl;
		ans=max(ans,(dd.siz[dd.getfa(cur)]*deg[cur]));
	}
	cout<<ans<<endl;
	return 0;
}