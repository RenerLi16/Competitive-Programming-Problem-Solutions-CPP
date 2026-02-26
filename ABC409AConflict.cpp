#include <iostream>
using namespace std;
const int maxn=105;
int n;
char s1[maxn],s2[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s1[i];
    }
    for(int i=1;i<=n;i++) {
        char c;
        cin>>c;
        if(c=='o' && s1[i]==c) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}