#include <iostream>
using namespace std;
const int maxn=1e5+10;
int lowbit(int x) {
    return x&(-x);
}
struct FenwickTree {
    int siz;
    int t[maxn];
    void modify(int id, int x) {
        for(;id<=siz;id+=lowbit(id)) {
            if(t[id]<=x) {
                return;
            } else {
                t[id]=x;
            }
        }
    }
    int getmin(int id) {
        int ret=0x3f3f3f3f;
        for(;id;id-=lowbit(id)) {
            if(ret>t[id]) {
                ret=t[id];
            }
        }
        return ret;
    }
} ft1,ft2;
int f[maxn][105],h[maxn],n,c,ans=0x3f3f3f3f;
int revid(int id) {
    return (100-id+1);
}
void buildtree(int id) {
    memset(ft1.t,0x3f,sizeof(ft1.t));
    ft1.siz=n;
    for(int i=100;i>=1;i--) {
//        cout<<(f[id][i]+(100-i+1))<<" ";
        ft1.modify(i,f[id][i]+(100-i+1));
    }
//    cout<<endl;
    memset(ft2.t,0x3f,sizeof(ft2.t));
    ft2.siz=n;
    for(int i=1;i<=100;i++) {
//        cout<<(f[id][i]+i)<<" ";
        ft2.modify(revid(i),f[id][i]+i);
    }
//    cout<<endl;
}
int main() {
    cin>>n>>c;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
        for(int j=h[i]+1;j<=100;j++) {
            f[i][j]=(j-h[i])*(j-h[i]);
        }
    }
    for(int i=2;i<=n;i++) {
        buildtree(i-1);
//        for(int j=1;j<=100;j++) {
//            cout<<f[1][j]<<" ";
//        }
//        cout<<endl;
//        for(int j=1;j<=100;j++) {
//            cout<<ft1.t[j]<<" ";
//        }
//        cout<<endl;
//        for(int j=1;j<=100;j++) {
//            cout<<ft2.t[j]<<" ";
//        }
//        cout<<endl;
//        return 0;
        for(int j=1;j<=100;j++) {
            f[i][j]+=min((ft1.getmin(j)-(100-i)),(ft2.getmin(revid(j))-(i-1)));
        }
    }
    for(int i=1;i<=100;i++) {
        ans=min(ans,f[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}