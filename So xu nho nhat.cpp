#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define INF 1e9

using namespace std;

void input(vector<int>& num, int n){
	for(int i = 0 ; i < n ; ++i) cin >> num[i];
}
void solve() {
	int n,x;
	cin >> n >> x;
	vector<int> coins(n);
	input(coins,n);
	vector<int> dp(x+1,INF);
	dp[0] = 0;
	for(int i=1;i<=x;++i){
		for(int j=0;j<n;++j){
			if(coins[j]<=i){
				dp[i] = min(dp[i],dp[i-coins[j]]+1);
			}
		}
	}
	if(dp[x]!=INF){
		cout << dp[x] << endl;
	}else{
		cout << -1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	//int tt; cin >> tt; for (int i = 0; i < tt; i++) {solve();}
	solve();
}
