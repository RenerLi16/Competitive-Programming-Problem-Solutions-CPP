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
#else
#define debug(x...) 
#define systemwait
#endif

#define int long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

struct Node {
    int a,c,ind;
    friend bool operator <(Node first,Node second) {
        return first.c<second.c || (first.c==second.c && first.ind<second.ind);
    }
} pool[maxn];

int N,Q;
int presum[maxn],delta[maxn],dtot,lb[maxn],rb[maxn];

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>pool[i].a;
        pool[i].ind=i;
    }
    for(int i=1;i<=N;i++) {
        cin>>pool[i].c;
    }
    sort(pool+1,pool+N+1);
    for(int i=1;i<=N;i++) {
        if(pool[i].c!=pool[i-1].c) {
            lb[pool[i].c]=i;
            rb[pool[i-1].c]=i-1;
            presum[i]=pool[i].a;
        } else {
            presum[i]=(presum[i-1]+pool[i].a);
        }
    }
    rb[pool[N].c]=N;
    // for(int i=1;i<=N;i++) {
    //     cout<<presum[i]<<" ";
    // }
    // cout<<endl;
    cin>>Q;
    while(Q--) {
        int type,cor,x;
        cin>>type>>cor>>x;
        if(type==2) {
            int l=lb[cor],r=rb[cor];
            while(l<=r) {
                int mid=((l+r)/2);
                debug(mid,(mid-lb[cor]+1),(dtot-delta[cor]));
                if((presum[mid]+((mid-lb[cor]+1)*(dtot-delta[cor])))<=x) {
                    l=mid+1;
                } else {
                    r=mid-1;
                }
            }
            debug(r);
            cout<<max(0ll,(r-lb[cor]+1))<<endl;
        } else {
            dtot+=x;
            delta[cor]+=x;
        }
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    //cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}