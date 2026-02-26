#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int deg[maxn],vis[maxn],TT,N,M;
priority_queue<int> pq;
vector<int> g[maxn],ans;
void Solve() {
	for(int i=0;i<maxn;i++) {
		g[i].clear();
	}
	ans.clear();
	memset(deg,0,sizeof(deg));
	memset(vis,0,sizeof(vis));
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
//		g[uu].push_back(vv);
		g[vv].push_back(uu);
		deg[uu]++;
//		deg[vv]++;
	}
	for(int i=1;i<=N;i++) {
		if(deg[i]==0) {
			pq.push(i);
		}
	}
	while(!pq.empty()) {
		int u=pq.top();
//		cout<<u<<endl;
		pq.pop();
		deg[u]--;
		vis[u]=1;
		ans.push_back(u);
		for(int v:g[u]) {
			deg[v]--;
			if(deg[v]==0) {
				pq.push(v);
			}
		}
	}
	for(int i=1;i<=N;i++) {
		if(vis[i]==0) {
			cout<<"Impossible!"<<endl;
			return;
		}
	}
	reverse(ans.begin(),ans.end());
	for(int cur:ans) {
		cout<<cur<<" ";
	}
	cout<<endl;
	return;
}
int main() {
	cin>>TT;
	for(int i=1;i<=TT;i++) {
		Solve();
	}
	return 0;
}