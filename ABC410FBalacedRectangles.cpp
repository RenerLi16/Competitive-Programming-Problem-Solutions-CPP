#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//const int maxn=5005;
//const int SHIFT=2.5e7;
//const int maxval=5e7+10;
int H,W,T;
long long ans;
vector<vector<int>> intmp,mp,ps;
vector<int> cnt;
void solve() {
	ans=0;
	cin>>H>>W;
	intmp.resize(H+5);
	for(int i=0;i<=H;i++) {
		intmp[i].assign(W+5,0);
	}
	for(int i=1;i<=H;i++) {
		for(int j=1;j<=W;j++) {
			char c;
			cin>>c;
			if(c=='#') {
				intmp[i][j]=1;
			} else {
				intmp[i][j]=-1;
			}
		}
	}
	if(H<=W) {
		mp.resize(W+5);
		for(int i=0;i<=W;i++) {
			mp[i].assign(H+5,0);
		}
		for(int i=1;i<=H;i++) {
			for(int j=1;j<=W;j++) {
				mp[j][i]=intmp[i][j];
			}
		}
		swap(H,W);
	} else {
		mp.resize(H+5);
		for(int i=0;i<=H;i++) {
			mp[i].assign(W+5,0);
		}
		for(int i=1;i<=H;i++) {
			for(int j=1;j<=W;j++) {
				mp[i][j]=intmp[i][j];
			}
		}
	}
//	for(int i=1;i<=H;i++) {
//		for(int j=1;j<=W;j++) {
//			if(mp[i][j]==1) {
//				cout<<"#";
//			} else {
//				cout<<".";
//			}
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	ps.resize(H+5);
	for(int i=1;i<=H;i++) {
		ps[i].assign(W+5,0);
		for(int j=1;j<=W;j++) {
			ps[i][j]=ps[i][j-1]+mp[i][j];
		}
	}
	cnt.assign(3*H*W+10,0);
	int SHIFT=H*W;
	cnt[0+SHIFT]=1;
	for(int lb=1;lb<=W;lb++) {
		for(int rb=lb;rb<=W;rb++) {
			int sum=0;
			for(int i=1;i<=H;i++) {
				sum=sum+(ps[i][rb]-ps[i][lb-1]);
//				cout<<sum<<endl;
//				cout<<cnt[sum]
//				cout<<cnt[sum]<<" "<<sum<<endl;
//
//				cout,<
//				cout<<c
//				cout<<sum<<" "<<cnt[sum]<<endl;
				ans+=((long long)cnt[sum+SHIFT]);
				cnt[sum+SHIFT]++;
			}
			sum=0;
			for(int i=1;i<=H;i++) {
				sum=sum+(ps[i][rb]-ps[i][lb-1]);
				cnt[sum+SHIFT]--;
			}
//			cout<<lb<<" "<<rb<<" "<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return;
}
int main() {
	cin>>T;
	for(int i=1;i<=T;i++) {
		solve();
	}
	return 0;
}