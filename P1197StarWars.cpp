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

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=4e5+10;
const int maxedge=2e5+10;

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

int C[maxn],vis[maxn],N,M,K,cntr,ans[maxn];
si chosen;
pii pool[maxedge*2];

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>pool[i].first>>pool[i].second;
		pool[i+M]={pool[i].second,pool[i].first};
	}
	cin>>K;
	for(int i=1;i<=K;i++) {
		cin>>C[i];
		chosen.insert(C[i]);
	}
	dd.siz=N;
	dd.init();
	sort(pool+1,pool+M*2+1);
	cntr=N;
	for(int i=1;i<=2*M;i++) {
		if(chosen.count(pool[i].first)==0 && chosen.count(pool[i].second)==0) {
			if(dd.getfa(pool[i].first)!=dd.getfa(pool[i].second)) {
				cntr--;
				dd.merge(pool[i].first,pool[i].second);
			}
		}
	}
	cntr-=K;
	ans[K]=cntr;
	for(int i=K;i>=1;i--) {
		cntr++;
		pii ltmp={C[i],0},rtmp={C[i],4e5+5};
		int lpos=lower_bound(pool+1,pool+M*2+1,ltmp)-pool,rpos=lower_bound(pool+1,pool+M*2+1,rtmp)-pool-1;
		for(int j=lpos;j<=rpos;j++) {
//			cout<<pool[j].first<<" "<<pool[j].second<<endl;
			if(chosen.count(pool[j].second)==0) {
				if(dd.getfa(pool[j].first)!=dd.getfa(pool[j].second)) {
					cntr--;
					vis[pool[j].first]=1;
					dd.merge(pool[j].first,pool[j].second);
				}
			}
		}
		ans[i-1]=cntr;
		chosen.erase(C[i]);
	}
	for(int i=0;i<=K;i++) {
		cout<<ans[i]<<endl;
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