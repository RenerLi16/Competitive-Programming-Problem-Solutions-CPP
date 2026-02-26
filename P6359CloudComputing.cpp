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
#define all(x,n) (x)+1,((x)+(n)+1)
#define vall(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

#ifdef LOCAL
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;
#else
#define debug(x)
#define debugarr(a,n)
#endif

const int INF=2e18+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=4010;
const int maxc=1e5+10;
//const int SHIFT=1e4;

struct CCNode {
	int c,freq,v;
	friend bool operator < (CCNode first, CCNode second) {
		return first.freq>second.freq || (first.freq==second.freq && first.v<second.v);
	}
} pool[maxn];

int f[(maxc*2)],N,M,ans;

void solve() {
	// Initiallize
	memset(f,-0x3f,sizeof(f));
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>pool[i].c>>pool[i].freq>>pool[i].v;
		pool[i].v=(-pool[i].v);
	}
	cin>>M;
	for(int i=(N+1);i<=(N+M);i++) {
		cin>>pool[i].c>>pool[i].freq>>pool[i].v;
		pool[i].c=(-pool[i].c);
	}
	N+=M;
	sort(all(pool,N));
	f[0]=0;
	for(int i=1;i<=N;i++) {
		if(pool[i].c<0) {
			for(int j=0;j<=100000;j++) {
				if(f[j-pool[i].c]==(-INF)) continue;
				f[j]=max(f[j],(f[(j-pool[i].c)]+pool[i].v));
			}
		} else {
			for(int j=100000;j>=pool[i].c;j--) {
				if(f[j-pool[i].c]==(-INF)) continue;
				f[j]=max(f[j],(f[(j-pool[i].c)]+pool[i].v));
			}
		}
		debugarr(f,20);
	}
	for(int i=0;i<=50;i++) {
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
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