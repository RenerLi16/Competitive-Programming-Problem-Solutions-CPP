#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
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
const int maxn=2e5+10;
//const int maxm=4e5+10;

int deg[maxn],cpydeg[maxn],l[maxn],r[maxn],ans[maxn],N,M;
vi mp[maxn],tporder;
queue<int> q;

void TopologicalExpansionGetAnswer() {
	priority_queue<pii,vii,greater<pii>> pq;
	vii e[maxn];
	for(int i=1;i<=N;i++) {
		if(cpydeg[i]==0) {
			if(l[i]<=1) {
				pq.push({r[i],i});
			} else {
				e[l[i]].push_back({r[i],i});
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for (auto x:e[i]) {
			pq.push(x);
		}
		if(pq.empty()) {
			cout<<"No"<<endl;
			exit(0);
		}
		auto [rcur,u]=pq.top();
		pq.pop();
		if(i>rcur) {
			cerr<<"H"<<endl;
			cout<<"No"<<endl;
			exit(0);
		}
		ans[u]=i;
		for(int v:mp[u]) {
//			if(cpydeg[v]==0) {
//				cout<<"No"<<endl;
//				exit(0);
//			}
			cpydeg[v]--;
			if(cpydeg[v]==0) {
				if(l[v]<=i+1) {//err:1
					pq.push({r[v],v});
				} else {
					e[l[v]].push_back({r[v],v});
				}
			}
		}
	}
}

void TopologicalExpansionGetRight() {
	for(int i=1;i<=N;i++) {
		if(deg[i]==0) {
			q.push(i);
//			tporder.push_back(i);
		}
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		tporder.push_back(u);
		for(int v:mp[u]) {
//			if(deg[v]==0) {
//				cout<<"No"<<endl;
//				exit(0);
//			}
			deg[v]--;
			if(deg[v]==0) {
				q.push(v);
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int si,ti;
		cin>>si>>ti;
		mp[si].push_back(ti);
		deg[ti]++;
	}
	memcpy(cpydeg,deg,sizeof(deg));
	for(int i=1;i<=N;i++) {
		cin>>l[i]>>r[i];
	}
	TopologicalExpansionGetRight();
	if(tporder.size()<N) {
		cout<<"No"<<endl;
		return;
	}
	for(int x:tporder) {
		cerr<<x<<" ";
	}
	cerr<<endl;
	reverse(tporder.begin(),tporder.end());
	for(int u:tporder) {
		for(int v:mp[u]) {
			r[u]=min(r[u],r[v]-1);
		}
	}
	for(int i=1;i<=N;i++) {
		cerr<<l[i]<<" "<<r[i]<<endl;
	}
	TopologicalExpansionGetAnswer();
	cout<<"Yes"<<endl;
	for(int i=1;i<=N;i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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