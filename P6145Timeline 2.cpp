#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

//#define int long long
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

int dist[maxn],deg[maxn],N,M,C;
vii mp[maxn];

void TopologicalExpansion() {
	queue<pii> q;
	memset(dist,-0x3f,sizeof(dist));
	q.push({0,0});
	while(!q.empty()) {
		auto [curlen,u]=q.front();
		q.pop();
		for(auto [v,w]: mp[u]) {
			deg[v]--;
			dist[v]=max(dist[v],curlen+w);
			if(deg[v]==0) {
				q.push({dist[v],v});
			}
		}
	}
}

void Dijkstra() {
	priority_queue<pii, vector<pii>, less<pii>  > pq;
	memset(dist,-0x3f,sizeof(dist));
	pq.push({0,0});
//	vis[0]=1;
	while(!pq.empty()) {
		auto [curlen,u]=pq.top();
		debug(curlen);
		debug(u);
		pq.pop();
		for(auto [v,w]:mp[u]) {
			if(dist[v]<(curlen+w)) {
				dist[v]=curlen+w;
				pq.push({dist[v],v});
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M>>C;
	for(int i=1;i<=N;i++) {
		int x;
		cin>>x;
		mp[0].push_back({i,x});
		deg[i]++;
	}
	for(int i=1;i<=C;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		deg[v]++;
	}
	TopologicalExpansion();
	cout<<dist[1];
	for(int i=2;i<=N;i++) {
		cout<<endl<<dist[i];
	}
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