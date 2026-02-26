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

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

vii mp[maxn*4];
int dist[maxn*4],vis[maxn*4],N,M,ans;

void Dijkstra(int src) {
	//init
	memset(dist,0x3f,sizeof(dist));
	//stuff
	priority_queue<pii,vii,greater<pii>> pq;
	pq.push({0,src});
	dist[src]=0;
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

int GoH(int x,int layr) {
	return (x+(layr-1)*N);
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[GoH(uu,1)].push_back({GoH(vv,1),ww});
		mp[GoH(uu,2)].push_back({GoH(vv,2),ww});
		mp[GoH(uu,3)].push_back({GoH(vv,3),ww});
		mp[GoH(uu,4)].push_back({GoH(vv,4),ww});
		mp[GoH(uu,1)].push_back({GoH(vv,2),0});
		mp[GoH(uu,2)].push_back({GoH(vv,4),(ww*2)});
		mp[GoH(uu,1)].push_back({GoH(vv,3),(ww*2)});
		mp[GoH(uu,3)].push_back({GoH(vv,4),0});
		mp[GoH(uu,1)].push_back({GoH(vv,4),ww});
		mp[GoH(vv,1)].push_back({GoH(uu,1),ww});
		mp[GoH(vv,2)].push_back({GoH(uu,2),ww});
		mp[GoH(vv,3)].push_back({GoH(uu,3),ww});
		mp[GoH(vv,4)].push_back({GoH(uu,4),ww});
		mp[GoH(vv,1)].push_back({GoH(uu,2),0});
		mp[GoH(vv,2)].push_back({GoH(uu,4),(ww*2)});
		mp[GoH(vv,1)].push_back({GoH(uu,3),(ww*2)});
		mp[GoH(vv,3)].push_back({GoH(uu,4),0});
		mp[GoH(vv,1)].push_back({GoH(uu,4),ww});
	}
	Dijkstra(1);
//	for(int i=1;i<=N;i++) {
//		cout<<dist[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=N;i++) {
//		cout<<dist[i+N]<<" ";
//	}
//	cout<<endl;
//	for(int j=1;j<=4;j++) {
//		for(int i=1;i<=N;i++) {
//			cout<<dist[GoH(i,j)]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=2;i<=N;i++) {
		ans=dist[GoH(i,4)];
		cout<<ans<<" ";
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