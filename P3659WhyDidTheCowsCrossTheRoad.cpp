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
const int maxn=105;

vii mp[maxn*maxn*3];
int A[maxn*maxn],dist[maxn*maxn*3],vis[maxn*maxn*3],N,T,ans;

void Dijkstra(int src) {
	//init
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	//stuff
	priority_queue<pii,vii,greater<pii>> pq;
	dist[src]=0;
	pq.push({0,src});
	while(!pq.empty()) {
		auto [distcur,u]=pq.top();
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

int GoH(int x,int y,int layr) {
	return ((x-1)*N+y+(N*N*(layr-1)));
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>T;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>A[GoH(i,j,1)];
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(i<N) {
				mp[GoH(i,j,1)].push_back({GoH(i+1,j,2),T});
				mp[GoH(i,j,2)].push_back({GoH(i+1,j,3),(T+A[GoH(i+1,j,1)])});
				mp[GoH(i,j,3)].push_back({GoH(i+1,j,1),T});
			}
			if(i>1) {
				mp[GoH(i,j,1)].push_back({GoH(i-1,j,2),T});
				mp[GoH(i,j,2)].push_back({GoH(i-1,j,3),(T+A[GoH(i-1,j,1)])});
				mp[GoH(i,j,3)].push_back({GoH(i-1,j,1),T});
			}
			if(j<N) {
				mp[GoH(i,j,1)].push_back({GoH(i,j+1,2),T});
				mp[GoH(i,j,2)].push_back({GoH(i,j+1,3),(T+A[GoH(i,j+1,1)])});
				mp[GoH(i,j,3)].push_back({GoH(i,j+1,1),T});
			}
			if(j>1) {
				mp[GoH(i,j,1)].push_back({GoH(i,j-1,2),T});
				mp[GoH(i,j,2)].push_back({GoH(i,j-1,3),(T+A[GoH(i,j-1,1)])});
				mp[GoH(i,j,3)].push_back({GoH(i,j-1,1),T});
			}
		}
	}
	Dijkstra(GoH(1,1,3));
//	for(int i=1;i<=N;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<dist[GoH(i,j,1)]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=N;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<dist[GoH(i,j,2)]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=N;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<dist[GoH(i,j,3)]<<" ";
//		}
//		cout<<endl;
//	}
	ans=min(dist[GoH(N,N,1)],min(dist[GoH(N,N,2)],dist[GoH(N,N,3)]));
	cout<<ans<<endl;
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