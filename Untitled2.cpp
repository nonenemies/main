#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    string s;
    cin >> s;

    int left = 0, right = n - 1;

    auto mod_product = [&](int l, int r) {
        ll res = 1;
        for (int i = l; i <= r; ++i) {
            res = (res * (num[i] % m)) % m;
        }
        return res;
    };

    // Initial product
    cout << mod_product(left, right) << " ";

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'L') left++;
        else right--;
        cout << mod_product(left, right) << " ";
    }

    cout << endl;
    return 0;
}

