#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
const int maxn=1e5+10;
struct MPNode {
    int to,w;
};
int N,Val[maxn],du[maxn],cost[maxn],vis[maxn];
vector<MPNode> mp[maxn];
void BFS() {
    queue<int> q;
//    cout<<1<<endl;
//    exit(0);
    for(int i=1;i<=N;i++) {
        if(du[i]==1) {
            q.push(i);
        }
    }
    int cur;
    while(!q.empty()) {
        cur=q.front();
//        cout<<cur<<endl;
        vis[cur]=1;
        q.pop();
        for(auto [to,w]:mp[cur]) {
            if(vis[to]) {
                continue;
            }
            Val[to]+=Val[cur];
            cost[to]+=(cost[cur]+(w*abs(Val[cur])));
            du[to]--;
            if(du[to]==1) {
                q.push(to);
            }
        }
    }
    cout<<cost[cur]<<endl;
}
signed main() {
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>Val[i];
    }
    for(int i=1;i<N;i++) {
        int uu,vv,ww;
        cin>>uu>>vv>>ww;
        mp[uu].push_back({vv,ww});
        mp[vv].push_back({uu,ww});
        du[uu]++;
        du[vv]++;
    }
    BFS();
    return 0;
}