#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

//#define int long long
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
const int maxn=105;
const int maxlen=105;


int deg[30],vis[maxn],N;
char s[maxn][maxlen];
vi mp[30],ans;

void TopologicalExpansion() {
	queue<int> q;
	for(int i=0;i<26;i++) {
		if(deg[i]==0) {
			q.push(i);
			ans.push_back(i);
			vis[i]=1;
		}
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v:mp[u]) {
			if(vis[v]==1) {
				cout<<"Impossible"<<endl;
				exit(0);
			}
			deg[v]--;
			if(deg[v]==0) {
				q.push(v);
				ans.push_back(v);
				vis[v]=1;
			}
		}
	}
}

void solve() {
	// Initiallize
	// No fluff real stuff
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>s[i];
	}
	for(int i=2;i<=N;i++) {
		bool flag=false;
		for(int j=0;j<min(strlen(s[i-1]),strlen(s[i]));j++) {
			if(s[i-1][j]!=s[i][j]) {
				flag=true;
				debug(s[i-1][j]);
				debug(s[i][j]);
				mp[(int)(s[i-1][j]-'a')].push_back((int)(s[i][j]-'a'));
				deg[(int)(s[i][j]-'a')]++;
				break;
			}
		}
		if(flag==false && strlen(s[i-1])>strlen(s[i])) {
			cout<<"Impossible"<<endl;
			return;
		}
	}
	TopologicalExpansion();
	for(int i=0;i<26;i++) {
		if(vis[i]==0) {
			cout<<"Impossible"<<endl;
			return;
		}
	}
	for(auto it:ans) {
		cout<<((char)(it+'a'));
	}
	cout<<endl;
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