#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e4+10;

vii mp[maxn];
int dist[maxn],vis[maxn],A[maxn],fa[maxn],siz[maxn],N,M,T,ans=0;

void Dijkstra(int src) {
	priority_queue<pii,vii,greater<pii>> pq;
	dist[src]=0;
	pq.push({dist[src],src});
	while(!pq.empty()) {
		auto [l,u]=pq.top();
		pq.pop();
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(auto [v,w]:mp[u]) {
			if(dist[v]>(dist[u]+w)) {
				dist[v]=(dist[u]+w);
				pq.push({dist[v],v});
			}
		}
	}
}

void DFS(int u,int from) {
	siz[u]=A[u];
	for(auto [v,w]:mp[u]) {
		if(fa[v]==u && !vis[v]) {
			vis[v]=1;
			DFS(v,u);
			siz[u]+=siz[v];
		}
	}
}

void solve() {
	// Initiallize
	memset(dist,0x3f,sizeof(dist));
	// No fluff real stuff
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
	}
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[uu].push_back({vv,ww});
		mp[vv].push_back({uu,ww});
	}
	Dijkstra(1);
	memset(fa,0x3f,sizeof(fa));
	for(int i=1;i<=N;i++) {
		int u=i;
		for(auto [v,w]:mp[u]) {
			if(dist[v]==(dist[u]-w)) {
				fa[u]=min(fa[u],v);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	DFS(1,-1);
//	for(int i=1;i<=N;i++) {
//		cout<<siz[i]<<endl;
//	}
	for(int i=1;i<=N;i++) {
		ans=max(ans,((dist[i]-T)*siz[i]));
	}
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