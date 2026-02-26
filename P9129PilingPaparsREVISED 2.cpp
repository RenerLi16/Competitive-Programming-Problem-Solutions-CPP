#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int maxn=305;
const int maxbit=20;
const int maxq=5e4+10;
int C[maxn][maxn],a[maxn],n,A,B,q,ans[maxq];
struct DP {
    int f[maxn][maxbit][maxbit][3],bits[maxbit],tot;
    void init(int x) {
        for(;x;x/=10) bits[++tot]=(x%10);
        reverse(bits+1,bits+tot+1);
    }
    int PreGetRel(int x, int y, int o) {
        if(x>y) {
            return 2;
        }
        if(x<y) {
            return 0;
        }
        return o;
    }
    int SufGetRel(int x, int y, int o) {
        if(o==1) {
            if(x>y) {
                return 2;
            }
            if(x<y) {
                return 0;
            }
            return 1;
        }
        return o;
    }
    void DProcess(int l) {
        memset(f,0,sizeof(f));
        for(int r=l;r<=n;r++) {
            for(int x=1;x<=tot;x++) {
                f[r][x][x][PreGetRel(a[r],bits[x],1)]=2;
            }
        }
        for(int r=l;r<n;r++) {
            for(int x=1;x<=tot;x++) {
                for(int y=x;y<=tot;y++) {
                    for(int rel=0;rel<=2;rel++) {
                        (f[r+1][x][y][rel]+=f[r][x][y][rel])%=MOD;
                        if(x>1) {
                            (f[r+1][x-1][y][PreGetRel(a[r+1],bits[x-1],rel)]+=f[r][x][y][rel])%=MOD;
                        }
                        if(y<tot) {
                            (f[r+1][x][y+1][SufGetRel(a[r+1],bits[y+1],rel)]+=f[r][x][y][rel])%=MOD;
                        }
                    }
                }
            }
        }
    }
    int getans(int l, int r) {
        int ans=(f[r][1][tot][0]+f[r][1][tot][1])%MOD;
        for(int i=1;i<tot;i++) {
            (ans+=(C[r-l+1][i]*(1<<i)))%=MOD;
        }
        return ans;
    }
} DP1,DP2;
vector<pair<int,int>> qq[maxn];
signed main() {
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++) {
        C[i][0]=1;
        for(int j=1;j<=i;j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    DP1.init(A-1);
    DP2.init(B);
    cin>>q;
    for(int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        qq[l].push_back({i,r});
    }
    for(int l=1;l<=n;l++) {
        DP1.DProcess(l);
        DP2.DProcess(l);
        for(auto it:qq[l]) {
            ans[it.first]=(DP2.getans(l,it.second)-DP1.getans(l,it.second)+MOD)%MOD;
        }
    }
    for(int i=1;i<=q;i++) {
        cout<<ans[i]<<endl;
    }
    cout<<endl;
    return 0;
}