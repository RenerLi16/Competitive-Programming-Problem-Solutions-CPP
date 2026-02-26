#include <iostream>
#include <cstring>
#include <algorithm>
//#define TEST
using namespace std;
using ll=long long;
const int maxn=15;
ll lbound,rbound;
int f[maxn][maxn][maxn][4][2];
//As for here no "zero" axis is needed since phone numbers are all valid.
int solve(ll tar) {
    //init
    memset(f,0,sizeof(f));
    //decomp
    int dgt[maxn]={}, numlen=0;
    while(tar) {
        dgt[++numlen]=tar%10;
        tar/=10;
    }
    reverse(dgt+1,dgt+12);
    /*#ifdef TEST
    for(int i=1;i<=11;i++) {
        cout<<dgt[i]<<endl;
    }
    cout<<endl;
    #endif*/
    //DP
    f[0][0][0][0][1]=1;
    for(int i=0;i<11;i++) {
        for(int j=0;j<=9;j++) {
            for(int len=0;len<=3;len++) {
                for(int st=0;st<4;st++) {
                    for(int lim=0;lim<2;lim++) {
                        if(f[i][j][len][st][lim]==0) {
                            continue;
                        }
                        int curlim=(lim ? dgt[i+1] : 9);
                        for(int nxt=0;nxt<=curlim;nxt++) {
                            int newlen=len,newst=st,newlim=0;
                            if(nxt==j && newlen<3) {
                                newlen++;
                            } else if (newlen!=3) {
                                newlen=1;
                            }
                            if(nxt==4) {
                                newst|=1;
                            }
                            if(nxt==8) {
                                newst|=2;
                            }
                            if(lim && nxt==curlim) {
                                newlim=1;
                            }
                            f[i+1][nxt][newlen][newst][newlim]+=f[i][j][len][st][lim];
                        }
                    }
                }
            }
        }
    }
    #ifdef TEST
    for(int i=0;i<=9;i++) {
        for(int len=0;len<4;len++) {
            cout<<f[2][i][len][0][0]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=9;i++) {
        for(int len=0;len<=3;len++) {
            cout<<f[2][i][len][0][1]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    #endif
    //get answer
    int res=0;
    for(int i=0;i<=9;i++) {
        for(int st=0;st<3;st++) {
            for(int lim=0;lim<2;lim++) {
                res+=f[11][i][3][st][lim];
            }
        }
    }
    return res;
}
int main() {
    cin>>lbound>>rbound;
    cout<<(solve(rbound)-solve(lbound-1))<<endl;
    return 0;
}