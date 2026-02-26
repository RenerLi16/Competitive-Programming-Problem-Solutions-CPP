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
const int maxn=1e5+10;

vii mp[maxn];
int A[maxn],dist[maxn],vis[maxn],N,M,K,ans;

void Dijkstra(int noiussrc) {
	priority_queue<pii,vii,greater<pii>> pq;
	for(int i=1;i<=K;i++) {
		dist[A[i]]=0;
		pq.push({dist[A[i]],A[i]});
		vis[A[i]]=1;
	}
	while(!pq.empty()) {
		auto [l,u]=pq.top();
		pq.pop();
		vis[u]++;
		if(vis[u]!=2) {
			continue;
		}
		dist[u]=l;
		for(auto [v,w]:mp[u]) {
			if(dist[v]>(dist[u]+w)) {
				pq.push({(dist[u]+w),v});
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
		mp[uu].push_back({vv,ww});
		mp[vv].push_back({uu,ww});
	}
	for(int i=1;i<=K;i++) {
		cin>>A[i];
	}
	Dijkstra(N);
	ans=dist[0];
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