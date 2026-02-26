#include <iostream>
#include <map>
using namespace std;
const int maxn=2e6+10;
const int maxm=2e5+10;
int pre[maxn],suf[maxn],N,M,Q;
map<int,int> rec,mp;
int main() {
    cin>>N>>M;
    N=N*2;
    for(int i=1;i<=M;i++) {
        int Ai,Bi;
        cin>>Ai>>Bi;
        mp[Ai]=i;
        mp[Bi]=i;
    }
    for(int i=1;i<=N;i++) {
        pre[i]=pre[i-1];
        if(rec[mp[i]]==1) {
            pre[i]++;
            rec[mp[i]]=0;
        } else if(i%2==0) {
            rec[mp[i]]=1;
        }
    }
    for(int i=N;i>=1;i--) {
        suf[i]=suf[i+1];
        if(rec[mp[i]]==1) {
            suf[i]++;
            rec[mp[i]]=0;
        } else if(i%2==0) {
            rec[mp[i]]=1;
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    cin>>Q;
    for(int i=1;i<=Q;i++) {
        int l,r;
        cin>>l>>r;
        cout<<pre[r]<<" "<<suf[l]<<endl;
        cout<<(2*M-(pre[r]+suf[l]))<<endl;
    }
    return 0;
}