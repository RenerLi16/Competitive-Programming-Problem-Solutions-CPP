#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 500005
#define pb push_back
#define MAXN 500000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,c,a[N],pre[N],suf[N],ans;
vector<int>G[N];
int main()
{
	n=read();c=read();
	for(int i=1;i<=n;i++)a[i]=read(),G[a[i]].pb(i);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(a[i]==c);
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+(a[i]==c);
	for(int i=1;i<=MAXN;i++)
	{
		if(!G[i].size())continue;
		int siz=G[i].size(),pos=0,maxn=pre[G[i][0]-1];
		ans=max(ans,1+maxn+suf[G[i][0]+1]);
		for(int j=1;j<siz;j++)
		{
			if((j-pos+1)+maxn>=1+pre[G[i][j]-1])ans=max(ans,(j-pos+1)+maxn+suf[G[i][j]+1]);
			else pos=j,maxn=pre[G[i][j]-1],ans=max(ans,1+pre[G[i][j]-1]+suf[G[i][j]+1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}