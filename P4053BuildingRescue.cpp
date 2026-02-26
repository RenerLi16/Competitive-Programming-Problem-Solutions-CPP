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
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1.5e5+10;

int N,sum,ans=0;
pii pool[maxn];
priority_queue<int> pq;

bool cmp(pii first,pii second) {
	return first.second<second.second;
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>pool[i].first>>pool[i].second;
	}
	sort(pool+1,pool+N+1,cmp);
	for(int i=1;i<=N;i++) {
		sum+=(pool[i].first);
		pq.push(pool[i].first);
		if(sum<=(pool[i].second)) {
			ans++;
		} else {
			sum-=(pq.top());
			pq.pop();
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