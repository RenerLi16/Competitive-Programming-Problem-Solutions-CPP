#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=5e5+10;

struct DSU {
	int fa[maxn],siz;
	void init() {
		for(int i=1;i<=siz;i++) {
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
}dd;

int distl[maxn],distr[maxn],N,M,ans;
vi grup[maxn];

void solve() {
	// Initiallize
	fill(distl,distl+maxn,INF);
	fill(distr,distr+maxn,INF);
	for(int i=0;i<maxn;i++) {
		grup[i].clear();
	}
	ans=INF;
	// No fluff real stuff
	cin>>N>>M;
	dd.siz=N;
	dd.init();
	for(int i=1;i<=M;i++) {
		int uu,vv;
		cin>>uu>>vv;
		dd.merge(uu,vv);
	}
	for(int i=1;i<=N;i++) {
		grup[dd.getfa(i)].push_back(i);
	}
	for(int i=1;i<=N;i++) {
		sort(grup[i].begin(),grup[i].end());
	}
	int lfa=dd.getfa(1),rfa=dd.getfa(N);
	for(int i=1;i<=N;i++) {
		int pos=lower_bound(grup[lfa].begin(),grup[lfa].end(),i)-grup[lfa].begin();
		distl[dd.getfa(i)]=min(distl[dd.getfa(i)],min((pos==grup[lfa].size() ? INF : abs(i-grup[lfa][pos])),abs(i-grup[lfa][max(pos-1,0LL)])));
		pos=lower_bound(grup[rfa].begin(),grup[rfa].end(),i)-grup[rfa].begin();
		distr[dd.getfa(i)]=min(distr[dd.getfa(i)],min((pos==grup[rfa].size() ? INF : abs(i-grup[rfa][pos])),abs(i-grup[rfa][max(pos-1,0LL)])));
	}
	for(int i=1;i<=N;i++) {
		ans=min(ans,((distl[i]*distl[i])+(distr[i]*distr[i])));
	}
	cout<<ans<<endl;
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