#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back

const int maxn=5e5+10;

int N,C;
char l[maxn],r[maxn];
vi pool[4],seq;
string ans;
//0: JJ
//1: JN
//2: NN
//3: NJ

void solve() {
    //Initialization
    for(int i=0;i<4;i++) {
        pool[i].clear();
    }
    seq.clear();
    ans.clear();
    //Input
    cin>>N;
    cin>>(l+1);
    cin>>(r+1);
    for(int i=1;i<=N;i++) {
        if(l[i]=='J' && r[i]=='J') {
            pool[0].pb(i);
        } else if(l[i]=='J' && r[i]=='N') {
            pool[1].pb(i);
        } else if(l[i]=='N' && r[i]=='N') {
            pool[2].pb(i);
        } else if(l[i]=='N' && r[i]=='J') {
            pool[3].pb(i);
        }
    }
    if(pool[1].size()!=pool[3].size()
     || (!pool[0].empty() && !pool[2].empty() && pool[1].empty())
     || ((pool[1].size()+pool[2].size())%2)!=0) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(C==1) {
        for(auto it:pool[0]) {
            seq.pb(it);
        }
        if(!pool[1].empty()) {
            seq.pb(pool[1][0]);
        }
        for(auto it:pool[2]) {
            seq.pb(it);
        }
        if(!pool[3].empty()) {
            seq.pb(pool[3][0]);
        }
        for(int i=1;i<pool[1].size();i++) {
            seq.pb(pool[1][i]);
            seq.pb(pool[3][i]);
        }
        int cur=0;
        for(int i=0;i<N;i++) {
            if(cur==0) {
                ans.pb('J');
            } else {
                ans.pb('N');
            }
            if(r[seq[i]]=='N') {
                cur^=1;
            }
        }
        for(int i=0;i<seq.size();i++) {
            if(i!=0) {
                cout<<" ";
            }
            cout<<seq[i];
        }
        cout<<endl;
        cout<<ans<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TT=1;
    cin>>TT>>C;
    while(TT--) {
        solve();
    }
    return 0;
}