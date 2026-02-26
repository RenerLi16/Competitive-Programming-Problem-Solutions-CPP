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

#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2005;

int N,A[maxn],Q;
int num=0;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=1;i<=N;i++) {
        int mx=0;
        for(int j=i+1;j<=N;j++) {
            if(((A[i]+A[j]))>=(2*mx)) {
                num++;
            }
            mx=max(mx,A[j]);
        }
    }
    debug(num);
    cin>>Q;
    while(Q--) {
        int x,y;
        cin>>x>>y;
        int cnt1=0,cnt2=0,mx=0;
        //前
        //以当前点作为端点总数
        for(int i=x-1;i>=1;i--) {
            if((A[x]+A[i])>=(2*mx)) {
                cnt1++;
            }
            mx=max(mx,A[i]);
        }
        mx=0;
        for(int j=x+1;j<=N;j++) {
            if((A[x]+A[j])>=(2*mx)) {
                cnt1++;
            }
            mx=max(mx,A[j]);
        }
        debug(cnt1);
        //处理左右区间，分别加入数组tmp1与tmp2
        vector<int> tmp1,tmp2;
        tmp1.clear();
        tmp2.clear();
        int pos1=(x-1);
        for(;pos1>=1;pos1--) {
            if(A[pos1]>=A[x]) {
                break;
            }
        }
        if(A[pos1]<(A[x]+y)) {
            pos1--;
        }
        for(;pos1>=1;pos1--) {
            tmp1.push_back(A[pos1]);
            if(A[pos1]>=(A[x]+y)) {
                break;
            }
        }
        int pos2=(x+1);
        for(;pos2<=N;pos2++) {
            if(A[pos2]>=A[x]) {
                break;
            }
        }
        if(A[pos2]<(A[x]+y)) {
            pos2++;
        }
        for(;pos2<=N;pos2++) {
            tmp2.push_back(A[pos2]);
            if(A[pos2]>=(A[x]+y)) {
                break;
            }
        }
        for(int it:tmp1) {
            cout<<it<<" ";
        }
        cout<<endl;
        for(int it:tmp2) {
            debug(it);
        }
        //二分找位置处理先后夸当前值区间的数量
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());

        for(int i=0;i<tmp1.size();i++) {
            int pos=lower_bound(tmp2.begin(),tmp2.end(),max(((2*(A[x]))-tmp1[i]),0))-tmp2.begin();
            if(pos<tmp2.size() && max(((2*(A[i]))-tmp1[i]),0)<tmp2[pos]) {
                pos--;
            }
            debug(i,pos);
            cnt1=(cnt1+tmp2.size()-pos);
        }
        for(int i=0;i<tmp2.size();i++) {
            int pos=lower_bound(tmp1.begin(),tmp1.end(),max(((2*(A[x]+y))-tmp2[i]),0))-tmp1.begin();
            if(!tmp1.empty()) {
                debug(tmp1[pos]);
            }
            if(pos<tmp1.size() && max(((2*(A[x]+y))-tmp2[i]),0)<tmp1[pos]) {
                pos--;
            }
            debug(i,pos);
            cnt2=(cnt2+tmp1.size()-pos);
        }
        //后：当前点作为端点
        mx=0;
        for(int i=x-1;i>=1;i--) {
            if((A[x]+y+A[i])>=(2*mx)) {
                cnt2++;
            }
            mx=max(mx,A[i]);
        }
        mx=0;
        for(int j=x+1;j<=N;j++) {
            if((A[x]+y+A[j])>=(2*mx)) {
                cnt2++;
            }
            mx=max(mx,A[j]);
        }
        debug(cnt1,cnt2);
        num=(num+cnt2-cnt1);
        cout<<num<<endl;
        A[x]=(A[x]+y);
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