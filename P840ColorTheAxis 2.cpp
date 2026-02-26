#include <iostream>
using namespace std;
const int maxn=2e5+10;
struct DSU {
    int fa[maxn],siz[maxn],tot;
    void init() {
        for(int i=1;i<=tot+1;i++) {
            fa[i]=i;
            siz[i]=1;
        }
    }
    int getfa(int x) {
        if(fa[x]==x) {
            return x;
        }
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) {
        siz[getfa(y)]+=siz[getfa(x)];
        fa[getfa(x)]=getfa(y);
    }
}dsu;
int N,M,ans,stat[maxn];
int main() {
    cin>>N>>M;
    dsu.tot=N;
    dsu.init();
    ans=N;
    for(int i=1;i<=M;i++) {
        int ll,rr;
        cin>>ll>>rr;
        for(int i=ll;i<=rr;i=(dsu.getfa(ll)+1)) {
            if(stat[i]==0) {
                stat[i]=1;
                dsu.merge(i-1,i);
                ans--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}