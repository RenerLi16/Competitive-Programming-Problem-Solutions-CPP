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
const int maxn=2e5+10;

pii A[maxn];
int tot,numx,valx,N,K;

bool cmp(pii first, pii second) {
	return first.second<second.second;
}

void solve() {
	// Initiallize
	memset(A,0,sizeof(A));
	numx=0;
	// No fluff real stuff
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A+1,A+N+1);
//	for(int i=1;i<=N;i++) {
//		cout<<A[i].first<<" ";
//	}
	for(int i=K;i<=N;i++) {
		valx=A[i].first;
		numx++;
		if(A[i].first!=A[i+1].first) {
			for(int j=i+1;j<=N;j++) {
				A[j]={0,INF};
			}
			tot=i;
			break;
		}
	}
	sort(A+1,A+N+1,cmp);
//	cout<<numx<<" "<<valx<<endl;
//	for(int i=1;i<=tot;i++) {
//		cout<<A[i].first<<endl;
//	}
	int l=1,r=tot;
	while(l<r) {
		if(A[l].first!=A[r].first) {
			if(numx==0) {
				cout<<"NO"<<endl;
				return;
			}
			if(A[l].first==valx) {
				l++;
				numx--;
				continue;
			} else if(A[r].first==valx) {
				r--;
				numx--;
				continue;
			} else {
				cout<<"NO"<<endl;
				return;
			}
		}
		l++;
		r--;
	}
	cout<<"YES"<<endl;
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