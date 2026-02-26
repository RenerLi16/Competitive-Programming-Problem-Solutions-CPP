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
const int maxn=1e5+10;

int A[maxn],Prime[maxn],isPrime[maxn],cnt,vis[maxn],N;
void GetPrime(int n)//筛到n
{
	memset(isPrime, 1, sizeof(isPrime));
	//以“每个数都是素数”为初始状态，逐个删去
	isPrime[1] = 0;//1不是素数
	
	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i])//没筛掉 
			Prime[++cnt] = i; //i成为下一个素数
			
		for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) 
		{
        	//从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
			isPrime[i*Prime[j]] = 0;
            
			if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
				break; //重要步骤。见原理
		}
	}
}

void solve() {
	// Initiallize
	memset(A,0,sizeof(A));
	memset(vis,0,sizeof(vis));
	// No fluff real stuff
	cin>>N;
	A[1]=1;
	for(int i=N;i>=2;i--) {
		if(isPrime[i]) {
			int mx=i;
			for(int j=2;(i*j)<=N;j++) {
				if(A[i*j]==0) {
					A[i*j]=(mx);
					vis[mx]=1;
					while(mx<=N) {
						mx+=i;
						if(!vis[mx]) {
							break;
						}
					}
				}
			}
			vis[mx]=1;
			A[i]=mx;
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return;
	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	GetPrime(1e5);
	int TT=1;
	cin>>TT;
	for(int i=1;i<=TT;++i) {
		solve();
	}
	return 0;
}