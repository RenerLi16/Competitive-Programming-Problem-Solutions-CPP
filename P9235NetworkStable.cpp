#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <unordered_set>
using namespace std;

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
const int maxn=1e5+10;
const int maxedge=3e5+10;

int ans[maxn];

struct pair_hash {
  size_t operator()(const pair<int,int> &p) const {
    // a simple but reasonable hash: combine the two hashes
    return std::hash<int>()(p.first) * 0x9e3779b97f4a7c15ULL 
         + (std::hash<int>()(p.second) << 1);
  }
};

struct DSU {
	unordered_set<pii,pair_hash> ncld[maxn];
	int fa[maxn],siz[maxn],tot;
	void init() {
		for(int i=1;i<=tot;i++) {
			fa[i]=i;
			siz[i]=1;
		}
	}
	int getfa(int x) {
		return (fa[x]==x ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x,int y,int w) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		if(siz[xfa]>siz[yfa]) {
			swap(xfa,yfa);
		}
		siz[yfa]+=siz[xfa];
		while(!ncld[xfa].empty()) {
			auto cur=(*ncld[xfa].begin());
			ncld[xfa].erase(ncld[xfa].begin());
			if(getfa(cur.first)==yfa) {
				ans[cur.second]=w;
			} else {
				ncld[yfa].insert(cur);
			}
		}
		fa[xfa]=yfa;
	}
} dd;

struct Edge{
	int u,v,w;
	friend bool operator < (Edge first, Edge second) {
		return first.w>second.w;
	}
} pool[maxedge];

unordered_set<int> target[maxn];
int N,M,Q;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M>>Q;
	dd.tot=N;
	dd.init();
	for(int i=1;i<=M;i++) {
		cin>>pool[i].u>>pool[i].v>>pool[i].w;
	}
	sort(pool+1,pool+M+1);
	for(int i=1;i<=Q;i++) {
		int uu,vv;
		cin>>uu>>vv;
		dd.ncld[uu].insert({vv,i});
		dd.ncld[vv].insert({uu,i});
	}
	for(int i=1;i<=N;i++) {
		dd.merge(pool[i].u,pool[i].v,pool[i].w);
	}
	for(int i=1;i<=Q;++i) {
		if(ans[i]==0) {
			ans[i]=(-1);
		}
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