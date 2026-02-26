#include <bits/stdc++.h>
using namespace std;

#define int long long
#define i128 __int128_t
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define fi first
#define se second

static inline int to_ll(i128 x){return (long long)x;}

static inline i128 floordiv(i128 a,i128 b){
    if(a>=0){return a/b;}
    return -(((-a)+b-1)/b);
}
static inline i128 ceildiv(i128 a,i128 b){
    if(a>=0){return (a+b-1)/b;}
    return -(((-a))/b);
}

static inline i128 getsum(const vector<int>& llist,const vector<int>& rlist,const vector<i128>& prefL,const vector<i128>& prefR,int m){
    int n=(int)llist.size();
    int cntR=(int)(lower_bound(rlist.begin(),rlist.end(),m)-rlist.begin());
    int posL=(int)(upper_bound(llist.begin(),llist.end(),m)-llist.begin());
    return (i128)m*cntR-prefR[cntR]+(prefL[n]-prefL[posL])-(i128)m*(n-posL);
}

static inline int nxtgrd(const vector<int>& llist,const vector<int>& rlist,int m){
    int n=(int)llist.size();
    int cntR=(int)(lower_bound(rlist.begin(),rlist.end(),m)-rlist.begin());
    int posL=(int)(upper_bound(llist.begin(),llist.end(),m)-llist.begin());
    int cntL=n-posL;
    return (int)cntR-(int)cntL;
}

static bool feasible_d(const vector<int>& a,const vector<int>& b,int K,int d){
    int n=(int)a.size();
    vector<int> llist;llist.reserve(n);
    vector<int> rlist;rlist.reserve(n);
    i128 constantNeed=0;
    for(int i=0;i<n;i++){
        i128 p=(i128)a[i]-(i128)d;
        i128 bi=(i128)b[i];
        if(p<=bi){
            llist.push_back(to_ll(p));
            rlist.push_back(b[i]);
        }else{
            constantNeed+=ceildiv(p-bi,2);
            llist.push_back(to_ll(floordiv(p+bi,2)));
            rlist.push_back(to_ll(ceildiv(p+bi,2)));
        }
    }
    sort(llist.begin(),llist.end());
    sort(rlist.begin(),rlist.end());
    vector<i128> prefL(n+1,0),prefR(n+1,0);
    for(int i=0;i<n;i++){
        prefL[i+1]=prefL[i]+(i128)llist[i];
        prefR[i+1]=prefR[i]+(i128)rlist[i];
    }
    int lb=min(llist.front(),rlist.front())-2;
    int rb=max(llist.back(),rlist.back())+2;
    while(lb<rb){
        int mid=lb+(int)(((i128)rb-(i128)lb)/2);
        if(nxtgrd(llist,rlist,mid)>=0){rb=mid;}
        else{lb=mid+1;}
    }
    i128 best=getsum(llist,rlist,prefL,prefR,lb);
    best=min(best,getsum(llist,rlist,prefL,prefR,lb-1));
    return constantNeed+best<=(i128)K;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<int> a(N),b(N);
        for(int i=0;i<N;i++){cin>>a[i];}
        for(int i=0;i<N;i++){cin>>b[i];}
        int rb=*max_element(a.begin(),a.end())-*min_element(b.begin(),b.end());
        i128 lb128=(i128)rb-(i128)2*(i128)K-10;
        int lb=(lb128<(i128)LLONG_MIN?LLONG_MIN:(int)lb128);
        while(lb<rb){
            int mid=lb+(int)(((i128)rb-(i128)lb)/2);
            if(feasible_d(a,b,K,mid)){rb=mid;}
            else{lb=mid+1;}
        }
        cout<<lb<<"\n";
    }
    return 0;
}
