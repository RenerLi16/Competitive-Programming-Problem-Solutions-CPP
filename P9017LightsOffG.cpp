#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=20;

char A[maxn+5],B[maxn+5];
int f[maxn*3+5][1<<maxn],a,b,N,mp[1<<maxn];

void Left_Shift(int &x) {
	x=(((x<<1) & ((1<<N)-1)) | ((x & (1<<(N-1))) ? 1 : 0));
}

void solve() {
	// Initiallize
	a=0,b=0;
	// No fluff real stuff
	cin>>A>>B;
	for(int i=0;i<N;i++) {
		a=(a|((A[i]-'0')<<i));
		b=(b|((B[i]-'0')<<i));
	}
//	cout<<a<<" "<<b<<endl;
	if(a==0) {
		cout<<0<<endl;
		return;
	}
	for(int ans=1;ans<=(3*N);ans++) {
		a=(a^b);
		if(f[ans][mp[a]]) {
			cout<<ans<<endl;
			return;
		}
		Left_Shift(b);
	}
	return;
	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TT=1;
	cin>>TT>>N;
	memset(mp,-1,sizeof(mp));
	for(int S=0;S<(1<<N);++S) {
		if(mp[S]!=-1) {
			continue;
		}
		int x=S;
		while(mp[x]==(-1)) {
			mp[x]=S;
			Left_Shift(x);
		}
	}
	f[0][0]=1;
	int bittmp=0;
	for(int i=1;i<=(N*3);++i) {
		if(i<=N) {
			bittmp++;
		} else if(i<=(N*2)) {
			bittmp--;
		} else {
			bittmp++;
		}
		int x=((1<<bittmp)-1);
		for(int S=0;S<(1<<N);++S) {
			f[i][mp[S]]=(f[i][mp[S]] | f[i-1][mp[S^x]]);
		}
	}
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}