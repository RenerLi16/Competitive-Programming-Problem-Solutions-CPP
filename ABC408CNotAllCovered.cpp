#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+10;
struct Node {
    int l,r;
    friend bool operator < (Node first, Node second) {
        return first.l<second.l || (first.l==second.l && first.r<second.r);
    }
} pool[maxn];
int n,m,ans=INF;
queue<int> q;
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>pool[i].l>>pool[i].r;
    }
    sort(pool+1,pool+m+1);/*
    for(int i=1;i<=m;i++) {
        cout<<pool[i].l<<" "<<pool[i].r<<endl;
    }*/
    int cursz=0;
    for(int i=1;i<=m;i++) {
        while(!q.empty() && q.front()<pool[i].l) {
            q.pop();
            cursz--;
        }
        ans=(i==1 || pool[i].l==pool[i-1].l) ? ans : min(ans,cursz);
        q.push(pool[i].r);
        cursz++;
//        cout<<cursz<<endl;
    }
    ans=min(ans,cursz);
    cout<<ans<<endl;
    return 0;
}