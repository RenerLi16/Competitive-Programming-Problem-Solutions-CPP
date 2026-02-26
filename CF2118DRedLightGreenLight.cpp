#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define debug(x) cerr<< #x <<" = "<<x<<endl;
#define debugarr(a,n) cerr<< #a <<" = "; for(int _=1;_<=n;++_) cerr<<a[_]<<" "; cerr<<endl;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;
const int maxn=2e5+10;

const int HASHMOD=524287;
const int STEP_MOD=525281;

struct HashMap {
    vector<int64_t> key;
    vector<int> val;
    vector<bool> used;

    HashMap() {
        key.resize(HASHMOD);
        val.resize(HASHMOD);
        used.resize(HASHMOD);
        clear();
    }

    inline int h1(int64_t x) const {
        x %= HASHMOD;
        if (x < 0) x += HASHMOD;
        return x;
    }

    inline int h2(int64_t x) const {
        x %= STEP_MOD;
        if (x < 0) x += STEP_MOD;
        return 1 + x;
    }

    int& operator[](int64_t x) {
        int i = h1(x);
        int step = h2(x);
        while (used[i] && key[i] != x) {
            i += step;
            if (i >= HASHMOD) i -= HASHMOD;
        }
        if (!used[i]) {
            used[i] = true;
            key[i] = x;
            val[i] = 0;
        }
        return val[i];
    }

    int* get(int64_t x) {
        int i = h1(x);
        int step = h2(x);
        while (used[i]) {
            if (key[i] == x) return &val[i];
            i += step;
            if (i >= HASHMOD) i -= HASHMOD;
        }
        return nullptr;
    }

    void clear() {
        fill(used.begin(), used.end(), false);
    }
} mp;

int vis[maxn*4],N,K,Q;
pii pool[maxn];
vi cpypool;
//map<int,int> mp;

bool dfs(int x,int t,int dir) {
//	cout<<x<<" "<<t<<" "<<dir<<endl;
	if(x==0 || x==1e15+1) {
		return true;
	}
	int pos=mp[x];
	cerr<<pos<<endl;
	t%=K;
	if(t%K==pool[pos].second) {
		dir^=1;
		dir+=2;
	}
//	cout<<dir<<endl;
	if(vis[dir*N+pos]==1 && dir>1) {
//		cout<<"SW"<<endl;
		return false;
	}
	vis[dir*N+pos]=1;
	if((dir%2)==0) {
		return dfs(pool[pos+1].first,(t+(pool[pos+1].first-pool[pos].first)),0);
	} else {
		return dfs(pool[pos-1].first,(t+(pool[pos].first-pool[pos-1].first)),1);
	}
}

void solve() {
	// Initiallize
	memset(pool,0,sizeof(pool));
	cpypool.clear();
	mp.clear();
	// No fluff real stuff
	cin>>N>>K;
	cpypool.push_back(0);
	for(int i=1;i<=N;i++) {
		cin>>pool[i].first;
		cpypool.push_back(pool[i].first);
		mp[pool[i].first]=i;
	}
	for(int i=1;i<=N;i++) {
		cin>>pool[i].second;
	}
	cpypool.push_back(1e15+1);
	pool[0]={0,0};
	pool[N+1]={1e15+1,0};
	cin>>Q;
	for(int i=1;i<=Q;i++) {
		//init
		memset(vis,0,sizeof(vis));
		//real stuff
		int aa;
		cin>>aa;
		int nxtpos=(lower_bound(cpypool.begin(),cpypool.end(),aa)-cpypool.begin());
//		cout<<nxtpos<<endl;
		if(dfs(pool[nxtpos].first,(pool[nxtpos].first-aa),0)) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
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