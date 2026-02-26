#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define int long long
#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=105;


int dist[maxn][maxn],mp[maxn][maxn],N,M,ans;

void solve() {
	// Initiallize
	for(int i=0;i<maxn;i++) {
		for(int j=0;j<maxn;j++) {
			dist[i][j]=INF;
			mp[i][j]=INF;
		}
		dist[i][i]=0;
		mp[i][i]=0;
	}
	ans=0x3f3f3f3f;
	// No fluff real stuff
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		int uu,vv,di;
		cin>>uu>>vv>>di;
		mp[uu][vv]=min(mp[uu][vv],di);
		mp[vv][uu]=mp[uu][vv];
		dist[uu][vv]=min(dist[uu][vv],di);
		dist[vv][uu]=min(dist[vv][uu],di);
	}
	for(int k=1;k<=N;k++) {
		for(int i=1;i<k;i++) {
			for(int j=i+1;j<k;j++) {
				ans=min(ans,(mp[i][k]+mp[k][j]+dist[i][j]));
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(i==j) {
					continue;
				}
				dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
			}
		}
	}
//	for(int i=1;i<=N;i++) {
//		for(int j=1;j<=N;j++) {
//			cout<<dist[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	if(ans==0x3f3f3f3f) {
		cout<<"No solution."<<endl;
	} else {
		cout<<ans<<endl;
	}
	return ;
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