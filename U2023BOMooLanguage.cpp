#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
#include <bitset>
#include <set>
#include <queue>
#include <cmath>
#include <tuple>
#include <stack>
#include <numeric>
#include <climits>
#include <deque> 
#include <chrono>
#include <unordered_map>
#include <cstring>
#include <random>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define systemwait system("read -p \"Press Enter to continue...\"");
#define debugbreak exit(0)
#else
#define debug(x...) 
#define systemwait
#define debugbreak
#endif

#define LL long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sqsq(x) (x)*(x)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define tiii tuple<int,int,int>
#define vstto vector<Edge>
#define fi first
#define se second
#define pb push_back

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int dx[4]={0,(-1),0,1};
const int dy[4]={(-1),0,1,0};
const int maxch=26;
const int maxn=1005;

struct Node {
    string n1,v,n2;
};

int N,C,P;
vector<string> n,v1,v2,cnjt;
vector<Node> ans;

void solve() {
//--------Initiallize--------
//--------Input--------
    cin>>N>>C>>P;
    n.clear();
    v1.clear();
    v2.clear();
    cnjt.clear();
    ans.clear();
    for(int i=1;i<=N;i++) {
        string s,type;
        cin>>s>>type;
        if(type=="noun") n.pb(s);
        else if(type=="intransitive-verb") v1.pb(s);
        else if(type=="transitive-verb") v2.pb(s);
        else if(type=="conjunction") cnjt.pb(s);
    }
    /*for(string it:v1) {
        cout<<it<<" ";
    }
    cout<<endl;
    for(string it:v2) {
        cout<<it<<" ";
    }
    cout<<endl;
    for(string it:n) {
        cout<<it<<" ";
    }
    cout<<endl;
    for(string it:cnjt) {
        cout<<it<<" ";
    }
    cout<<endl;*/
    int num=P+min(P,(int)cnjt.size());
    for(int i=1;i<=num && (!v1.empty() || !v2.empty()) && !n.empty();i++) {
        if(!v1.empty()) {
            ans.pb({n.back(),v1.back(),""});
            n.pop_back();
            v1.pop_back();
        } else if(!v2.empty()) {
            if(n.size()<2) {
                break;
            }
            ans.pb({n.back(),v2.back(),*--(--n.end())});
            n.pop_back();
            n.pop_back();
            v2.pop_back();
        }
    }
    for(int i=0;i<ans.size() && !v2.empty() && !n.empty();i++) {
        if(!ans[i].n2.empty()) {
            break;
        }
        ans[i].v=v2.back();
        ans[i].n2=n.back();
        v2.pop_back();
        n.pop_back();
    }
    int tot=min(cnjt.size(),ans.size()/2);
    bool flag=false;
    for(int i=0;i<ans.size();i++) {
        tot+=2;
        if(!ans[i].n2.empty() && !flag) {
            tot+=min((int) n.size(),C);
            flag=true;
        }
        if(!ans[i].n2.empty()) {
            tot++;
        }
    }
    if(!ans.size()) {
        cout<<0<<endl;
        cout<<endl;
        return;
    }
    cout<<tot<<endl;
    for(int i=0;i<ans.size();i++) {
        if(i!=0) {
            cout<<" ";
        }
        cout<<ans[i].n1<<" "<<ans[i].v;
        if(!ans[i].n2.empty()) {
            cout<<" "<<ans[i].n2;;
            while(!n.empty() && C>0) {
                cout<<", "<<n.back();
                n.pop_back();
                C--;
            }
        }
        if(i%2==0 && !cnjt.empty() && i!=ans.size()-1) {
            cout<<" "<<cnjt.back();
            cnjt.pop_back();
            //debug(cnjt.empty());
        } else {
            cout<<".";
        }
    }
    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int TT=1;
    cin>>TT;
    for(int i=1;i<=TT;++i) {
        solve();
    }
    return 0;
}