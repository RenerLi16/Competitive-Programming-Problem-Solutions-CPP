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

const int INF=2e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

int A[maxn],premn[maxn],sufsum[maxn],flag[maxn],N,ans;

void solve() {
	// Initiallize
	memset(flag,0,sizeof(flag));
	ans=INF;
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
	}
	premn[1]=A[1];
	flag[1]=1;
	for(int i=2;i<=N;i++) {
		if(A[i]<premn[i-1]) {
			flag[i]=1;
		}
		premn[i]=min(premn[i-1],A[i]);
	}
	sufsum[N]=premn[N];
	for(int i=(N-1);i>=1;i--) {
		sufsum[i]=(sufsum[i+1]+premn[i]);
	}
	ans=sufsum[1];
	for(int i=2;i<=N;i++) {
//		cout<<(sufsum[1]-sufsum[i])<<endl;
//		cout<<flag[i-1]<<" "<<A[i]<<endl;
		ans=min(ans,((sufsum[1]-sufsum[i])+(flag[i-1]==0 ? 0 : A[i])));
	}
	cout<<ans<<endl;
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