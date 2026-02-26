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
const int maxn=2005;

vi mp[maxn],pool;
int dist[maxn][maxn],C[maxn],A[maxn],N,ans;

void BFS(int src) {
	queue<int> q;
	dist[src][src]=0;
	q.push(src);
	while(!q.empty()) {
//		cout<<(q.front())<<endl;
		int u=q.front();
		q.pop();
		for(int v:mp[u]) {
			if(dist[src][v]>(dist[src][u]+1)) {
				dist[src][v]=(dist[src][u]+1);
				q.push(v);
			}
		}
	}
}

void solve() {
	// Initiallize
	memset(dist,0x3f,sizeof(dist));
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>C[i];
		for(int j=(i-1);j>=(i-C[i]);j--) {
			mp[j].push_back(i);
		}
	}
	for(int i=1;i<N;i++) {
		cin>>A[i];
		if(A[i]==1) {
			pool.push_back(i);
		}
	}
	for(int i=0;i<N;i++) {
		BFS(i);
//		for(int j=0;j<N;j++) {
//			cout<<dist[i][j]<<" ";
//		}
//		cout<<endl;
	}
	for(int v:pool) {
		int valcur=dist[0][v];
		for(int u:pool) {
			if(u>=v) {
				break;
			}
//			cout<<u<<" "<<v<<" "<<dist[u][v]<<endl;
			valcur=min(valcur,(dist[u][v]));
		}
		debug(valcur)
		ans+=valcur;
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