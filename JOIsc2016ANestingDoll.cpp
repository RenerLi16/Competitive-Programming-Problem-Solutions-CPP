#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2e5+10;
int f[maxn],g[maxn],ans[maxn],N,Q,pos=1,tot;
struct Node {
    int A,B,id;
    friend bool operator < (Node first, Node second) {
        return first.A>second.A || (first.A==second.A && first.B<second.B);
    }
} a[maxn],q[maxn];
int main() {
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>a[i].A>>a[i].B;
    }
    for(int i=1;i<=Q;i++) {
        cin>>q[i].A>>q[i].B;
        q[i].id=i;
    }
    sort(a+1,a+N+1);
    sort(q+1,q+Q+1);
    for(int i=1;i<=Q;i++) {
        while(pos<=N && a[pos].A>=q[i].A) {
            int curlen=upper_bound(g+1,g+tot+1,a[pos].B)-g;
            tot=max(tot,curlen);
            g[curlen]=a[pos].B;
            pos++;
        }
        ans[q[i].id]=upper_bound(g+1,g+tot+1,q[i].B)-g-1;
    }
    for(int i=1;i<=Q;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}