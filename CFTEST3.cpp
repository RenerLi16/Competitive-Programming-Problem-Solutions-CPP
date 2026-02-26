≥#include<iostream>
#include<vector>
#define mod 998244353
using namespace std;
int powdv(int x,int y=mod-2){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%mod;
        y>>=1,x=1ll*x*x%mod;
    }
    return ans;
}
int query(vector<int>v){
    int k=v.size();
    printf("? %d",k);
    for(int i=0;i<k;++i)printf(" %d",v[i]);
    printf("\n");fflush(stdout);
    int x;scanf("%d",&x);
    return x;
}
bool ok(int l,int r){
    vector<int>v;
    for(int i=l;i<=r;++i)v.emplace_back(i);
    for(int i=l;i<=r;++i)v.emplace_back(i);
    return query(v)>0;
}
int LL,RR;
bool fin(int l,int r){
    int L=l+1,R=r;
    while(L<=R){
        int mid=(L+R)>>1;
        if(ok(l,mid))R=mid-1;
        else L=mid+1;
    }
    if(L>r)return 0;
    if(query({l,L}))LL=l,RR=L;
    else LL=L,RR=l;
    return 1;
}
int ans[1005];
int main(){
    int T=1;
    scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        LL=RR=0;
        if(!fin(1,n/2)){
            if(!fin(n/2,n-1)){
                fin(n-1,n);
            }
        }
        for(int i=1;i<=n;i+=2){
            int x=i,y=min(n,i+1);
            int an=query({x,y,LL,LL,x,LL,LL,x,LL,LL,y,LL,LL,y});
            if(an==0)ans[x]=ans[y]=0;
            else if(an==2)ans[x]=1,ans[y]=0;
            else if(an==3)ans[x]=0,ans[y]=1;
            else ans[x]=ans[y]=1;
        }
        printf("! ");
        for(int i=1;i<=n;++i){
            if(ans[i]==0)putchar('(');
            else putchar(')');
        }
        putchar('\n');fflush(stdout);
    }
    return 0;
}