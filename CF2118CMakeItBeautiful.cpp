#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
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
const int maxn=5005;
const int maxnum=65;


int A[maxn],digt[maxnum],N,k,ans;
vector<int> pool;

void GetExpansion(int x) {
	memset(digt,0,sizeof(digt));
	int tot=0;
	while(x>0) {
		digt[tot]=(x%2);
		x/=2;
		tot++;
	}
	for(int i=0;i<=60;i++) {
		if(digt[i]==1) {
			ans++;
			continue;
		}
		pool.push_back((long long)(1LL<<i));
//		cout<<(1LL<<i)<<endl;
	}
}

void solve() {
	// Initiallize
	pool.clear();
	ans=0;
	// No fluff real stuff
	cin>>N>>k;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
		GetExpansion(A[i]);
	}
	sort(pool.begin(),pool.end());
	for(int it:pool) {
		cerr<<it<<" ";
	}
	cerr<<endl;
	for(int cost:pool) {
		if(k<cost) {
			break;
		}
		k-=cost;
		ans++;
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