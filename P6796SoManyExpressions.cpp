#include <iostream>
using namespace std;
using ll=long long;
const int MOD=998244353;
const int maxn=1e5+10;
int n;
ll a[maxn],ans;
char c[maxn];
int main() {
    cin>>n;
    for(int i=1;i<n;i++) {
        cin>>a[i]>>c[i];
    }
    cin>>a[n];
    bool hasmul=0;
    ll mul=1,sum=0;
    for(int i=1;i<=n;i++) {
        if(hasmul) {
            mul=(mul*a[i]+a[i])%MOD;
        } else {
            mul=(i*a[i])%MOD;
        }
        hasmul=1;
        ans=(ans+mul+sum)%MOD;
        if(c[i]=='+') {
            hasmul=0;
            sum=(sum+mul)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}