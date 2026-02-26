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
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

struct Edge{
	int v,s,r;
	friend bool operator <(Edge first, Edge second) {
		return first.s>second.s;
	}
};

int A[maxn],tag[maxn],vis[maxn],dist[maxn],N,M;
vector<Edge> mp[maxn];

queue<int> q;
void SPFA(int src) {
	memset(dist,0x3f,sizeof(dist));
	q.push(src);
	dist[src]=0;
	vis[src]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(;tag[u]<mp[u].size() && mp[u][tag[u]].s>=(dist[u]+A[u]);tag[u]++) {
			int v=mp[u][tag[u]].v;
			int r=mp[u][tag[u]].r;
			if(dist[v]>r) {
				dist[v]=r;
				if(!vis[v]) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,ss,vv,rr;
		cin>>uu>>ss>>vv>>rr;
		mp[uu].push_back({vv,ss,rr});
	}
	for(int i=1;i<=N;i++) {
		cin>>A[i];
		sort(mp[i].begin(),mp[i].end());
	}
	A[1]=0;
	SPFA(1);
	for(int i=1;i<=N;i++) {
		if(dist[i]==0x3f3f3f3f) {
			dist[i]=-1;
		}
		cout<<dist[i]<<endl;
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