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
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=3e5+10;


int P[maxn],N,ans;
priority_queue<int,vi,greater<int>> pq;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>P[i];
	}
	for(int i=1;i<=N;i++) {
		if(!pq.empty() && pq.top()<P[i]) {
			ans+=(P[i]-pq.top());
			pq.pop();
			pq.push(P[i]);
		}
		pq.push(P[i]);
	}
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