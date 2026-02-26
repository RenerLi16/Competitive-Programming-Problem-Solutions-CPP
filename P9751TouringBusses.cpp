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
const int maxn=1e4+10;
const int maxrmn=105;

vii mp[maxn];
int dist[maxn][maxrmn],vis[maxn][maxrmn],N,M,K,ans;

void Dijkstra(pii src) {
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
	dist[src.first][src.second]=0;
	pq.push({0,src});
	while(!pq.empty()) {
		auto [l,tmppii]=pq.top();
		int u=tmppii.first,rmncur=tmppii.second;
		pq.pop();
		if(vis[u][rmncur]) {
			continue;
		}
		vis[u][rmncur]=1;
		for(auto [v,lim]:mp[u]) {
			if(lim>dist[u][rmncur]) {
				int tmp=(dist[u][rmncur]+(lim-dist[u][rmncur]+K-1)/K*K+1);
				if(dist[v][(rmncur+1)%K]>tmp) {
					dist[v][(rmncur+1)%K]=tmp;
					pq.push({dist[v][(rmncur+1)%K],{v,(rmncur+1)%K}});
				}
			} else {
				if(dist[v][(rmncur+1)%K]>(dist[u][rmncur]+1)) {
					dist[v][(rmncur+1)%K]=(dist[u][rmncur]+1);
					pq.push({dist[v][(rmncur+1)%K],{v,((rmncur+1)%K)}});
				}
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
		int uu,vv,aa;
		cin>>uu>>vv>>aa;
		mp[uu].push_back({vv,aa});
	}
	Dijkstra({1,0});
//	for(int i=0;i<K;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<dist[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	ans=(dist[N][0]+K-1)/K*K;
	if(ans>=0x3f3f3f3f) {
		ans=-1;
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