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

int A[maxn],N,K,cnt;

void solve() {
	// Initiallize
	cnt=0;
	// No fluff real stuff
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		char cc;
		cin>>cc;
		A[i]=(cc-'0');
		if(cc=='1') {
			cnt++;
		}
	}
	if(cnt<=K) {
		cout<<"Alice"<<endl;
		return;
	}
	if(K>(N/2)) {
		cout<<"Alice"<<endl;
		return;
	}
	cout<<"Bob"<<endl;
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