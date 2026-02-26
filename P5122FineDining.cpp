#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define int long long
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e4+10;

vii mp[maxn*2];
int dist[maxn*2],vis[maxn*2],N,M,K;
pii brn[maxn*2];

int GoH(int x,int layr) {
	return ((layr-1)*N+x);
}

void Dijkstra1(int src) {
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

void Dijkstra2(int nousesrc) {
	priority_queue<pii,vii,greater<pii>> pq;
	for(int i=1;i<=K;i++) {
		dist[GoH(brn[i].first,2)]=dist[GoH(brn[i].first,1)]-brn[i].second;
		pq.push({dist[GoH(brn[i].first,2)],GoH(brn[i].first,2)});
	}
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

void solve() {
	// Initiallize
	memset(dist,0x3f,sizeof(dist));
	// No fluff real stuff
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[GoH(uu,1)].push_back({GoH(vv,1),ww});
		mp[GoH(vv,1)].push_back({GoH(uu,1),ww});
		mp[GoH(uu,2)].push_back({GoH(vv,2),ww});
		mp[GoH(vv,2)].push_back({GoH(uu,2),ww});
	}
	for(int i=1;i<=K;i++) {
		cin>>brn[i].first>>brn[i].second;
	}
	Dijkstra1(GoH(N,1));
	Dijkstra2(GoH(N,2));
	debugarr(dist,N*2)
	for(int i=1;i<N;i++) {
		if(dist[GoH(i,2)]>dist[GoH(i,1)]) {
			cout<<0<<endl;
		} else {
			cout<<1<<endl;
		}
//		cout<<dist[GoH(i,2)]<<endl;
	}
	cout<<endl;
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