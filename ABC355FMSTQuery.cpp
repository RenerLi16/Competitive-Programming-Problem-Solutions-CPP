#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
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
const int maxn=2e5+10;
const int maxval=15;

struct DSU {
	int fa[maxn],tot;
	void init() {
		for(int i=1;i<=tot;i++) {
			fa[i]=i;
		}
	}
	int getfa(int x) {
		return (fa[x]==x ? x:(fa[x]=getfa(fa[x])));
	}
	void merge(int x,int y) {
		fa[x]=y;
	}
} dd[maxval];

int N,Q,ans;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>Q;
	ans=(10*(N-1));
	for(int i=1;i<10;i++) {
		dd[i].tot=N;
		dd[i].init();
	}
	for(int i=1;i<(N+Q);i++) {
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		for(int j=ww;j<10;j++) {
			int ufa=dd[j].getfa(uu),vfa=dd[j].getfa(vv);
			if(ufa==vfa) {
				break;
			}
			dd[j].merge(ufa,vfa);
			ans--;
		}
		if(i>=N && i<=(N+Q)) {
			cout<<ans<<endl;
		}
	}
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