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
const int maxn=1e5+10;


int N,ans;
pii pool[maxn];
priority_queue<int,vi,greater<int>> pq;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>pool[i].first>>pool[i].second;
	}
	sort(pool+1,pool+N+1);
	int rmn=0;
	for(int i=1;i<=N;i++) {
		rmn+=(pool[i].first-pool[i-1].first);
		if(rmn==0 && (!pq.empty() && pool[i].second>pq.top()) ) {
			ans=(ans-pq.top()+pool[i].second);
			pq.pop();
			pq.push(pool[i].second);
			continue;
		}
		rmn--;
		pq.push(pool[i].second);
		ans+=(pool[i].second);
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