#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
const int maxn=5e4+10;

int N,K,M,sum,ans=0;
pii pool[maxn];
priority_queue<pii,vii,greater<pii>> cpq;
priority_queue<int> ppq;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>K>>M;
	for(int i=1;i<=N;i++) {
		cin>>pool[i].first>>pool[i].second;
	}
	for(int i=1;i<=N;i++) {
		sum+=pool[i].second;
		cpq.push({(pool[i].first-pool[i].second),pool[i].second});
		if(cpq.size()>K || (sum>M && ppq.empty())) {
			sum+=(cpq.top().first);
			ppq.push(cpq.top().first+cpq.top().second);
			cpq.pop();
		}
		if(sum<=M) {
			ans++;
		} else {
			sum-=ppq.top();
			ppq.pop();
		}
	}
	cout<<ans<<endl;
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