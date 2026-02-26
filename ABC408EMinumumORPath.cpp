#include <iostream>
#include <cmath>
#include <iomanip>
#define int long long
using namespace std;
using ll=long long;
const int maxn=2e5+10;
struct DSU {
    int fa[maxn],sz[maxn];
    void init() {
        for(int i=0;i<maxn;i++) {
            fa[i]=i;
            sz[i]=1;
        }
    }
    int getfa(int id) {
        if(fa[id]==id) {
            return id;
        } else {
            fa[id]=getfa(fa[id]);
            return fa[id];
        }
    }
    void merge(int id1, int id2) {
        int fa1=getfa(id1),fa2=getfa(id2);
        if(fa1==fa2) {
//            cout<<"lol"<<endl;
            return;
        }
        if(sz[fa1]>sz[fa2]) {
            sz[fa1]+=sz[fa2];
            fa[fa2]=fa1;
        } else {
            sz[fa2]+=sz[fa1];
            fa[fa1]=fa2;
        }
    }
} dsu;
struct Edge {
    int u,v;
    ll w;
} e[maxn];
int n,m;
signed main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    ll ans=(1LL<<30)-1;
//    dsu.init();
//    dsu.merge(1,2);
//    cout<<dsu.getfa(1)<<endl;
//    cout<<dsu.getfa(2)<<endl;
//    cout<<dsu.sz[dsu.getfa(1)]<<endl;
//    return 0;
//    cout<<ans<<endl;
    for(int i=29;i>=0;i--) {
        ans=(ans^(1LL<<i));
        dsu.init();
        for(int j=1;j<=m;j++) {
            if((ans|(e[j].w))==ans) {
                dsu.merge(e[j].u,e[j].v);
//                if(i==15) {
//                    cout<<e[j].u<<" "<<e[j].v<<endl;
//                }
            }
        }
        if(dsu.getfa(1)!=dsu.getfa(n)) {
            ans=(ans^(1<<i));
        }// else {
//            cout<<i<<" is deleted"<<endl;
//        }
    }
    cout<<ans<<endl;
    return 0;
}