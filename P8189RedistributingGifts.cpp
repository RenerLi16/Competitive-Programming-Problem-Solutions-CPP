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
const int maxn=25;
const int maxstat=(1<<18);

bool mp[maxn][maxn];
int f[maxstat],g[maxstat],h[maxstat][maxn],N,ans;

void solve() {
	// Initiallize
	char s[maxn]={};
	// No fluff real stuff
	cin>>(s);
	int S=0;
	for(int i=0;i<N;i++) {
		if(s[i]=='G') {
			S=(S|(1<<i));
		}
	}
	ans=(f[S]*f[((1<<N)-1)-S]);
	cout<<ans<<endl;
	return;
	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	for(int i=1;i<=N;i++) {
		bool flag=false;
		for(int j=1;j<=N;j++) {
			int x;
			cin>>x;
			if(!flag) {
				mp[i-1][x-1]=true;
			}
			if(x==i) {
				flag=true;
			}
		}
	}
	for(int i=0;i<N;i++) {
		h[1<<i][i]=1;
	}
	for(int S=1;S<(1<<N);S++) {
		int x=__builtin_ctz(S);
		for(int u=x;u<N;u++) {
			if(h[S][u]>0) {
				if(mp[u][x]) {
					g[S]+=h[S][u];
				}
				for(int v=(x+1);v<N;v++) {
					if(((S&(1<<v))==0) && mp[u][v]) {
						h[S^(1<<v)][v]+=h[S][u];
					}
				}
			}
		}
	}
	f[0]=1;
	for(int S=1;S<(1<<N);S++) {
		int x=__builtin_ctz(S);
		for(int T=S;T;T=(S&(T-1))) {
			if((T)&(1<<x)) {
				f[S]+=(g[T]*f[S^T]);
			}
		}
	}
	int TT=1;
	cin>>TT;
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}