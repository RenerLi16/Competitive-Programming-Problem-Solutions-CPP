#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
using namespace std;

#define pb push_back
#define int long long

const int maxn=20;

int N,K,f[maxn][(1<<maxn)+10],ans,cnt,tot;
vector<tuple<int,int,int>> qryl,qryr,qryc;

void solve() {
    //Initialization
    cnt=1;
    //Input
    cin>>N>>K;
    for(int i=1;i<=K;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        z--;
        f[x][(1<<y)|(1<<z)]++;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int S=0;S<(1<<N);S++) {
                if(S&(1<<j)) {
                    f[i][S]+=f[i][S^(1<<j)];
                }
            }
        }
    }
    int ALL=((1<<N)-1);
    for(int S=0;S<(1<<N);S++) {
        int num=0;
        for(int T=S;T;T&=(T-1)) {
            int tmp=__builtin_ctz(T);
            num+=f[tmp][ALL^S];
        }
        if(num==ans) {
            cnt++;
        }
        if(num>ans) {
            ans=num;
            cnt=1;
        }
    }
    cout<<ans<<" "<<cnt<<endl;
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