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

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=205;
const int maxedge=5e4+10;

struct Node {
	int to,w,id;
};
vector<Node> mp[2][maxn];
int dist[3][maxn],fa[maxn],vis[maxn],f[maxedge],U[maxedge],V[maxedge],C[maxedge],D[maxedge],N,M,ans[maxedge],anstot;

void Dijkstra(int p,int src,int drn,int dist[],int opt=0) {
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;i++) {
		dist[i]=0x3f3f3f3f3f3f3f3f;
	}
	if(!p && !opt) {
		memset(f,0,sizeof(f));
	}
	dist[src]=0;
	fa[src]=0;
	for(int i=1;i<=N;i++) {
		int mn=0x3f3f3f3f3f3f3f3f,u=0;
		for(int j=1;j<=N;j++) {
			if(!vis[j] && dist[j]<mn) {
				mn=dist[j];
				u=j;
			}
		}
		vis[u]=1;
		if(p==0 && V[opt]==u && dist[U[opt]]>(dist[u]+C[opt])) {
			dist[U[opt]]=(dist[u]+C[opt]);
		}
		if(p==1 && U[opt]==u && dist[V[opt]]>(dist[u]+C[opt])) {
			dist[V[opt]]=(dist[u]+C[opt]);
		}
		for(auto [v,w,id]:mp[p][u]) {
			if(id!=opt && dist[v]>(dist[u]+w)) {
				dist[v]=(dist[u]+w);
				if(!p && !opt) {
					fa[v]=id;
				}
			}
		}
	}
	if(!p && !opt) {
		for(int i=1;i<=N;i++) {
			f[fa[i]]=1;
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>U[i]>>V[i]>>C[i]>>D[i];
		mp[0][U[i]].push_back({V[i],C[i],i});
		mp[1][V[i]].push_back({U[i],C[i],i});
	}
	Dijkstra(0,1,N,dist[0]);
	Dijkstra(1,N,1,dist[1]);
	anstot=dist[0][N];
	for(int i=1;i<=M;i++) {
		if(f[i]) {
			Dijkstra(0,1,N,dist[2],i);
			ans[i]=dist[2][N];
		} else {
			ans[i]=(min(dist[0][N],(dist[0][V[i]]+dist[1][U[i]]+C[i])));
		}
	}
	Dijkstra(0,N,1,dist[0]);
	Dijkstra(1,1,N,dist[1]);
	anstot+=(dist[0][1]);
	for(int i=1;i<=M;i++) {
		if(f[i]) {
			Dijkstra(0,N,1,dist[2],i);
			ans[i]+=(dist[2][1]+D[i]);
		} else {
			ans[i]+=(min(dist[0][1],(dist[0][V[i]]+dist[1][U[i]]+C[i]))+D[i]);
		}
		anstot=min(anstot,ans[i]);
	}
	cout<<(anstot>=0x3f3f3f3f3f3f3f3f ? -1 : anstot)<<endl;
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