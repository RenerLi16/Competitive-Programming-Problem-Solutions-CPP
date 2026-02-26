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
const int maxm=5e4+10;


int deg[maxn],vis[maxn],N,M;
vi req[maxm],mp[maxn],ans,curseq;

bool TopologicalExpansion() {
	memset(vis,0,sizeof(vis));
	curseq.clear();
	priority_queue<int,vi,greater<int>> pq;
	for(int i=1;i<=N;i++) {
		if(deg[i]==0) {
			pq.push(i);
			vis[i]=1;
		}
	}
	while(!pq.empty()) {
		int u=pq.top();
		pq.pop();
		curseq.pb(u);
		for(int v:mp[u]) {
			if(vis[v]==1) {
				return false;
			}
			deg[v]--;
			if(deg[v]==0) {
				vis[v]=1;
				pq.push(v);
			}
		}
	}
	return true;
}

bool Check(int bound) {
	memset(deg,0,sizeof(deg));
	for(int i=1;i<=N;i++) {
		mp[i].clear();
	}
	for(int i=1;i<=bound;i++) {
		for(int j=1;j<(req[i].size());j++) {
			mp[req[i][j-1]].pb(req[i][j]);
			deg[req[i][j]]++;
		}
	}
	if(TopologicalExpansion()==false) {
		return false;
	}
	for(int i=1;i<=N;i++) {
		if(vis[i]==0) {
			return false;
		}
	}
	ans.clear();
	for(auto it:curseq) {
		ans.pb(it);
	}
	return true;
}

void BiSearch() {
	int l=0,r=M;
	while(l<=r) {
		int mid=((l+r)/2);
		if(Check(mid)) {
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	Check(r);
	debug(r)
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int mm;
		cin>>mm;
		for(int j=1;j<=mm;j++) {
			int xx;
			cin>>xx;
			req[i].pb(xx);
		}
	}
	BiSearch();
	for(auto it:ans) {
		cout<<it<<" ";
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