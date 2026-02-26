#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define pb push_back

const int maxn=2e5+10;

int N,ans;
pii A[maxn];

struct FWT {
    int pre[maxn];
    void Add(int x, int pos) {
        for(;pos<=N;pos+=(pos&(-pos))) {
            pre[pos]+=x;
        }
    }
    int Ask(int pos) {
        if(pos==0) {
            return 0;
        }
        int res=0;
        for(;pos;pos-=(pos&(-pos))) {
            res+=pre[pos];
        }
        return res;
    }
} ft;

void solve() {
//--------Initiallize--------
    ans=0;
    memset(ft.pre,0,sizeof(ft.pre));
//--------Input--------
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i].fi;
        A[i].se=i;
    }
    sort(A+1,A+N+1);
    int curval=1;
    for(int i=1;i<=N;i++) {
        if(i!=N && A[i].fi!=A[i+1].fi) {
            A[i].fi=curval;
            curval++;
        } else {
            A[i].fi=curval;
        }
    }
    vi bf;
    for(int i=1;i<=N;i++) {
        if(i!=1 && A[i].fi!=A[i-1].fi) {
            while(!bf.empty()) {
                ft.Add(1,bf.back());
                bf.pop_back();
            }
        }
        int curcnt=ft.Ask(A[i].se-1);
        //debug(curcnt,A[i].fi,A[i].se);
        ans+=min(curcnt,((int)((i-1)-curcnt-bf.size())));
        bf.pb(A[i].se);
    }∫
    cout<<ans<<endl;
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}