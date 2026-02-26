#include <iostream>
#define ll long long
using namespace std;
const int maxn=15;
ll a,b;
int dp[maxn][maxn][2][2];
// ith digit; current j; reached limit; all 0.
int solve(int lim) {
    int dcomp[maxn]={},len=0;
    while(lim) {
        dcomp[++len]=lim%10;
        lim/=10;
    }
    for(int i=len;i>=1;i--) {
        for(int j=0;j<dcomp[i];j++) {
            if(j==0) {
                dp[i][0][0][1]+=(dp[i+1][0][0][1]+dp[i+1][0][1][1]);
            }
            for(int p=0;p<=dcomp[i+1];p++) {
                dp[i][j][0][0]+=(dp[i+1][p][0][0]+dp[i+1][p][1][0]+dp[i+1][p][0][1]+dp[i+1][p][1][1]);
            }
        }
        if(dcomp[i]==0) {
            dp[i][0][1][1]+=(dp[i+1][0][0][1]+dp[i+1][0][1][1]);
        }
        for(int j=0;j<=dcomp[i+1];j++) {
            dp[i][dcomp[i]][1][0]+=(dp[i+1][j][0][0]+dp[i+1][j][1][0]+dp[i+1][j][0][1]+dp[i+1][j][1][1]);
        }
    }
    for(int i=1;i<=len;i++) {
        
    }
}
int main() {
    cin>>a>>b;
    cout<<(solve(b)-solve(a-1));
    return 0;
}