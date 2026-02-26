#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <cmath>
#include <array>
#include <numeric>
using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back

const int maxn=1e5+10;

int N,Q,ans,sum;
pii pool[maxn];
vii cost;

void solve() {
    //Initialization
    //Input
    cin>>N>>Q;
    for(int i=0;i<N;i++) {
        cin>>pool[i].fi;
        if(i<=31) {
            pool[i].se=(1LL<<i);
        }
    }
    cost.pb(pool[0]);
    for(int i=1;i<min(N,32LL);i++) {
        if((1.0*pool[i].fi/pool[i].se)<(1.0*cost.back().fi/cost.back().se)) {
            cost.pb(pool[i]);
        }
    }
    //for(auto it:cost) {
        //cout<<it.fi<<" "<<it.se<<endl;
    //}
    for(int i=1;i<=Q;i++) {
        int x;
        cin>>x;
        ans=0x3f3f3f3f3f3f3f3f;
        sum=0;
        for(int j=(cost.size()-1);j>=0;j--) {
            if(x>=cost[j].se) {
                sum+=(cost[j].fi*(x/cost[j].se));
                x%=cost[j].se;
            }
            int tmp=(sum+cost[j].fi);
            if(x==0) {
                tmp-=cost[j].fi;
            }
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TT=1;
    //cin>>TT;
    while(TT--) {
        solve();
    }
    return 0;
}