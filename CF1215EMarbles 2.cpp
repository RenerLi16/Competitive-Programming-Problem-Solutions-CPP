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
const int maxn=4e5+10;
const int maxcolor=20;

int f[1<<maxcolor],c[maxcolor+5][maxcolor+5],cnt[maxcolor+5],A[maxn],StatFinal,N;

void solve() {
	// Initiallize
	memset(f,0x3f,sizeof(f));
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
		A[i]--;

		if(cnt[A[i]]==0) {
			StatFinal=(StatFinal^(1<<A[i]));
		}
		for(int j=0;j<maxcolor;j++) {
			if(A[i]==j) {
				continue;
			}
			c[A[i]][j]+=cnt[j];
		}
		cnt[A[i]]++;
	}
//	cout<<StatFinal<<endl;
//	for(int i=1;i<4;i++) {
//		for(int j=1;j<4;j++) {
//			cout<<c[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	f[0]=0;
	for(int S=0;S<(1<<maxcolor);S++) {
		for(int i=0;i<maxcolor;i++) {
			if(!((1<<i)&S)) {
				continue;
			}
			int cur=f[S^(1<<i)];
			for(int j=0;j<maxcolor;j++) {
				if(i==j || ((1<<j)&S)) {
					continue;
				}
				cur+=c[i][j];
			}
			f[S]=min(f[S],cur);
		}
	}
	cout<<f[StatFinal]<<endl;
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