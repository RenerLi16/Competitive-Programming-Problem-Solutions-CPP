#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define fi first
#define se second

const int maxn=2e5+10;

int N,M,vis[maxn],dist[maxn],cnt[maxn];
vector<pair<int,char>> mp[maxn];

void BFS(int src) {
    vi pool;
    pool.pb(src);
    dist[src]=0;
    vis[src]=1;
    int dep=0;
    while(!pool.empty()) {
        char mn='z';
        for(auto it:pool) {
            for(auto [to,w]:mp[it]) {
                mn=min(mn,w);
            }
        }
        vi nxt;
        memset(cnt,0,sizeof(cnt));
        dep++;
        for(auto it:pool) {
            for(auto [to,w]:mp[it]) {
                if(w==mn) {
                    if(cnt[to]==0 && vis[to]==0) {
                        dist[to]=dep;
                        vis[to]=1;
                        nxt.pb(to);
                    }
                    cnt[to]++;
                }
            }
        }
        //for(auto it:nxt) {
            //cout<<it<<" ";
        //}
        //cout<<endl;
        pool=nxt;
        //for(auto it:pool) {
            //cout<<it<<" ";
        //}
        //cout<<endl;
    }
}

void solve() {
    cin>>N>>M;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;i++) {
        mp[i].clear();
    }
    for(int i=1;i<=N;i++) {
        dist[i]=(-1);
    }
    for(int i=1;i<=M;i++) {
        int u,v;
        char ch;
        cin>>u>>v>>ch;
        mp[u].pb({v,ch});
        mp[v].pb({u,ch});
    }
    BFS(1);
    for(int i=1;i<=N;i++) {
        if(i>1) {
            cout<<" ";
        }
        if(vis[i]) {
            cout<<dist[i];
        } else {
            cout<<(-1);
        }
    }
    cout<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;i++) {
        solve();
    }
    return 0;
}