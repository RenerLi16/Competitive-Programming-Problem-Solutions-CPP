#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e5+10;
const int maxval=2e5+10;
int f[maxval],N,a[maxn];
vector<int> res;
int main() {
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=N;i++) {
        for(int st=0;st<512;st++) {
            if(f[a[i]^st]<a[i]) {
//                if(st==504) {
//                    cout<<"WTF"<<endl;
//                    cout<<a[i]<<" "<<(a[i]^st)<<" "<<f[a[i]^st]<<endl;
//                }
                f[st]=min(f[st],a[i]);
            }
//            if(i==1 && st==4) {
//                cout<<(a[i]^st)<<" "<<f[a[i]^st]<<" "<<a[i]<<endl;
//                cout<<f[st]<<endl;
//            }
        }
    }
//    cout<<f[504]<<endl;
    for(int st=0;st<512;st++) {
        if(f[st]<f[114514]) {
            res.push_back(st);
        }
    }
    cout<<(res.size())<<endl;
    for(auto it:res) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}