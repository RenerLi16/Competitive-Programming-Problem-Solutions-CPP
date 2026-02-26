#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        string r;
        cin >> r; // length = N-K+1

        int m = (int)r.size();
        vector<int> rb(m + 1, 0);
        for (int i = 1; i <= m; i++) rb[i] = r[i - 1] - '0';

        // d[i] = r_i xor r_{i+1}, for i=1..N-K (i=1..m-1)
        vector<int> d(N + 1, 0);
        for (int i = 1; i <= m - 1; i++) d[i] = rb[i] ^ rb[i + 1];

        // val[i] = known xor from chain head to position i (so b_i = x_head xor val[i])
        vector<int> val(N + 1, 0);
        for (int i = K + 1; i <= N; i++) {
            // relates b_{i-K} and b_i by d[i-K]
            val[i] = val[i - K] ^ d[i - K];
        }

        const long long INF = (1LL << 60);
        long long dpMin[2] = {0, INF};
        long long dpMax[2] = {0, -INF};

        for (int c = 1; c <= K; c++) {
            long long len = 0, cnt1 = 0;
            for (int i = c; i <= N; i += K) {
                len++;
                cnt1 += val[i];
            }
            long long cost0 = cnt1;
            long long cost1 = len - cnt1;

            long long ndpMin[2] = {INF, INF};
            long long ndpMax[2] = {-INF, -INF};

            for (int p = 0; p <= 1; p++) {
                if (dpMin[p] < INF) {
                    ndpMin[p ^ 0] = min(ndpMin[p ^ 0], dpMin[p] + cost0);
                    ndpMin[p ^ 1] = min(ndpMin[p ^ 1], dpMin[p] + cost1);
                }
                if (dpMax[p] > -INF) {
                    ndpMax[p ^ 0] = max(ndpMax[p ^ 0], dpMax[p] + cost0);
                    ndpMax[p ^ 1] = max(ndpMax[p ^ 1], dpMax[p] + cost1);
                }
            }
            dpMin[0] = ndpMin[0]; dpMin[1] = ndpMin[1];
            dpMax[0] = ndpMax[0]; dpMax[1] = ndpMax[1];
        }

        int need = rb[1]; // xor of first K bits must equal r1
        cout << dpMin[need] << " " << dpMax[need] << "\n";
    }
    return 0;
}
