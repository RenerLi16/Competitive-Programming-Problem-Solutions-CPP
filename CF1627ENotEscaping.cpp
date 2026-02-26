#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

struct Node {
	int y1,x2,y2,h;
	ll dist;
	friend bool operator <(Node first, Node second) {
		return first.y1<second.y1;
	}
};

vector<Node> mp[maxn];
ll X[maxn],ans;
int N,M,K;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++) {
		mp[i].clear();
	}
	for(int i=1;i<=N;i++) {
		cin>>X[i];
	}
	for(int i=1;i<=K;i++) {
		int xx1,yy1,xx2,yy2,hh;
		cin>>xx1>>yy1>>xx2>>yy2>>hh;
		mp[xx1].push_back({yy1,xx2,yy2,hh,0x3f3f3f3f3f3f3f3f});
		mp[xx2].push_back({yy2,0,0,0,0x3f3f3f3f3f3f3f3f});
	}
	mp[1].push_back({1,0,0,0,0});
	mp[N].push_back({M,0,0,0,0x3f3f3f3f3f3f3f3f});
	for(int i=1;i<=N;i++) {
		sort(mp[i].begin(),mp[i].end());
	}
	for(int i=1;i<=N;i++) {
		ll mn=0x3f3f3f3f3f3f3f3f;
		for(auto &[y1,x2,y2,h,dist]:mp[i]) {
			mn=min(mn,(dist-y1*X[i]));
			dist=(mn+y1*X[i]);
		}
		reverse(mp[i].begin(),mp[i].end());
		mn=0x3f3f3f3f3f3f3f3f;
		for(auto &[y1,x2,y2,h,dist]:mp[i]) {
			mn=min(mn,(dist+y1*X[i]));
			dist=(mn-y1*X[i]);
			if(h>0) {
				auto it=lower_bound(mp[x2].begin(),mp[x2].end(),(Node){y2,0,0,0,0});
				it->dist=min(it->dist,(dist-h));
			}
		}
	}
	ans=mp[N].begin()->dist;
	if(ans<=1e16) {
		cout<<ans<<endl;
	} else {
		cout<<"NO ESCAPE"<<endl;
	}
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