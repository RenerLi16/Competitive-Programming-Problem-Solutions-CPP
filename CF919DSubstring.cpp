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
const int maxn=3e5+10;


int dist[maxn][30],deg[maxn],vis[maxn],N,M,ans;
char S[maxn];
vi mp[maxn];

void TopologicalExpansion() {
	queue<int> q;
	for(int i=1;i<=N;i++) {
		if(deg[i]==0) {
			q.push(i);
			dist[i][(int)(S[i]-'A')]=1;
		}
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v:mp[u]) {
			if(vis[v]==1) {
				cout<<(-1)<<endl;
				exit(0);
			}
			deg[v]--;
			dist[v][(int)(S[v]-'A')]++;
			if(deg[v]==0) {
				vis[v]=1;
				q.push(v);
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	cin>>(S+1);
	for(int i=1;i<=M;i++) {
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		deg[v]++;
	}
	TopologicalExpansion();
	for(int i=1;i<=N;i++) {
		for(int j=0;j<26;j++) {
			ans=max(ans,dist[i][j]);
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