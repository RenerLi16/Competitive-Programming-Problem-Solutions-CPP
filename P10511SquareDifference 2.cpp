#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long

const int MOD = 998244353;
const int N = 1e6 + 5;

// Clean modular integer type
struct ModInt {
    int v;
    ModInt(long long _v = 0) { 
        v = (_v % MOD + MOD) % MOD; 
    }
    ModInt operator+(const ModInt& other) const { return ModInt(v + other.v); }
    ModInt operator-(const ModInt& other) const { return ModInt(v - other.v); }
    ModInt operator*(const ModInt& other) const { return ModInt(v * other.v); }
    ModInt& operator+=(const ModInt& other) { v = (v + other.v) % MOD; return *this; }
    ModInt& operator-=(const ModInt& other) { v = (v - other.v + MOD) % MOD; return *this; }
    ModInt& operator*=(const ModInt& other) { v = (v * other.v) % MOD; return *this; }
};

int n, m, q;
int L[N], R[N];
ModInt B[N], prefixSum1[N], prefixSum2[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    // Read segments [L[i], R[i]] with value B[i]
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        L[i] = x;
        R[i] = y;
        B[i] = z;
    }

    // Precompute prefix sums of value * length and value^2 * length
    for (int i = 1; i <= m; i++) {
        ModInt len = R[i] - L[i] + 1;
        prefixSum1[i] = prefixSum1[i - 1] + B[i] * len;
        prefixSum2[i] = prefixSum2[i - 1] + B[i] * B[i] * len;
    }

    while (q--) {
        int left, right;
        cin >> left >> right;

        // Find segment indices x, y containing left and right
        int x = upper_bound(L + 1, L + m + 1, left) - L - 1;
        int y = upper_bound(L + 1, L + m + 1, right) - L - 1;

        ModInt sum1, sum2;

        if (x != y) {
            // Sum between segments
            sum1 = (prefixSum1[y - 1] - prefixSum1[x]) 
                 + B[x] * (R[x] - left + 1)
                 + B[y] * (right - L[y] + 1);

            sum2 = (prefixSum2[y - 1] - prefixSum2[x]) 
                 + B[x] * B[x] * (R[x] - left + 1)
                 + B[y] * B[y] * (right - L[y] + 1);
        } else {
            // Same segment
            ModInt len = right - left + 1;
            sum1 = B[x] * len;
            sum2 = B[x] * B[x] * len;
        }

        // Compute result: sum2 * len - sum1^2
        ModInt len = right - left + 1;
        cout << (sum2 * len - sum1 * sum1).v << '\n';
    }
    return 0;
}
