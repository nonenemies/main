#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define INF 1e9

using namespace std;

void input1(vector<ll>& num, int n){
	for(int i = 0 ; i < n ; ++i) cin >> num[i];
}

void input2(vector<vector<char> >& num, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num[i][j];
        }
    }
}

void solve() {
	//decalre
	int n,m;
	cin >> n >> m;
	//vector<ll> arr(n);
	//input1(arr,n);
	//end declare
	vector<vector<ll> > dp(n+1, vector<ll>(m+1,1e9));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j!=1){
				dp[i][j] = j-1;
			}else if(j==1&&i!=1){
				dp[i][j] = i-1;
			}else if(i==j){
				dp[i][j] = 0;
			}
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			if(i!=j){
				for(int k=1;k<j;++k){
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}
				for(int k=1;k<i;++k){
					dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
			}
		}
	}
	cout << dp[n][m] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	//int tt; cin >> tt; for (int i = 0; i < tt; i++) {solve();}
	solve();
}
