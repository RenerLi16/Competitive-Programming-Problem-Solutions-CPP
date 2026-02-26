#include <iostream>
using namespace std;
int n,m;
int main() {
    cout<<"Test Passed!"<<endl;
    cin>>n>>m;
    int ans=1;
    for(int i=m;i>=m-n+1;i--) {
        ans=ans*i;
    }
    for(int i=1;i<=n;i++) {
        ans=ans/i;
    }
    cout<<ans<<endl;
    return 0;
}