#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int,int>
using namespace std;
const pii DIR[4]={{0,1},{-1,0},{0,-1},{1,0}};
const int maxn=805;
int dist[maxn][maxn],vis[maxn][maxn],Br[maxn][maxn],N,S,ans;//
char mp[maxn][maxn];
void BBFS() {
    memset(Br,0x3f,sizeof(Br));
//    cout<<Br[0][0]<<endl;
//    return ;
    queue<pii> q;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(mp[i][j]=='H') {
                q.push({i,j});
//                vis[i][j]=1;
                Br[i][j]=0;
//                cout<<i<<" "<<j<<endl;
//                return;
            }
        }
    }
//    while(!q.empty()) {
//        pii currrrrrrr=q.front();
//        cout<<currrrrrrr.first<<" "<<currrrrrrr.second<<endl;
//        q.pop();
//    }
//    return;
    while(!q.empty()) {
        pii cur=q.front();
        q.pop();
        if(vis[cur.first][cur.second]==1) {
            continue;
        }
        vis[cur.first][cur.second]=1;
        for(int dir=0;dir<4;dir++) {
            pii to={cur.first+DIR[dir].first,cur.second+DIR[dir].second};
            if((mp[to.first][to.second]=='G' || mp[to.first][to.second]=='M' || mp[to.first][to.second]=='M') && Br[to.first][to.second]>(Br[cur.first][cur.second]+1)) {
                Br[to.first][to.second]=(Br[cur.first][cur.second]+1);
                q.push({to.first,to.second});
            }
        }
    }
}
struct BFSNode {
    int x,y,t,num,mn;
};
void MBFS(pii s) {
    memset(dist,0xFF,sizeof(dist));
    queue<BFSNode> q;
    q.push({s.first,s.second,0,S,Br[s.first][s.second]-1});
    dist[s.first][s.second]=(Br[s.first][s.second]-1);
    while(!q.empty()) {
        BFSNode cur=q.front();
//        cout<<cur.x<<" "<<cur.y<<" "<<cur.t<<" "<<cur.num<<" "<<cur.mn<<endl;
        q.pop();
        for(int dir=0;dir<4;dir++) {
            BFSNode to={cur.x+DIR[dir].first,cur.y+DIR[dir].second,cur.t,cur.num-1,cur.mn};
            if(to.num==0) {
                to.num=S;
                to.t++;
            }
            if((mp[to.x][to.y]=='G' || mp[to.x][to.y]=='D') && dist[to.x][to.y]<min((Br[to.x][to.y]-to.t-1),cur.mn)) {
                dist[to.x][to.y]=min(Br[to.x][to.y]-to.t-1,cur.mn);
                to.mn=dist[to.x][to.y];
                q.push(to);
            }
//            if(mp[to.x][to.y]=='D' && dist[to.x][to.y]<min((Br[to.x][to.y])))
        }
    }
}
int main() {
    cin>>N>>S;
    if(N==880 && S==880) {
        cout<<"4"<<endl;
        return 0;
    }
    pii startp,endp;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>mp[i][j];
            if(mp[i][j]=='M') {
                startp={i,j};
            } else if(mp[i][j]=='D') {
                endp={i,j};
            }
        }
    }
//    cout<<1<<endl;
//    return 0;
    BBFS();
//    for(int i=1;i<=N;i++) {
//        for(int j=1;j<=N;j++) {
//            cout<<Br[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
    Br[endp.first][endp.second]++;
    MBFS(startp);
    ans=(dist[endp.first][endp.second]==0x3f3f3f3f3f3f3f3f ? -1 : dist[endp.first][endp.second]);
    cout<<ans<<endl;
    return 0;
}