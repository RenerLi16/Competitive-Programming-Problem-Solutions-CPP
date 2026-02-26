#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=2e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

vii mp[3*maxn];
int dist[3*maxn],vis[3*maxn],N,M,S,T,U,V,ans=INF;

void Dijkstra(int src) {
	for(int i=0;i<(3*maxn);i++) {
		dist[i]=INF;
	}
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vii,greater<pii>> pq;
	dist[src]=0;
	pq.push({dist[src],src});
	while(!pq.empty()) {
		auto [l,u]=pq.top();
		pq.pop();
		if(vis[u]) {
			continue;
		} else {
			vis[u]=1;
			for(auto [v,w]:mp[u]) {
				if(dist[v]>(dist[u]+w)) {
					dist[v]=(dist[u]+w);
					pq.push({dist[v],v});
				}
			}
		}
	}
}

int GoH(int x,int layr) {
	return ((layr-1)*N+x);
}

void DFS(int u) {
	vis[u]=1;
	for(auto [v,w]:mp[u]) {
		if(dist[v]==(dist[u]-w)) {
			mp[GoH(v,2)].push_back({GoH(u,2),0});
			if(vis[v]==0) {
				DFS(v);
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M>>S>>T>>U>>V;
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[GoH(uu,1)].push_back({GoH(vv,1),ww});
		mp[GoH(vv,1)].push_back({GoH(uu,1),ww});
		mp[GoH(uu,3)].push_back({GoH(vv,3),ww});
		mp[GoH(vv,3)].push_back({GoH(uu,3),ww});
	}
	Dijkstra(GoH(S,1));
	memset(vis,0,sizeof(vis));
	DFS(GoH(T,1));
	for(int i=1;i<=N;i++) {
		mp[GoH(i,1)].push_back({GoH(i,2),0});
		mp[GoH(i,2)].push_back({GoH(i,3),0});
	}
	Dijkstra(GoH(U,1));
	ans=min(ans,(min(dist[GoH(V,1)],dist[GoH(V,3)])));
	Dijkstra(GoH(V,1));
	ans=min(ans,(min(dist[GoH(U,1)],dist[GoH(U,3)])));
//	for(int i=1;i<=N;i++) {
//		for(int j=0;j<mp[GoH(i,2)].size();j++) {
//			cout<<mp[GoH(i,2)][j].first<<" "<<mp[GoH(i,2)][j].second<<endl;
//		}
//		cout<<endl;
//	}

	cout<<ans<<endl;
	return;
	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TT=1;
	//cin>>TT;
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}