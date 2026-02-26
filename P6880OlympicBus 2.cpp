#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

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
const int maxn=205;
const int maxm=5e4+10;

struct OlympicBusEdge{
	int to,w,cost;
};
vector<OlympicBusEdge> mp[maxn];
int dist[4][maxn],vis[4][maxn],fa[4][maxn],N,M,ans=0x3f3f3f3f;

void Dijkstra(int src,int layr) {
	for(int i=1;i<=N;i++) {
		dist[layr][i]=0x3f3f3f3f;
		vis[layr][i]=0;
//		fa[layr][i]=-1;
	}
	dist[layr][src]=0;
	for(int i=1;i<=N;i++) {
		int u=0;
		for(int j=1;j<=N;j++) {
			if(!vis[layr][j] && (u==0 || dist[layr][u]>dist[layr][j])) {
				u=j;
			}
		}
		vis[layr][u]=1;
		for(auto [v,w,nusw]:mp[u]) {
			if(v==0) {
				continue;
			}
			if(dist[layr][v]>(dist[layr][u]+w)) {
				dist[layr][v]=(dist[layr][u]+w);
				fa[layr][v]=u;
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv,cc,dd;
		cin>>uu>>vv>>cc>>dd;
		mp[uu].push_back({vv,cc,dd});
	}
	Dijkstra(1,0);
	Dijkstra(N,1);
	debugarr(dist[0],N);
	debugarr(dist[1],N);
	ans=(dist[0][N]+dist[1][1]);
	for(int i=1;i<=N;i++) {
		for(auto &[v,w,cost]:mp[i]) {
			if(!(fa[0][v]!=i && fa[1][v]!=i)) {
				continue;
			}
			int tmpv=v,tmpw=w;
			mp[v].push_back({i,w,cost});
			v=0;
			w=0x3f3f3f3f;
			Dijkstra(1,2);
			Dijkstra(N,3);
			ans=cost+min(ans,(min(dist[0][N],(dist[2][N]))+min(dist[1][1],(dist[3][1]))));
			v=tmpv;
			w=tmpw;
			mp[v].pop_back();
		}
	}
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