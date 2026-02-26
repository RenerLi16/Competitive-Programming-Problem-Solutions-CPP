#include <iostream>
using namespace std;
const int maxn=1e5+10;
const int maxm=35;
int dist[maxm][maxm],cost[maxn][maxm],f[maxn],n,m,k;
char s[maxn];
void Floyed() {
    for(int k=1;k<=m;k++) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void InitCost() {
    for(int i=1;i<=m;i++) {
    }
}
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            cin>>dist[i][j];
        }
    }
    Floyed();
    InitCost();
}