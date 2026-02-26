#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10;
int mx[maxn],f[maxn],a[maxn],N,T,ans;
pair<int,int> dls[maxn];
int GetMax(int id) {
    int ret=0;
    for(;id;id-=(id&(-id))) {
        ret=max(ret,mx[id]);
    }
    return ret;
}
void SingleChange(int id, int x) {
    for(;id<=N;id+=(id&(-id))) {
        mx[id]=max(mx[id],x);
    }
    return;
}
signed main() {
    cin>>N>>T;
    for(int i=1;i<=N;i++) {
        int s,v;
        cin>>s>>v;
        dls[i]={1LL*(s+v*T),i};
    }
    sort(dls+1,dls+N+1);
    for(int i=1,cur=0;i<=N;i++) {
        if(dls[i].first!=dls[i-1].first) {
            cur++;
        }
        a[dls[i].second]=cur;
    }
    reverse(a+1,a+N+1);
//    for(int i=1;i<=N;i++) {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    for(int i=1;i<=N;i++) {
        f[i]=GetMax(a[i])+1;
        SingleChange(a[i],f[i]);
    }
    for(int i=1;i<=N;i++) {
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}