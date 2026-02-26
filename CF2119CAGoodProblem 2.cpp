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
const int maxn=1e18+10;

int N,L,R,K;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>L>>R>>K;
	if(N%2==1) {
		cout<<L<<endl;
	} else {
		if(N==2) {
			cout<<-1<<endl;
			return;
		}
		int nextPow2;
    	if (L == 0) {
    	    nextPow2 = 1;	
   		} else {
        	int k = 64 - __builtin_clzll(L);
        	nextPow2 = 1LL << k;
    	}
		if(nextPow2<=R) {
			if(K<=(N-2)) {
				cout<<L<<endl;
			} else {
				cout<<nextPow2<<endl;
			}
		} else {
			cout<<-1<<endl;
		}
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