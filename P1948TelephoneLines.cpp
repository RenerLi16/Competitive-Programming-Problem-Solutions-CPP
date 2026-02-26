#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define int long long
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
const int maxn=1005;
const int maxp=1e4+10;


vii mp[maxn];
int dist[maxn],vis[maxn],N,P,K,ans;

void BFS01(int src,int bnd) {
	//init
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	//stuff
	deque<int> dq;
	dq.clear();
	dist[src]=0;
	dq.push_back(src);
	while(!dq.empty()) {
		int u=dq.front();
		dq.pop_front();
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(auto [v,w]:mp[u]) {
			int wcur=w;
			if(wcur<=bnd) {
				wcur=0;
			} else {
				wcur=1;
			}
			if(dist[v]>(dist[u]+wcur)) {
				dist[v]=(dist[u]+wcur);
				if(wcur==0) {
					dq.push_front(v);
				} else {
					dq.push_back(v);
				}
			}
		}
	}
}

bool Check(int lb) {
	BFS01(1,lb);
//	cout<<lb<<" "<<dist[N]<<endl;
	if(dist[N]<=K) {
		return true;
	} else {
		return false;
	}
}

int BiSearch() {
	bool flag=false;
	int l=0,r=1e6;
	while(l<=r) {
		int mid=((l+r)/2);
		if(Check(mid)) {
			flag=true;
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	if(!flag) {
		return -1;
	}
	return l;
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>P>>K;
	for(int i=1;i<=P;i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		mp[uu].push_back({vv,ww});
		mp[vv].push_back({uu,ww});
	}
	ans=BiSearch();
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