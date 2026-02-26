#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll INF = (1LL << 62);

struct IntervalC {
    int s;
    int e;
    ll c;
};

static vector<ll> solve_direction(const vector<int>& B, int N, int D) {
    int M = (int)B.size();
    vector<int> minR(M, -1);

    vector<int> cnt(D, 0);
    int have = 0;
    int r = 0; // window is [l, r)
    for (int l = 0; l < M; l++) {
        if (r < l) r = l;
        while (have < D && r < M && r < l + N) {
            int v = B[r];
            if (cnt[v] == 0) have++;
            cnt[v]++;
            r++;
        }
        if (have == D) minR[l] = r - 1;
        int v = B[l];
        cnt[v]--;
        if (cnt[v] == 0) have--;
    }
    vector<vector<pair<ll,int>>> startsPlus(M), startsMinus(M);
    for (int l = 0; l < M; l++) {
        int rr = minR[l];
        if (rr == -1) continue;
        int m = (l + rr) / 2;
        ll c1 = (ll)rr - 2LL * l;
        startsPlus[l].push_back({c1, m});
        if (m + 1 <= rr) {
            ll c2 = 2LL * rr - (ll)l;
            startsMinus[m + 1].push_back({c2, rr});
        }
    }
    auto aaa = [&](const vector<vector<pair<ll,int>>>& starts) {
        vector<ll> best(M, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        for (int i = 0; i < M; i++) {
            for (auto &p : starts[i]) pq.push({p.first, p.second});
            while (!pq.empty() && pq.top().second < i) pq.pop();
            if (!pq.empty()) best[i] = pq.top().first;
        }
        return best;
    };
    vector<ll> bestC1 = aaa(startsPlus);
    vector<ll> bestC2 = aaa(startsMinus);
    vector<ll> ansTurn(M, INF);
    for (int i = 0; i < M; i++) {
        ll v = INF;
        if (bestC1[i] < INF) v = min(v, bestC1[i] + (ll)i);
        if (bestC2[i] < INF) v = min(v, bestC2[i] - (ll)i);
        ansTurn[i] = v;
    }
    vector<vector<pair<int,int>>> startsOne(M);
    for (int l = 0; l < M; l++) {
        int rr = minR[l];
        if (rr == -1) continue;
        int end = min(M - 1, l + N - 1);
        if (rr <= end) startsOne[rr].push_back({end, l});
    }
    vector<ll> ansOne(M, INF);
    priority_queue<pair<int,int>> pq;
    for (int j = 0; j < M; j++) {
        for (auto &it : startsOne[j]) {
            int end = it.first, l = it.second;
            pq.push({l, end});
        }
        while (!pq.empty() && pq.top().second < j) pq.pop();
        if (!pq.empty()) {
            int bestL = pq.top().first;
            ansOne[j] = (ll)j - bestL;
        }
    }
    vector<ll> ans(M, INF);
    for (int i = 0; i < M; i++) ans[i] = min(ansTurn[i], ansOne[i]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> vals = A;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int D = (int)vals.size();

    if (D == 1) {
        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << 0;
        }
        cout << "\n";
        return 0;
    }

    int M = 2 * N;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        int v = A[i % N];
        B[i] = (int)(lower_bound(vals.begin(), vals.end(), v) - vals.begin());
    }
    vector<ll> ansF = solve_direction(B, N, D);
    vector<int> Brev = B;
    reverse(Brev.begin(), Brev.end());
    vector<ll> ansRrev = solve_direction(Brev, N, D);
    vector<ll> ansR(M, INF);
    for (int i = 0; i < M; i++) ansR[i] = ansRrev[M - 1 - i];
    vector<ll> ans(M, INF);
    for (int i = 0; i < M; i++) ans[i] = min(ansF[i], ansR[i]);
    for (int i = 0; i < N; i++) {
        ll res = min(ans[i], ans[i + N]);
        if (i) cout << ' ';
        cout << res;
    }
    cout << "\n";
    return 0;
}
