#include <iostream>
#define int long long
using namespace std;
const int maxn=4e5+10;
int f[maxn*2],lst[maxn*2],n,a[maxn*2],V[maxn*2];
struct SegmentTree {
    int siz,mx[maxn*8],tag[maxn*8];
    int LS(int x) {
        return x*2;
    }
    int RS(int x) {
        return x*2+1;
    }
    void PushUp(int id) {
        mx[id]=max(mx[LS(id)],mx[RS(id)]);
    }
    void AddTag(int id,int val) {
        tag[id]=max(tag[id],val);
        mx[id]=max(mx[id],tag[id]);
    }
    void PushDown(int id, int lbound, int rbound) {
        if(tag[id]) {
            AddTag(LS(id),tag[id]);
            AddTag(RS(id),tag[id]);
            tag[id]=0;
        }
    }
    void Build(int id, int lcur, int rcur) {
        tag[id]=0;
        if(lcur==rcur) {
            mx[id]=a[lcur];
            return;
        }
        int mid=(lcur+rcur)/2;
        Build(LS(id),lcur,mid);
        Build(RS(id),mid+1,rcur);
        PushUp(id);
    }
    void SegmentModify(int lbound, int rbound, int id, int lcur, int rcur,int val) {
        if (rbound < lcur || lbound > rcur) 
            return;
        if(lbound<=lcur && rbound>=rcur) {
            AddTag(id,val);
            return;
        } else {
            PushDown(id, lcur, rcur);
            int mid=(lcur+rcur)/2;
            SegmentModify(lbound,rbound,LS(id),lcur,mid,val);
            SegmentModify(lbound,rbound,RS(id),mid+1,rcur,val);
        }
        PushUp(id);
    }
    int GetMax(int lbound, int rbound, int id, int lcur, int rcur) {
        if(lcur>=lbound && rbound>=rcur) {
            return mx[id];
        }
        PushDown(id,lcur,rcur);
        int ret=0;
        int mid=(lcur+rcur)/2;
        if(mid>=lbound) {
            ret=max(ret,GetMax(lbound,rbound,LS(id),lcur,mid));
        }
        if(rbound>mid) {
            ret=max(ret,GetMax(lbound,rbound,RS(id),mid+1,rcur));
        }
        return ret;
    }
} segt;
signed main() {
    cin>>n;
    n*=2;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n/2;i++) {
        cin>>V[i];
    }
    for(int i=1;i<=n;i++) {
        f[i]=f[i-1];
        if(!lst[a[i]]) {
            lst[a[i]]=i;
            continue;
        }
        f[i]=max(f[i-1],f[lst[a[i]]-1]+V[a[i]]);
        f[i]=max(f[i],segt.GetMax(lst[a[i]],lst[a[i]],1,1,n)+V[a[i]]);
        segt.SegmentModify(lst[a[i]],i,1,1,n,f[lst[a[i]]-1]+V[a[i]]);
    }
    cout<<f[n]<<endl;
    return 0;
}