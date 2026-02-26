#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int maxn=505;
const int maxsiz=250005;//数据范围开大 
struct DSU {
	int fa[maxsiz],siz[maxsiz],cnt[maxsiz],tot;//cnt数据范围开小了 
	int getfa(int x) {
		return (fa[x]==x ? x : (fa[x]=getfa(fa[x])));
	}
	void merge(int x, int y, int w) {
		int xfa=getfa(x),yfa=getfa(y);
		if(xfa==yfa) {
			return;
		}
		siz[yfa]+=siz[xfa];
		cnt[yfa]+=cnt[xfa];
		fa[xfa]=yfa;
	}
} dd;
struct SkiCourseRatingEdge {
	int u,v,w;
	friend bool operator < (SkiCourseRatingEdge first, SkiCourseRatingEdge second) {
		return first.w<second.w;
	}
};
int MP[maxn][maxn],N,M,T,ans;
vector<SkiCourseRatingEdge> pool;
int GetHash(int x, int y) {
	return ((x-1)*M+y);
}
signed main() {
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>MP[i][j];
			if(j>1) {
				pool.push_back({GetHash(i,j),GetHash(i,j-1),(abs(MP[i][j]-MP[i][j-1]))});
			//	pool.push_back({GetHash(i,j-1),GetHash(i,j),(abs(MP[i][j]-MP[i][j-1]))});一条边加一次就行了 
			}
			if(i>1) {
				pool.push_back({GetHash(i,j),GetHash(i-1,j),(abs(MP[i][j]-MP[i-1][j]))});
			//	pool.push_back({GetHash(i-1,j),GetHash(i,j),(abs(MP[i][j]-MP[i-1][j]))});
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			int x=GetHash(i,j);
			dd.siz[x]=1;
			dd.fa[x]=x;
			cin >> dd.cnt[x];
		}
	}
	sort(pool.begin(),pool.end());
	for(auto cur:pool) {
		dd.merge(cur.u,cur.v,cur.w);
		int x=dd.getfa(cur.u);
		if (dd.siz[x]>=T){
			ans+=dd.cnt[x]*cur.w;
			dd.cnt[x]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}