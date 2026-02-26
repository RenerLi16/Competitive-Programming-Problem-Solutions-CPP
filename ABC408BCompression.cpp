#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<int> vc;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        vc.push_back(x);
    }
    sort(vc.begin(),vc.end());
    auto last=unique(vc.begin(),vc.end());
    vc.erase(last,vc.end());
    cout<<vc.size()<<endl;
    for(int i=0;i<vc.size();i++) {
        cout<<vc[i]<<" ";
    }
    cout<<endl;
    return 0;
}