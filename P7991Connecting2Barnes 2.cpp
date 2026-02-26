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
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;

struct DSU {
	int fa[maxn],tot;
	void init() {
		for(int i=1;i<=tot;i++) {
			fa[i]=i;
		}
	}
	int getfa(int x) {
		return (fa[x]==x ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x,int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		fa[xfa]=yfa;
	}
} dd;

vi pool[maxn];
int srcdist[maxn],drndist[maxn],N,M,ans;

void solve() {
	// Initiallize
	ans=INF;
	// No fluff real stuff
	cin>>N>>M;
	dd.tot=N;
//	cout<<sqsq(-26)<<endl;
	dd.init();
	for(int i=1;i<=N;i++) {
		pool[i].clear();
		srcdist[i]=0x3f3f3f3f3f3f3f3f;
		drndist[i]=0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
		dd.merge(uu,vv);
	}
	for(int i=1;i<=N;i++) {
		pool[dd.getfa(i)].push_back(i);
	}
	for(int i=1;i<=N;i++) {
		sort(all(pool[i]));
	}
	int srcfa=dd.getfa(1),drnfa=dd.getfa(N);
	for(int i=1;i<=N;i++) {
		int pos=lower_bound(all(pool[srcfa]),i)-pool[srcfa].begin();
		if(pos!=pool[srcfa].size()) {
			srcdist[dd.getfa(i)]=min(srcdist[dd.getfa(i)],sqsq(pool[srcfa][pos]-i));
		}
		if(pos!=0) {
			srcdist[dd.getfa(i)]=min(srcdist[dd.getfa(i)],sqsq(pool[srcfa][pos-1]-i));
		}
	}
	for(int i=1;i<=N;i++) {
		int pos=lower_bound(all(pool[drnfa]),i)-pool[drnfa].begin();
		if(pos!=pool[drnfa].size()) {
			drndist[dd.getfa(i)]=min(drndist[dd.getfa(i)],sqsq(pool[drnfa][pos]-i));
		}
		if(pos!=0) {
			drndist[dd.getfa(i)]=min(drndist[dd.getfa(i)],sqsq(pool[drnfa][pos-1]-i));
		}
		
	}
	for(int i=1;i<=N;i++) {
		ans=min(ans,(srcdist[i]+drndist[i]));
	}
	cout<<ans<<endl;
	return;
	
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