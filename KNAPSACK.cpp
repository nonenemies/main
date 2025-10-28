#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, price;
    cin >> n >> price;

    vector<int> cost(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<ll> dp(price + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int c = price; c >= cost[i]; c--) {
            dp[c] = max(dp[c], dp[c - cost[i]] + pages[i]);
        }
    }
    cout << dp[price];
}
