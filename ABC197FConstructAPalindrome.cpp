#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pii pair<int,int>
#define int long long
using namespace std;
const int INF=1e9+7;
const int maxn=1005;
struct MPNode {
    int to;
    char ch;
};
int dist[maxn][maxn],vis[maxn][maxn],N,M,ans=INF;
vector<MPNode> mp[maxn];
void BFS() {
    memset(vis,0,sizeof(vis));
    memset(dist,-1,sizeof(dist));
    queue<pii> q;
    dist[1][N]=0;
    q.push({1,N});
    vis[1][N]=1;
    while(!q.empty()) {
        auto cur=q.front();
        q.pop();
        int l=cur.first,r=cur.second;
        for(auto [nxtl,chl]:mp[l]) {
            for(auto [nxtr,chr]:mp[r]) {
                if(chl==chr && vis[nxtl][nxtr]==0) {
                    dist[nxtl][nxtr]=dist[l][r]+2;
                    q.push({nxtl,nxtr});
                    vis[nxtl][nxtr]=1;
                }
            }
        }
    }
}
signed main() {
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int uu,vv;
        char cc;
        cin>>uu>>vv>>cc;
        mp[uu].push_back({vv,cc});
        mp[vv].push_back({uu,cc});
    }
    BFS();
    for(int i=1;i<=N;i++) {
        if(dist[i][i]!=-1) {
            ans=min(ans,dist[i][i]);
        }
    }
    for(int i=1;i<=N;i++) {
        for(auto [to,ch]:mp[i]) {
            if(dist[i][to]!=-1) {
                ans=min(ans,dist[i][to]+1);
            }
        }
    }
    if(ans==INF) {
        ans=-1;
    }
    cout<<ans<<endl;
    return 0;
}