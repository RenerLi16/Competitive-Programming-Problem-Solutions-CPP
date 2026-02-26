#include <iostream>
#define ll long long
using namespace std;
const int N = 100005;
ll n,m,ans,tot;
ll calc(ll n,ll m){
    int p=31-__builtin_clz(m/n);//算出最高位
    ll res=0,x=m-(1ll<<p)*n,tmp;
    tmp=x/(1<<p);
    x=x%(1<<p);
    tmp+=__builtin_popcount(x);
    // cout<<x<<" "<<" "<<p<<endl;
    for (int i=p;i>=0;--i){//从高位贪心填
        res+=x/(1ll<<i);
        x%=(1ll<<i);
    }
    // cout<<tmp<<" "<<res<<" ";
    return tmp+p;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n>>m;
        ans=0x3f3f3f3f3f3f3f3f;tot=0;
        while (n>1){
            if (n<=m) ans=min(ans,tot+calc(n,m));
            if (n&1) tot+=2,n=n/2+1;
            else tot+=1,n/=2;
        }
        ans=min(ans,tot+calc(n,m));
        cout<<ans<<"\n";
    }
}
