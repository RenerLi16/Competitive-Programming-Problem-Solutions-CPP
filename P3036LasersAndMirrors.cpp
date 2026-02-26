#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10;
int N,dist[maxn*2],ans;//,vis[maxn*2]
struct Node {
    int x, y, id;
    void print() {
        cout<<x<<" "<<y<<" "<<id<<endl;
    }
} pool[maxn*2];
vector<pair<int,int>> mp[maxn*2];
deque<int> dq;
bool cmpver(Node first, Node second) {
    return first.x<second.x || (first.x==second.x && first.y<second.y);
}bool cmphor(Node first, Node second) {
    return first.y<second.y || (first.y==second.y && first.x<second.x);
}bool cmpid(Node first, Node second) {
    return first.id<second.id;
}void OZBFS() {
//    memset(vis,0,sizeof(vis));
    dq.clear();
    dist[N-1]=0;
    dq.push_back(N-1);
//    vis[N-1]=1;
    dist[2*N-1]=0;
    dq.push_back(2*N-1);
//    vis[2*N-1]=1;
    while(!dq.empty()) {
        int cur=dq.front();
        dq.pop_front();
        for(auto [to,w]:mp[cur]) {
            if(dist[to]>(dist[cur]+w)) {
                dist[to]=dist[cur]+w;
                if(w==0) {
                    dq.push_front(to);
                } else {
                    dq.push_back(to);
                }
            }
        }
    }
}
signed main() {
//    freopen("/Users/renerli/Documents/code/in.txt","r",stdin);
    cin>>N>>pool[N+1].x>>pool[N+1].y>>pool[N+2].x>>pool[N+2].y;
    pool[N+1].id=N+1;
    pool[N+2].id=N+2;
    N+=2;
    for(int i=1;i<=N-2;i++) {
        cin>>pool[i].x>>pool[i].y;
        pool[i].id=i;
//        pool[i].print();
    }
    for(int i=1;i<=N;i++) {
        pool[i+N]=pool[i];
        pool[i+N].id=(i+N);
    }
    sort(pool+1,pool+N+1,cmphor);
    for(int i=2;i<=N;i++) {
        if(pool[i].y==pool[i-1].y) {
            mp[pool[i].id].push_back({pool[i-1].id,0});
            mp[pool[i-1].id].push_back({pool[i].id,0});
//            pool[i].print();
//            pool[i-1].print();
        }
    }
    sort(pool+N+1,pool+N*2+1,cmpver);
    for(int i=N+2;i<=2*N;i++) {
        if(pool[i].x==pool[i-1].x) {
            mp[pool[i].id].push_back({pool[i-1].id,0});
            mp[pool[i-1].id].push_back({pool[i].id,0});
//            pool[i].print();
//            pool[i-1].print();
        }
    }
    sort(pool+1,pool+N*2+1,cmpid);
    for(int i=1;i<=N;i++) {
        mp[i].push_back({i+N,1});
        mp[i+N].push_back({i,1});
    }
    memset(dist,0x3f,sizeof(dist));
    OZBFS();
//    for(int i=1;i<=N*2;i++) {
//        cout<<dist[i]<<endl;
//    }
    ans=min(dist[N],dist[N*2]);
    if(ans==0x3f3f3f3f3f3f3f3f) {
        ans=(-1);
    }
    cout<<ans<<endl;
    return 0;
}