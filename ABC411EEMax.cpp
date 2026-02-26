#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

//#define int long long
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=1e5+10;
const int maxval=6e5+10;


int f[maxval],A[maxn][6],N,ans,tot;
vi pool;
map<int,int> getpos;

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=6;j++) {
			cin>>A[i][j];
			pool.push_back(A[i][j]);
			sort(A[i]+1,A[i]+6+1);
		}
	}
	sort(all(pool));
	tot=pool-unique(all(pool))+1;
	for(int i=0;i<tot;i++) {
		getpos[pool[i]]=i;
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=6;j++) {
			if(A[i][j]!=A[i][j-1]) {
				f[getpos[A[i][j]]]
			}
		}
	}
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