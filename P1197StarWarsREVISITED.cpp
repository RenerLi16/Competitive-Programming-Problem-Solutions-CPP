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
const int maxn=4e5+10;
const int maxedge=2e5+10;

struct DSU {
	int fa[maxn*2],tot;
	void init() {
		for(int i=0;i<tot;i++) {
			fa[i]=i;
		}
	}
	int getfa(int x) {
		if(fa[x]==x) {
			return x;
		} else {
			fa[x]=getfa(fa[x]);
			return fa[x];
		}
	}
	void merge(int x,int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		fa[xfa]=yfa;
	}
}dd;

map<int,int> mp;
pii pool[maxedge];
int N,M,K,counterans,ans[maxn];

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	dd.tot=(N*2);
	dd.init();
	for(int i=1;i<=M;i++) {
		cin>>pool[i].first>>pool[i].second;
	}
	cin>>K;
	for(int i=1;i<=K;i++) {
		int target;
		cin>>target;
		mp[target]=(N+K-i+1);
	}
	for(int i=0;i<N;i++) {
		if(mp[i]==0) {
			mp[i]=i;
		}
	}
	for(int i=1;i<=M;i++) {
		pool[i]={mp[pool[i].first],mp[pool[i].second]};
		if(pool[i].second>pool[i].first) {
			swap(pool[i].first,pool[i].second);
		}
	}
	counterans=(N-K);
	sort(pool+1,pool+M+1);
//	for(int i=1;i<=M;i++) {
//		cout<<pool[i].first<<" "<<pool[i].second<<endl;
//	}
	ans[1]=counterans;
	for(int i=1;i<=M;i++) {
		int ufa=dd.getfa(pool[i].first),vfa=dd.getfa(pool[i].second);
		if(ufa!=vfa) {
			dd.merge(pool[i].first,pool[i].second);
			counterans--;
		}
		if(pool[i].first!=pool[i+1].first && pool[i].first>=N) {
			counterans++;
			ans[pool[i].first-N+1]=counterans;
		}
	}
	cout<<ans[K+1]<<endl;
	for(int i=K;i>=1;i--) {
		cout<<ans[i]<<endl;
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