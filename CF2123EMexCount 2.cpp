#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define int long long
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
const int maxn=2e5+10;

int A[maxn],N,sum1[maxn],sum2[maxn],siz[maxn],tot,ans;


bool cmp(int first,int second) {
	return first>second;
}

void solve() {
	// Initiallize
	ans=0;
	tot=0;
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
	}
	bool flag=false;
	for(int i=1;i<=N;i++) {
		if(A[i]!=0) {
			flag=true;
			break;
		}
	}
	if(!flag) {
		for(int i=1;i<=(N+1);i++)  {
			cout<<1<<" ";
		}
		cout<<endl;
		return;
	}
	sort((A+1),(A+N+1));
	A[0]=(-1);
	for(int i=1;i<=N;i++) {
		if(A[i]!=A[i-1] && A[i]!=(A[i-1]+1)) {
			break;
		}
		if(A[i]==A[i-1]) {
			siz[tot]++;
			continue;
		}
		tot++;
		siz[tot]=1;
	}
	siz[tot+1]=0;
	sort((siz+1),(siz+tot+1+1),cmp);
	sum1[0]=0;
	sum2[0]=0;
	for(int j=1;j<=(tot+1);j++){
		sum1[j]=(sum1[j-1]+siz[j]);
		sum2[j]=(sum2[j-1]+siz[j]-1);
	}
	int k=0,pos1=(tot+1),pos2=(tot+1);
	for(;k<=N;k++) {
		for(;pos1>=1;pos1--) {
//			cout<<k<<" "<<siz[pos1]<<" "<<(N-sum1[pos1-1]+sum2[pos1-1])<<endl;
			if(k>=siz[pos1]  && k<=(N-sum1[pos1-1]+sum2[pos1-1])) {
				ans++;
			} else {
				break;
			}
		}
		for(;pos2>=1;pos2--) {
//			cout<<k<<" "<<siz[pos]<<" "<<(N-sum1[pos-1]+sum2[pos-1])<<endl;
			if(k>=siz[pos2]  && k<=(N-sum1[pos2-1]+sum2[pos2-1])) {
				break;
			} else {
				ans--;
			}
		}
		cout<<ans<<" ";
	}
	k++;
//	cout<<pos<<endl;
	cout<<endl;
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