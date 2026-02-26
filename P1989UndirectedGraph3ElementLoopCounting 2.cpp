#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int maxn=1e5+10;
const int maxm=2e5+10;
int deg[maxn],N,M,ans,src[maxn];
vector<int> mp[maxn];
pair<int,int> e[maxm];
unordered_set<int> match[maxn];
int main() {
//    freopen("/Users/heheheheheheee/Documents/code/in.txt","r",stdin);
    cin>>N>>M;
//    cout<<N<<" "<<M<<endl;
    for(int i=1;i<=M;i++) {
        int uu,vv;
        cin>>uu>>vv;
        deg[uu]++;
        deg[vv]++;
        if(uu>vv) {
            swap(uu,vv);
        }
        e[i]={uu,vv};
    }
    for(int i=1;i<=M;i++) {
        if(deg[e[i].second]>deg[e[i].first]) {
            swap(e[i].first,e[i].second);
        }
        mp[e[i].second].push_back(e[i].first);
        match[e[i].second].insert(e[i].first);
    }
/*    for(int i=1;i<=N;i++) {
        for(int to:mp[i]) {
            src[to]=i;
        }
        for(int to:mp[i]) {
            for(int trd:mp[to]) {
                if(src[trd]==i) {
                    ans++;
                }
            }
        }
    }*/
    for(int i=1;i<=M;i++) {
//        int k=1;
        for(int to:mp[e[i].first]) {
//            int s=1;
            if(match[e[i].second].count(to)>0) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}