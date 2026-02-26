#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back

const int maxn=1e6+10;
const int maxcrit=1e5+10;

int N,C,f[maxn],parr[maxn],pstart[maxn],plen[maxn],crit[maxn],qsum,ans[maxn];
priority_queue<int> hip[maxcrit];

void HipInsert(int x) {
    int mnc=1;
    int cur=x;
    while(true) {
        int l=(pstart[cur]);
        int r=(pstart[cur]+plen[cur]);
        auto pos=lower_bound(crit+l,crit+r,mnc);
        if(pos==(crit+r)) {
            return;
        }
        if(hip[*pos].size()<f[*pos]) {
            hip[*pos].push(cur);
            qsum+=cur;
            return;
        }
        int mx=hip[*pos].top();
        if(cur<mx) {
            hip[*pos].pop();
            hip[*pos].push(cur);
            qsum+=(cur-mx);
            cur=mx;
            mnc=(*pos+1);
        } else {
            mnc=(*pos+1);
        }
    }
}

void solve() {
    //Initialization
    //Input
    cin>>N>>C;
    for(int i=1;i<=C;i++) {
        cin>>f[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>parr[i];
    }
    int pos=0;
    for(int i=1;i<=N;i++) {
        int ni;
        cin>>ni;
        pstart[i]=pos;
        plen[i]=ni;
        for(int j=0;j<ni;j++) {
            cin>>crit[pos++];
        }
        sort(crit+pstart[i],crit+pstart[i]+plen[i]);
    }
    for(int i=(N-1);i>=0;i--) {
        int cur=parr[i+1];
        HipInsert(cur);
        ans[i]=qsum;
    }
    for(int i=0;i<N;i++) {
        cout<<ans[i]<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TT=1;
    //cin>>TT>>C;
    while(TT--) {
        solve();
    }
    return 0;
}