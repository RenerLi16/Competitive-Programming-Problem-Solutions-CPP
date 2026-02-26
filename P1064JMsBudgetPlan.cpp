#include <iostream>
using namespace std;
const int maxn=3.2e4+10;
const int maxm=65;
int f[maxm][maxn],N,M,recsiz[maxn],tot,ans,vis[maxn];
pair<int,int> rec[maxm][3],itm[maxn][5];
int main() {
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int vv,pp,qq;
        cin>>vv>>pp>>qq;
        if(qq==0) {
            rec[i][0].first=vv;
            rec[i][0].second=pp;
            vis[i]=1;
        } else {
            recsiz[qq]++;
            rec[qq][recsiz[qq]].first=vv;
            rec[qq][recsiz[qq]].second=pp;
        }
    }
    for(int i=1;i<=M;i++) {
//        cout<<recsiz[i]<<endl;
        if(vis[i]==1) {
            tot++;
            itm[tot][0].first=0;
            itm[tot][1].first=rec[i][0].first;
            itm[tot][2].first=rec[i][0].first+rec[i][1].first;
            itm[tot][3].first=rec[i][0].first+rec[i][2].first;
            itm[tot][4].first=rec[i][0].first+rec[i][1].first+rec[i][2].first;
            itm[tot][0].second=0;
            itm[tot][1].second=rec[i][0].first*rec[i][0].second;
            itm[tot][2].second=rec[i][0].first*rec[i][0].second+rec[i][1].first*rec[i][1].second;
            itm[tot][3].second=rec[i][0].first*rec[i][0].second+rec[i][2].first*rec[i][2].second;
            itm[tot][4].second=rec[i][0].first*rec[i][0].second+rec[i][1].first*rec[i][1].second+rec[i][2].first*rec[i][2].second;
        }
    }
//    for(int i=1;i<=tot;i++) {
//        cout<<itm[i][0].first<<" "<<itm[i][0].second<<endl;
//        cout<<itm[i][1].first<<" "<<itm[i][1].second<<endl;
//        cout<<itm[i][2].first<<" "<<itm[i][2].second<<endl;
//        cout<<itm[i][3].first<<" "<<itm[i][3].second<<endl;
//        cout<<itm[i][4].first<<" "<<itm[i][4].second<<endl;
//    }
//    return 0;
    for(int i=1;i<=tot;i++) {
        for(int j=N;j>=0;j--) {
            f[i][j]=f[i-1][j];
            for(int id=0;id<5;id++) {
                if(j>=itm[i][id].first) f[i][j]=max(f[i][j],(f[i-1][j-itm[i][id].first]+itm[i][id].second));
            }
        }
    }
//    cout<<1<<endl;
//    return 0;
    for(int i=0;i<=N;i++) {
        ans=max(ans,f[tot][i]);
    }
    cout<<ans<<endl;
    return 0;
}