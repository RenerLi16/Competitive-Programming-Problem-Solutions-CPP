#include <iostream>
#include <vector>
using namespace std;
const int maxn=405;
int n,k,fa[maxn][20],f[1<<20],pos[maxn],dfsid[maxn],sz[maxn],tot;
vector<int> mp[maxn];
void dfs(int id) {
    if(dfsid[id]==k) {
        fa[id][0]=id;
        for(int i=1;i<=k;i++) {
            fa[id][i]=fa[fa[id][i-1]][1];
        }
        pos[++tot]=id;
    }
    for(auto it:mp[id]) {
        if(it!=fa[id][1]) {
            fa[it][1]=id;
            dfsid[it]=dfsid[id]+1;
            dfs(it);
        }
    }
    sz[id]=tot;
}
int main() {
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    //k>19, no solution
    if(k>19) {
        cout<<"DA"<<endl;
        return 0;
    }
    //init dfs tags
    dfs(1);
    //DP
    f[0]=0;
    for(int st=0;st<(1<<k);st++) {
        if(f[st]==tot) {
            cout<<"DA"<<endl;
            return 0;
        }
        int nxt=pos[f[st]+1];
        for(int i=0;i<k;i++) {
            if((st&(1<<i))==0) {
                f[st^(1<<i)]=max(f[st^(1<<i)],sz[fa[nxt][i]]);
            }
        }
    }
    cout<<"NE"<<endl;
    return 0;
}