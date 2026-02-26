#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 5000005; // Increased limit to handle max A, B, G, O <= 1e6
const int MOD = 998244353;
static ll fact[MAXN+1], ifact[MAXN+1];

// Fast exponentiation: computes x^e mod MOD
ll modpow(ll x, ll e) {
    ll res = 1;
    x %= MOD;
    while (e > 0) {
        if (e & 1) res = res * x % MOD;
        x = x * x % MOD;
        e >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void init_combinatorics() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i-1] * i % MOD;
    // Fermat's little theorem for inverse factorial
    ifact[MAXN] = modpow(fact[MAXN], MOD-2);
    for (int i = MAXN; i > 0; --i)
        ifact[i-1] = ifact[i] * i % MOD;
}

// Compute C(n, k) mod MOD
ll nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}


ll A,B,G,O,ans,n;
int main() {
    init_combinatorics();
    cin>>A>>O>>B>>G;
    n=A+B;
    for(int i=1;i<=B+1;i++) {
//        cout<<G+i-1<<" "<<i<<" "<<n-i+O+3<<" "<<n-i+3<<endl;
        ll numG=nCr(G+i-2,i-1),numO=nCr(n-i+O+1,n-i+1);
//        cout<<numG<<" "<<numO<<endl;
        ans=(ans+numG*numO)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
