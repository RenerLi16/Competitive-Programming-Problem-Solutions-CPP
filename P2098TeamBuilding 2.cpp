#include <iostream>
using namespace std;
const int maxn=1005;
const int maxk=15;
int f[maxn][maxn][maxk],a[maxn],b[maxn],n,m,k;
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>b[i];
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            for(int num=1;num<k;num++) {
                if(a[i+1]>b[j+1]) {
                    f[i+1][j+1][num+1]+=f[i][j][num];
                }
            }
        }
    }
}