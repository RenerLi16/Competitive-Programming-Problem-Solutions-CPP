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
//const int MOD=1e9+7;
const int MOD=998244353;
const int maxn=5005;

map<int,bool> vis[maxn][maxn];
int f[maxn],g[maxn][maxn],N,M,ans;

void solve() {
	// Initiallize
	memset(f,0,sizeof(f));
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=0;j<=N;j++) {
			g[i][j]=j;
			vis[i][j].clear();
		}
	}
	for(int i=1;i<=M;i++) {
		int pos,x;
		cin>>pos>>x;
		for(int j=(pos-x+1);j>=1;j--) {
			if(!vis[i][i-j+1][pos-x+1-j]) {
				g[i][i-j+1]--;
				vis[i][i-j+1][pos-x+1-j]=true;
			}
		}
	}
	f[0]=1;
	for(int i=1;i<=N;i++) {
		for(int j=0;j<i;j++) {
			cout<<i<<" "<<j<<" "<<g[j+1][i-j]<<endl;
			f[i]=(f[i]+f[j]*g[j+1][i-j])%MOD;
		}
	}
	ans=f[N];
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