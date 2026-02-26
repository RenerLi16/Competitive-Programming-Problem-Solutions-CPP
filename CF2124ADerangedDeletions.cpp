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
const int maxn=105;

int A[maxn],N,mx=0;
pii ans;

void solve() {
	// Initiallize
	mx=0;
	ans={0,0};
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
		if(A[i]<mx) {
			ans={mx,A[i]};
		}
		mx=max(mx,A[i]);
	}
	if(ans.first!=0 && ans.second!=0) {
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<ans.first<<" "<<ans.second<<endl;
	} else {
		cout<<"NO"<<endl;
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