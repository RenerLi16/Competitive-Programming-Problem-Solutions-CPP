#include <iostream>
using namespace std;
const int maxn=2e5+10;
int f1[maxn],f2[maxn],N,a[maxn],mx[maxn],ans,X,g[maxn];
pair<int,int> dls[maxn];
int LB(int x) {
    return x&(-x);
}
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
}
int main() {
    cin>>N>>X;
    for(int i=1;i<=N;i++) {
        int x;
        cin>>x;
        dls[i]={x,i};
    }
    sort(dls,dls+N+1);
    int curid=0;
    for(int i=1;i<=N;i++) {
        if(dls[i].first!=dls[i-1].first) {
            curid++;
        }
        a[dls[i].second]=curid;
    }
    for(int i=1;i<=N;i++) {
        f1[i]=(GetMax(a[i]-1)+1);
        SingleChange(a[i],f1[i]);
    }
//    for(int i=1;i<=N;i++) {
//        cout<<f1[i]<<" ";
//    }
//    cout<<endl;
//    return 0;
    reverse(a+1,a+N+1);
    for(int i=1;i<=N;i++) {
        a[i]=(N-a[i]+1);
    }
    memset(mx,0,sizeof(mx));
    for(int i=1;i<=N;i++) {
        f2[i]=(GetMax(a[i])+1);
        SingleChange(a[i],f2[i]);
    }
    for(int i=1;i<=N;i++) {
        a[i]=(N-a[i]+1);
    }
    reverse(a+1,a+N+1);
    for(int i=1;i<=N;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    reverse(f2+1,f2+N+1);
//    for(int i=1;i<=N;i++) {
//        cout<<f2[i]<<" ";
//    }
//    cout<<endl;
    for(int i=1;i<=N;i++) {
        f1[i]=max(f1[i],f1[i-1]);
    }
    for(int i=N;i>=1;i--) {
        f2[i]=max(f2[i],f2[i+1]);
        g[a[i]]=f2[i];
    }
//    for(int i=1;i<=N;i++) {
//        cout<<f1[i]<<" ";
//    }
//    cout<<endl;
    for(int i=1;i<=N;i++) {
        cout<<f2[i]<<" ";
    }
    cout<<endl;
    for(int i=N;i>=1;i--) {
        g[i]=max(g[i],g[i+1]);
    }
    for(int i=1;i<=N;i++) {
        cout<<g[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=N;i++) {
        ans=max(ans,(f1[i]+g[a[i]-X]));
    }
    cout<<ans<<endl;
    return 0;
}