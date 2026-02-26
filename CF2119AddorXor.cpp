#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

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
const int maxn=105;

int A,B,X,Y,ans;

void solve() {
	// Initiallize
	ans=0;
	// No fluff real stuff
	cin>>A>>B>>X>>Y;
	if(A>B) {
		if((A^1)==B) {
			cout<<Y<<endl;
			return;
		}
		cout<<-1<<endl;
		return;
	} else {
		if(X<Y) {
			Y=X;
		}
			if((A%2)==1) {
				ans+=X;
				A++;
			}
		if((B%2)==1) {
			ans+=Y;
			B--;
		}
		debug((B-A));
//		cout<<A<<" "<<B<<endl;
		ans+=(((B-A)/2)*(X+Y));
		cout<<ans<<endl;
		return;
	}
	
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