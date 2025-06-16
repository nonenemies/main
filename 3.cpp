#include <bits/stdc++.h>
using namespace std;

#define spd ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
vector<int> ans;
vector<int> visit(11, 0);

void permutation(int pos) {
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            visit[i] = 1;
            ans.push_back(i);
            if (ans.size() == n){
            	if(ans[0]-ans[n-1]>0){
            		for (int i = 0; i < n; ++i) cout << ans[i] << " ";
            		cout << '\n';
				}
            }	
			else{
                permutation(pos + 1);
            }
            ans.pop_back();
            visit[i] = 0;
        }
    }
}

void solve() {
    cin >> n;
    permutation(1);
}

int main() {
    spd;
    solve();
    return 0;
}
