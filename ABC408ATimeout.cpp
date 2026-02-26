#include <iostream>
using namespace std;
const int maxn=105;
int n,s,t[maxn];
int main() {
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        cin>>t[i];
    }
    for(int i=2;i<=n;i++) {
        if(t[i]>=t[i-1]+s+0.5) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}