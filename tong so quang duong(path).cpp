#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define INF 1e9

using namespace std;

void input1(vector<int>& num, int n){
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
	int n;
	cin >> n;
	vector<vector<char> > paths(n, vector<char>(n));
	input2(paths,n,n);
	vector<vector<int> > dp(n, vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(j!=0&&i==0){
				if(paths[i][j-1]!='*'){
					dp[i][j]+=dp[i][j-1];
				}
			}else if(j==0&&i!=0){
				if(paths[i-1][j]!='*'){
					dp[i][j]+=dp[i-1][j];
				}
			}else if(i!=0&&j!=0){
				if(paths[i-1][j]!='*'){
					dp[i][j]+=dp[i-1][j];
				}
				if(paths[i][j-1]!='*'){
					dp[i][j]+=dp[i][j-1];
				}
			}
			dp[i][j]%=mod;
		}
	}
	if(paths[n-1][n-1]=='*'){
		cout << 0 << endl;
	}else{
		cout << dp[n-1][n-1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	//int tt; cin >> tt; for (int i = 0; i < tt; i++) {solve();}
	solve();
}
