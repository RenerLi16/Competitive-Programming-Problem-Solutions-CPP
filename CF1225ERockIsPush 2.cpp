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
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2005;


int f[maxn][maxn],g[maxn][maxn],col[maxn][maxn],row[maxn][maxn],N,M,ans;
char MP[maxn][maxn];

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>(MP[i]+1);
	}
	if(N==1 && M==1) {
		cout<<1<<endl;
		return;
	}
	for(int i=N;i>=1;i--) {
		for(int j=M;j>=1;j--) {
			MP[i][j]=='R' ? (col[i][j]=1,row[i][j]=1) : 0;
			col[i][j]+=col[i+1][j];
			row[i][j]+=row[i][j+1];
		}
//		debugarr(col[i],M)
	}
	f[1][1]=1;
	g[1][1]=1;
	f[1][2]=(-1);
	g[2][1]=(-1);
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			f[i][j]=(f[i][j]+f[i-1][j])%MOD;
			g[i][j]=(g[i][j]+g[i][j-1])%MOD;
			f[i][j]=(f[i][j]+g[i][j-1])%MOD;
			g[i][j]=(g[i][j]+f[i-1][j])%MOD;
			(g[i][M-row[i][j+1]+1]-=(f[i][j]-MOD))%MOD;
			(f[N-col[i+1][j]+1][j]-=(g[i][j]-MOD))%MOD;
		}
		debugarr(f[i],M)
	}
	ans=(f[N][M]+g[N][M])%MOD;
	cout<<ans<<endl;
//	return 0;
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