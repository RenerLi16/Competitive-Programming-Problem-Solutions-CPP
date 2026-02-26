#include <iostream>
#include <cstring>
using namespace std;

const int maxn=30;

int N,K,decomp[maxn],ans,cnt;
tuple<int,int,int> qry[maxn];

int Check() {
    int res=0;
    for(int i=1;i<=K;i++) {
        auto [x,y,z]=qry[i];
        if(decomp[x]==1 && decomp[y]==0 && decomp[x]==0) {
            res++;
        }
    }
    return res;
}

void DFS(int dep) {
    if(dep>N) {
        for(int i=1;i<=N;i++) {
            cout<<decomp[i]<<" ";
        }
        cout<<endl;

        int res=Check();
        if(ans==res) {
            cnt++;
        }
        if(ans<res) {
            ans=res;
            cnt=0;
        }
        return;
    }
    decomp[dep]=0;
    DFS(dep+1);
    decomp[dep]=1;
    DFS(dep+1);
}

void solve() {
    //Initialization
    ans=0;
    cnt=0;
    //Input
    cin>>N>>K;
    for(int i=1;i<=K;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        qry[i]={x,y,z};
    }
    DFS(1);
    cout<<ans<<" "<<cnt<<endl;
    return;

}

int main() {
    int TT=1;
    //cin>>TT;
    while(TT--) {
        solve();
    }
    return 0;
}