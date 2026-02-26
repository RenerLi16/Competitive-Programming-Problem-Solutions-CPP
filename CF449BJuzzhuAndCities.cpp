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
const int maxn=3e5+10;

vii mp[maxn];
int dist[maxn],vis[maxn],S[maxn],N,M,K,ans;

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

bool cmp(pii first,pii second) {
	return first.second<second.second;
}

void solve() {
	// Initiallize
	memset(S,0x3f,sizeof(S));
	// No fluff real stuff
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[uu].push_back({vv,ww});
		mp[vv].push_back({uu,ww});
	}
	for(int i=1;i<=K;i++) {
		int ss,yy;
		cin>>ss>>yy;
		if(S[ss]!=0x3f3f3f3f) {
			ans++;
		}
		S[ss]=min(yy,S[ss]);
	}
	debugarr(S,N);
	for(int i=1;i<=N;i++) {
		if(S[i]!=0x3f3f3f3f) {
			mp[1].push_back({i,S[i]});
//			mp[i].push_back({1,S[i]});
		}
	}/*
	for(int i=1;i<=N;i++) {
		sort(mp[i].begin(),mp[i].end(),cmp);
	}*/
	Dijkstra(1);
	debugarr(dist,N);
	for(int i=2;i<=N;i++) {
		int u=i;
		for(auto [v,w]:mp[u]) {
			if(dist[u]==(dist[v]+w) && S[u]!=0x3f3f3f3f) {
//				debug(u)
//				debug(v)
				ans++;
				break;
			}
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