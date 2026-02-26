#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1e5+10;
int tag[maxn],dep[maxn],N,K,ans;
vector<int> mp[maxn];
priority_queue<int> pq;
void DFS1(int id, int fa, int dep) {
    bool f=0;
    for(auto to:mp[id]) {
        if(to!=fa) {
            f=1;
            DFS1(to,id,dep+1);
        }
    }
    if(f==0) {
        int newdep=ceil(1.0*dep/2);
        pq.push(newdep);
//        return;
    }
    while((!pq.empty()) && pq.top()==dep) {
        tag[id]=1;
        pq.pop();
    }
}
void DFS2(int id, int fa) {
    if(tag[id]==1) {
        ans++;
        return;
    }
    for(auto to:mp[id]) {
        if(to!=fa) {
            DFS2(to,id);
        }
    }
}
int main() {
//    freopen("/Users/renerli/Documents/code/in.txt","r",stdin);
    cin>>N>>K;
    for(int i=1;i<N;i++) {
        int uu,vv;
        cin>>uu>>vv;
        mp[uu].push_back(vv);
        mp[vv].push_back(uu);
    }
    DFS1(K,-1,0);
//    cout<<1<<endl;
//    return 0;
//    for(int i=1;i<=N;i++) {
//        cout<<tag[i]<<endl;
//    }
    DFS2(K,-1);
    cout<<ans<<endl;
    return 0;
}