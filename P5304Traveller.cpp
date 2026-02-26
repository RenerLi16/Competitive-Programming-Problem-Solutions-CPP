#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define int long long
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
const int maxn=1e5+10;
const int maxe=5e5+10;

vii mp[maxn*3];
int V[maxn],vis[maxn*2],dist[maxn*2],N,M,K,ans;

void Dijkstra(int src) {
	//init
	fill(dist,(dist+(maxn*2)),INF);
	memset(vis,0,sizeof(vis));
	//stuff
	priority_queue<pii,vii,greater<pii>> pq;
	dist[src]=0;
	pq.push({0,src});
	while(!pq.empty()) {
		auto [curdist,u]=pq.top();
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

void init1(int x) {
	mp[0].clear();
	mp[N+K*2].clear();
	for(int i=(N+1);i<=(N+K*2);i++) {
		mp[i].clear();
	}
	for(int i=1;i<=K;i++) {
		if(i&x) {
			mp[0].push_back({N+i,0});
			mp[N+i].push_back({V[i],0});
		} else {
			mp[N+K+i].push_back({N+K*2+1,0});
			mp[V[i]].push_back({N+K+i,0});
		}
	}
}

void init2(int x) {
	mp[0].clear();
	mp[N+K*2].clear();
	for(int i=(N+1);i<=(N+K*2);i++) {
		mp[i].clear();
	}
	for(int i=1;i<=K;i++) {
		if(i&x) {
			mp[N+K+i].push_back({N+K*2+1,0});
			mp[V[i]].push_back({N+K+i,0});
		} else {
			mp[0].push_back({N+i,0});
			mp[N+i].push_back({V[i],0});
		}
	}
}

void solve() {
	// Initiallize
	ans=INF;
	for(int i=0;i<(3*maxn);i++) {
		mp[i].clear();
	}
	// No fluff real stuff
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[uu].push_back({vv,ww});
	}
	for(int i=1;i<=K;i++) {
		cin>>V[i];
	}
	for(int i=0;(1<<i)<=K;i++) {
		init1((1<<i));
		Dijkstra(0);
		ans=min(ans,dist[N+K*2+1]);
		init2((1<<i));
		Dijkstra(0);
		ans=min(ans,dist[N+K*2+1]);
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TT=1;
	cin>>TT;
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}