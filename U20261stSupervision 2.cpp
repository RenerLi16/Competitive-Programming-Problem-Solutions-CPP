#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back

const int MOD=1e9+7;
const int maxn=1e6+10;

int N,D,f[maxn],ans;
vi A,B;

struct XDS{
    #define lson (x<<1)
    #define rson ((x<<1)+1)
    #define mid ((l+r)>>1)
    int sum[maxn<<2],tag[maxn<<2][2];
    void Update(int x) {
        sum[x]=(sum[lson]+sum[rson])%MOD;
    }
    void AddTag(int x,int l,int r,int t1,int t2) {
        sum[x]=(sum[x]*t1+(r-l+1)*t2)%MOD;
        tag[x][0]=(tag[x][0]*t1)%MOD;
        tag[x][1]=((tag[x][1]*t1)+t2)%MOD;
    }
    void Build(int x,int l,int r) {
        tag[x][0]=1, tag[x][1]=0;
        if(l==r) {
            return;
        }
        Build(lson,l,mid);
        Build(rson,(mid+1),r);
        Update(x);
    }
    void Add(int x,int l,int r,int s,int t,int t1,int t2) {
        if(l>=s && r<=t) {
            AddTag(x,l,r,t1,t2);
            return;
        }
        AddTag(lson,l,mid,tag[x][0],tag[x][1]);
        AddTag(rson,(mid+1),r,tag[x][0],tag[x][1]);
        tag[x][0]=1,tag[x][1]=0;
        if(s<=mid) {
            Add(lson,l,mid,s,t,t1,t2);
        }
        if(t>mid) {
            Add(rson,(mid+1),r,s,t,t1,t2);
        }
        Update(x);
    }
    int Ask(int x,int l,int r,int s,int t) {
        if(l>=s && r<=t) {
            return sum[x];
        }
        AddTag(lson,l,mid,tag[x][0],tag[x][1]);
        AddTag(rson,(mid+1),r,tag[x][0],tag[x][1]);
        tag[x][0]=1,tag[x][1]=0;
        int res=0;
        if(s<=mid) {
            res=(res+Ask(lson,l,mid,s,t));
        }
        if(t>mid) {
            res=(res+Ask(rson,(mid+1),r,s,t));
        }
        res=(res%MOD);
        return res;
    }
    #undef lson
    #undef rson
    #undef mid
} xt;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>D;
    xt.Build(1,1,N);
    A.pb(0);
    for(int i=1;i<=N;i++) {
        int x,type;
        cin>>x>>type;
        if(type==1) {
            A.pb(x);
        } else {
            B.pb(x);
        }
    }
    B.pb(2e9);
    int pos=0;
    //return;
    for(int i=0;i<B.size();i++) {
        while((pos+1)<A.size() && A[pos+1]<B[i]) {
            pos++;
            int cursum=0;
            if(pos!=1) {
                cursum=xt.Ask(1,1,N,1,(pos-1));
            }
            //debug(cursum);
            //return;
            xt.Add(1,1,N,pos,pos,1,((cursum+1)%MOD));
        }
        int lb=(lower_bound(A.begin(),A.end(),(B[i]-D))-A.begin());
        if(pos>0) {
            xt.Add(1,1,N,lb,pos,2,0);
        }
    }
    ans=xt.Ask(1,1,N,1,(A.size()-1));
    //ans--;
    cout<<ans<<endl;
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