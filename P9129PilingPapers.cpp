#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define ll long long
using namespace std;
const int MOD=1e9+7;
const int maxn=305;
int bits[maxn],n,Q;
ll C[maxn][maxn],ans[50005],A,B;
vector<pair<int,int>> q[maxn];
int PrefRel(int x, int y, int o) {
    if(x<y) {
        return 0;
    } else {
        if(x==y) {
            return o;
        } else {
            return 2;
        }
    }
}
int SufRel(int x, int y, int o) {
    if(o!=1) {
        return o;
    } else {
        if(x<y) {
            return 0;
        } else {
            if(x==y) {
                return 1;
            } else {
                return 2;
            }
        }
    }
}
struct DPNode {
    ll f[maxn][20][20][3];
    int a[20],tot;
    void init(ll bound) {
        for(;bound;bound/=10) {
            a[++tot]=bound%10;
        }
        reverse(a+1,a+tot+1);
    }
    void work(int l) {
        memset(f,0,sizeof(f));
        for(int r=l;r<=n;r++) {
            for(int x=1;x<=tot;x++) {
                f[r][x][x][PrefRel(bits[r],a[x],1)]=2;
            }
        }
        for(int r=l;r<n;r++) {
            for(int x=1;x<=tot;x++) {
                for(int y=x;y<=tot;y++) {
                    for(int rel=0;rel<3;rel++) {
                        if(f[r][x][y][rel]==0) {
                            continue;
                        } else {
                            (f[r+1][x][y][rel]+=f[r][x][y][rel])%MOD;
                            if(x>1) {
                                (f[r+1][x-1][y][PrefRel(bits[r+1],a[x-1],rel)]+=f[r][x][y][rel])%=MOD;
                            }
                            if(y<n) {
                                (f[r+1][x][y+1][SufRel(bits[r+1],a[y+1],rel)]+=f[r][x][y][rel])%=MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    ll query(int l, int r) {
        ll ans=(f[r][1][tot][0]+f[r][1][tot][1])%MOD;
        for(int i=1;i<tot;i++) {
            ans=(ans+C[r-l+1][i]*(1<<i))%MOD;
        }
        return ans;
    }
}T1,T2;
signed main() {
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++) {
        cin>>bits[i];
    }
    for(int i=0;i<=n;i++) {
        C[i][0]=1;
        for(int j=1;j<=i;j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    T1.init(A-1);
    T2.init(B);
    cin>>Q;
    for(int i=1;i<=Q;i++) {
        int l,r;
        cin>>l>>r;
        q[l].push_back({r,i});
    }
    for(int l=1;l<=n;l++) {
        T1.work(l);
        T2.work(l);
        for(auto [r,id]:q[l]) {
            ans[id]=((T2.query(l,r)-T1.query(l,r))+MOD)%MOD;
        }
    }
    for(int i=1;i<=Q;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}