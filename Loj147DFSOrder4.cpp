
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <tuple>
#include <stack>
#include <numeric>
#include <climits>
#include <deque>
#include <chrono>
#include <unordered_map>
#include <cstring>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define systemwait system("read -p \"Press Enter to continue...\"");
#define debugbreak exit(0)
#else
#define debug(x...)
#define systemwait
#define debugbreak
#endif

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second
using namespace std;
#define lowbit(x) ((x)&-(x))
#define ll long long
const int logsz = 21;
const int sz = 1e6 + 19;
const int esz = 2e6 + 19;
int n, q, root, arr[sz], head[sz], hpp = 0;
inline int read() {
    ll x = 0, f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * f;
}
struct edge {
    int nxt, to;
} graph[esz];
void addEdge(int from, int to) {
    graph[++hpp] = edge{head[from], to};
    head[from] = hpp;
}
int dpp = 0, dep[sz], dfn[sz], outid[sz], f[logsz][sz];
void DFS(int u, int fau) {
    ++dpp, dep[u] = dep[fau] + 1, dfn[u] = dpp, f[0][dpp] = fau;

    for (int p = head[u]; p != 0; p = graph[p].nxt) {
        int v = graph[p].to;

        if (v == fau)
            continue;

        DFS(v, u);
    }

    outid[u] = dpp;
}
int depmin(int u, int v) {
    return (dep[u] < dep[v]) ? (u) : (v);
}
int LCA(int u, int v) {
    if (u == v)
        return u;

    int du = dfn[u], dv = dfn[v];

    if (du > dv)
        swap(du, dv);

    int s = __lg(dv - du);
    return depmin(f[s][du + 1], f[s][dv - (1 << s) + 1]);
}
struct BinaryIndexedTree {
    ll tree1[sz], tree2[sz];
    void add(int ln, ll val) {
        if (ln == 0)
            return;

        for (int cx = ln; cx <= n; cx += lowbit(cx))
            tree2[cx] += val;
    }
    void add(int p, int ln, ll val) {
        if (ln == 0)
            return;

        for (int cx = ln; cx <= n; cx += lowbit(cx))
            tree1[cx] += val, tree2[cx] -= val * (dep[p] - 1);
    }
    ll pQuery(int id) {
        ll res = 0;

        if (id == 0)
            return 0;

        for (int cx = id; cx != 0; cx -= lowbit(cx))
            res += tree1[cx];

        return res;
    }
    ll iQuery(int p, int rn) {
        ll res = 0;

        if (rn == 0)
            return 0;

        for (int cx = rn; cx != 0; cx -= lowbit(cx))
            res += tree2[cx] + tree1[cx] * dep[p];

        return res;
    }
} BIT;
int main() {
    n = read();
    q = read();
    root = read();

    for (int cx = 1; cx <= n; ++cx)
        arr[cx] = read();

    for (int cx = 1, u, v; cx < n; ++cx) {
        u = read();
        v = read();
        addEdge(u, v), addEdge(v, u);
    }

    DFS(root, 0);

    for (int w = 1; w <= __lg(n); ++w)
        for (int cx = 1; cx + (1 << w) - 1 <= n; ++cx)
            f[w][cx] = depmin(f[w - 1][cx], f[w - 1][cx + (1 << (w - 1))]);

    for (int cx = 1; cx <= n; ++cx)
        BIT.add(dfn[cx], arr[cx]), BIT.add(outid[cx] + 1, -arr[cx]);

    for (int cx = 1, opt, a, b, x; cx <= q; ++cx) {
        opt = read();
        a = read();
        x = read();

        if (opt == 1)
            BIT.add(dfn[a], x), BIT.add(outid[a] + 1, -x);
        else if (opt == 2)
            BIT.add(a, dfn[a], x), BIT.add(a, outid[a] + 1, -x);
        else {
            int lca = LCA(a, x), falca = f[0][dfn[lca]];
            printf("%lld\n", (BIT.iQuery(a, dfn[a]) + BIT.iQuery(x, dfn[x]) - BIT.iQuery(lca,
                              dfn[lca]) - BIT.iQuery(falca, dfn[falca])));
        }
    }

    return 0;
}