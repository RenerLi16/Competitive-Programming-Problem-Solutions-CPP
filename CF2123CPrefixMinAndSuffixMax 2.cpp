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
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

int A[maxn],N,ans[maxn],mn,mx;

void solve() {
	// Initiallize
	mn=0x3f3f3f3f;
	mx=-0x3f3f3f3f;
	memset(ans,0,sizeof(ans));
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
	}
	for(int i=1;i<=N;i++) {
		mn=min(mn,A[i]);
		if(mn==A[i]) {
			ans[i]=1;
		}
	}
	for(int j=N;j>=1;j--) {
		mx=max(mx,A[j]);
		if(mx==A[j]) {
			ans[j]=1;
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<ans[i];
	}
	cout<<endl;
	
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