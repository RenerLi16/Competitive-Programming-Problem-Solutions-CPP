#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int dist[maxn],K;
vector<pair<int,int>> mp[maxn];
struct DIJNode {
    int id, s;
    friend bool operator < (DIJNode first, DIJNode second) {
        return first.s>second.s;
    }
};
priority_queue<DIJNode> pq;
void Dijkstra() {
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=9;i++) {
        dist[i]=i;
        pq.push({i,i});
    }
    while(!pq.empty()) {
        DIJNode cur=pq.top();
        pq.pop();
        for(auto [to,w]:mp[cur.id]) {
            if((cur.s+w)<dist[to]) {
                dist[to]=cur.s+w;
                pq.push({to,dist[to]});
            }
        }
    }
}
int main() {
    cin>>K;
    for(int rmd=0;rmd<=K;rmd++) {
        for(int dgt=0;dgt<9;dgt++) {
            mp[rmd].push_back({(rmd*10+dgt)%K,dgt});
        }
    }
    Dijkstra();
    cout<<dist[0]<<endl;
    return 0;
}