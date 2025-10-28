#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long

int main()
{
	int n, price;
    cin >> n >> price;
	vector<ll> books(n+1, 0);
    vector<ll> pages(n+1, 0);
	for(int i = 0;i < n;++i){
        cin >> books[i];
    }
    for(int i = 0;i < n;++i){
        cin >> pages[i];
    }
	vector<vector<ll>> dp(n+1, vector<ll>(price + 1, 0));
	for(ll bookvalue = 0; bookvalue <= n; ++bookvalue){
		for(ll cost = 0; cost <= price; ++cost){
			if(bookvalue==0||cost==0){
				dp[bookvalue][cost]=0;
                continue;
			}
            ll hientai = bookvalue - 1;
			if(books[hientai] > cost){
				dp[bookvalue][cost] = dp[bookvalue-1][cost];
			}
			else 
			{
				long long iftake = pages[hientai] + dp[bookvalue-1][cost - books[hientai]];
				long long ifnotake = dp[bookvalue-1][cost];
				dp[bookvalue][cost] = max(iftake,ifnotake);
			}
		}
	}
	cout << dp[n][price];
}
