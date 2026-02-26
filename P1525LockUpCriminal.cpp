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
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e4+10;
const int maxedge=1e5+10;

struct DSU {
	int fa[maxn*2],siz;
	void init() {
		for(int i=1;i<=siz;i++) {
			fa[i]=i;
		}
	}
	int getfa(int x) {
		return ((fa[x]==x) ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x,int y) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		fa[xfa]=yfa;
	}
} dd;

int N,M;
pair<int,pii> pool[maxedge];

bool cmp(pair<int,pii> first,pair<int,pii> second) {
	return first.first>second.first;
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	dd.siz=N*2;
	dd.init();
	for(int i=1;i<=M;i++) {
		cin>>pool[i].second.first>>pool[i].second.second>>pool[i].first;
	}
	sort(pool+1,pool+M+1,cmp);
	for(int i=1;i<=M;i++) {
		dd.merge(pool[i].second.first,pool[i].second.second+N);
		dd.merge(pool[i].second.first+N,pool[i].second.second);
		if(dd.getfa(pool[i].second.first)==dd.getfa(pool[i].second.first+N)
		|| dd.getfa(pool[i].second.second)==dd.getfa(pool[i].second.second+N)) {
			cout<<pool[i].first<<endl;
			return;
		}
	}
	cout<<0<<endl;
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