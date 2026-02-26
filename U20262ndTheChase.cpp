#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define fi first
#define se second

const int maxn=2e5+10;

int N,M,to[maxn],du[maxn],S[maxn],dist[maxn],cyc[maxn],cid[maxn],cpos[maxn],root[maxn],tot,dep[maxn],fns[maxn],ans[maxn],vp[maxn];
vi rev[maxn],clen,tree[maxn],ns[maxn],deps[maxn],lst[maxn];

void BFSGetDist() {
    memset(dist,0x3f,sizeof(dist));
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(S[i]) {
            dist[i]=0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        if(dist[to[cur]]==0x3f3f3f3f3f3f3f3f) {
            dist[to[cur]]=(dist[cur]+1);
            q.push(to[cur]);
        }
    }
}

void BFSGetDep() {
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(cyc[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        tree[root[cur]].pb(cur);
        for(auto nxt:rev[cur]) {
            if(!cyc[nxt]) {
                cid[nxt]=cid[cur];
                root[nxt]=root[cur];
                dep[nxt]=dep[cur]+1;
                q.push(nxt);
            }
        }
    }
}

void TopologicalExpansion() {
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(du[i]==0) {
            q.push(i);
        }
    }
    for(int i=1;i<=N;i++) {
        cyc[i]=1;
    }
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        cyc[cur]=0;
        du[to[cur]]--;
        if(du[to[cur]]==0) {
            q.push(to[cur]);
        }
    }
}

void solve() {
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>to[i];
        du[to[i]]++;
        rev[to[i]].pb(i);
    }
    for(int i=1;i<=M;i++) {
        int x;
        cin>>x;
        S[x]=1;
    }
    BFSGetDist();
    TopologicalExpansion();
    for(int i=1;i<=N;i++) {
        cid[i]=(-1);
    }
    for(int i=1;i<=N;i++) {
        if(cyc[i] && cid[i]==(-1)) {
            int cur=i,pcur=0;
            do {
                cid[cur]=tot;
                cpos[cur]=pcur;
                pcur++;
                root[cur]=i;
                cur=to[cur];
            } while(cur!=i);
            clen.pb(pcur);
            tot++;
        }
    }
    BFSGetDep();
    for(int i=1;i<=N;i++) {
        if(S[i]==1 && dist[i]==0) {
            int tmp=((dep[i]-cpos[root[i]]+clen[cid[i]])%clen[cid[i]]);
            if(ns[cid[i]].empty()) {
                ns[cid[i]].assign(clen[cid[i]],0);
            }
            ns[cid[i]][tmp]=1;
            if(!cyc[i]) {
                deps[root[i]].pb(dep[i]);
            }
        }
    }
    for(int i=0;i<tot;i++) {
        if(!ns[i].empty()) {
            fns[i]=1;
            for(int j=0;j<clen[i];j++) {
                if(!ns[i][j]) {
                    fns[i]=0;
                    break;
                }
            }
            if(fns[i]==0) {
                int lcur=clen[i];
                lst[i].resize(lcur*2);
                int last=(-1);
                for(int j=0;j<(lcur*2);j++) {
                    if(ns[i][j%lcur]==0) {
                        last=j;
                    }
                    lst[i][j]=last;
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {
        if(!cyc[i] || tree[i].empty()) {
            continue;
        }
        int id=cid[i],l=clen[cid[i]],mx=(-0x3f3f3f3f3f3f3f3f);
        for(auto it:deps[i]) {
            mx=max(mx,it);
        }
        if(mx!=(-0x3f3f3f3f3f3f3f3f)) {
            int last=(-1);
            for(int j=0;j<=mx;j++) {
                int tmp=(((j-cpos[i])+l)%l);
                if(!ns[id].empty() && ns[id][tmp]) {
                    vp[j]=j;
                } else {
                    vp[j]=(-1);
                }
            }
            for(auto it:deps[i]) {
                vp[it]=(-1);
            }
            for(int j=0;j<=mx;j++) {
                if(vp[j]!=(-1)) {
                    last=vp[j];
                }
                vp[j]=last;
            }
        }
        for(auto it:deps[i]) {
            if(S[it]) {
                ans[it]=(-1);
                continue;
            } else if(dist[i]==0x3f3f3f3f3f3f3f3f) {
                ans[it]=(-2);
                continue;
            } else if(fns[id]) {
                ans[it]=(-1);
                continue;
            }
            int res=(-1);
            if((dep[it]+dist[it]-1)>mx) {
                int tmp=((dep[it]+dist[it]-1+l)%l);
                int nxt=((dep[it]+dist[it]-1)-((tmp+l)-lst[id][tmp+l]));
                if(nxt>mx) {
                    res=nxt;
                } else if(mx!=(-1)) {
                    res=vp[dep[it]+dist[it]-1];
                }
            } else {
                if(mx!=(-1) && (dep[i]+dist[i]-1)>=0) {
                    res=vp[dep[it]+dist[it]-1];
                }
            }
            if(res<dep[i]) {
                ans[it]=(-1);
            } else {
                ans[it]=(res-dep[it]);
            }
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<ans[i]<<endl;
    }
    return;

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TT=1;
    //cin>>TT;
    for(int i=1;i<=TT;i++) {
        solve();
    }
    return 0;
}