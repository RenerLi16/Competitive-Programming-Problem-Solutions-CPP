#include <iostream>
using namespace std;
const int maxn=1e5+10;
struct FenwickTree {
    int t[maxn], siz;
    int lowbit(int x) {
        return x&(-x);
    }
    void modify(int id, int x) {
        for(;id<=siz;id+=lowbit(id)) {
            if(t[id]>=x) {
                return;
            } else {
                t[id]=x;
            }
        }
    }
    int getmx(int id) {
        int ret=0;
        for(;id;id-=lowbit(id)) {
            ret=max(ret,t[id]);
        }
        return ret;
    }
}ft;
int f[maxn],a[maxn],b[maxn],n;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        b[x]=i;
    }
    ft.siz=n;
    for(int i=1;i<=n;i++) {
        for(int j=max(1,a[i]-4);j<=min(n,a[i]+4);j++) {
            f[j]=ft.getmx(b[j]-1);
        }
        for(int j=max(1,a[i]-4);j<=min(n,a[i]+4);j++) {
            ft.modify(b[j],f[j]+1);
        }
    }
    cout<<(ft.getmx(n))<<endl;
    return 0;
}