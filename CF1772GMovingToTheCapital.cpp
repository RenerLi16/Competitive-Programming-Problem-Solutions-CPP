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
const int maxn=2e5+10;

vi mp[maxn*2];
int d[maxn*2],vis[maxn*2],ans[maxn*2],N,M;
pii pool[maxn],val[maxn];

void BFSGetDistance(int src) {
	//init
	//stuff
	queue<int> q;
	q.push(src);
	d[src]=0;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(int v:mp[u]) {
			if(d[v]>(d[u]+1)) {
				d[v]=(d[u]+1);
				q.push(v);
			}
		}
	}
}

void BFSGetAnswer(int src,int x) {
	//init
	//stuff
	if(vis[src]) {
		return;
	}
	queue<int> q;
	q.push(src);
	ans[src]=x;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(int v:mp[u]) {
			if(ans[v]>x) {
				ans[v]=x;
				q.push(v);
			}
		}
	}
}

int GoH(int x,int layr) {
	return (x+(layr-1)*N);
}

void solve() {
	// Initiallize
//	memset(pool,0,sizeof(pool));
	// No fluff real stuff
	cin>>N>>M;
	memset(d,0x3f,(4*(N*2+1)));
	memset(ans,0x3f,(4*(N*2+1)));
	cerr<<sizeof(ans)<<endl;
	for(int i=1;i<=(N*2);i++) {
		mp[i].clear();
	}
	memset(d,0x3f,(4*(N*2+1)));
	memset(vis,0,(4*(N*2+1)));
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
		mp[uu].push_back(vv);
		pool[i]={uu,vv};
	}
	BFSGetDistance(1);
	for(int i=1;i<=N;i++) {
		mp[i].clear();
	}
	for(int i=1;i<=M;i++) {
		int u=pool[i].first,v=pool[i].second;
		if(d[u]<d[v]) {
			mp[GoH(v,1)].push_back(GoH(u,1));
			mp[GoH(v,2)].push_back(GoH(u,2));
		} else {
			mp[GoH(v,2)].push_back(GoH(u,1));
		}
	}
//	debugarr(d,N);
	for(int i=1;i<=N;i++) {
		val[i]={d[i],i};
	}
	sort(val+1,val+N+1);
	memset(vis,0,(4*(N*2+1)));
	for(int i=1;i<=N;i++) {
		BFSGetAnswer(GoH(val[i].second,2),val[i].first);
	}
//	for(int i=1;i<=N;i++) {
//		cout<<ans[i+N]<<endl;
//	}
	for(int i=1;i<=N;i++) {
		cout<<(min(ans[GoH(i,1)],ans[GoH(i,2)]))<<" ";
	}
	cout<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TT=1;
	cin>>TT;
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}