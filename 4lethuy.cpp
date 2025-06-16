#include<bits/stdc++.h>
using namespace std;

#define spd ios::sync_with_stdio(false);cin.tie(NULL);

#define ll long long
#define INF 1e18

void solve(){
	int n;
	cin >> n;
	vector<ll> x(n);
	vector<ll> y(n);
	ll xxmin = INF;
	ll xxmax = -INF;
	ll yymin = INF;
	ll yymax = -INF;
	for(int i=0;i<n;++i){
		ll a,b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
		xxmin = min(x[i],xxmin);
		xxmax = max(x[i],xxmax);
		yymin = min(y[i],yymin);
		yymax = max(y[i],yymax);
	}
	ll no_change = (xxmax-xxmin+1)*(yymax-yymin+1);
	vector<ll> pmin_x(n);
	vector<ll> pmin_y(n);
	vector<ll> pmax_x(n);
	vector<ll> pmax_y(n);
	
	pmin_x[0] = x[0];
	pmin_y[0] = y[0];
	pmax_x[0] = x[0];
	pmax_y[0] = y[0];
	
	for(int i=1;i<n;++i){
		pmin_x[i] = min(x[i],pmin_x[i-1]);
		pmin_y[i] = min(y[i],pmin_y[i-1]);
		pmax_x[i] = max(x[i],pmax_x[i-1]);
		pmax_y[i] = max(y[i],pmax_y[i-1]);
	}
	
	vector<ll> smin_x(n);
	vector<ll> smin_y(n);
	vector<ll> smax_x(n);
	vector<ll> smax_y(n);
	
	smin_x[n-1] = x[n-1];
	smin_y[n-1] = y[n-1];
	smax_x[n-1] = x[n-1];
	smax_y[n-1] = y[n-1];
	
	for(int i=n-2;i>=0;--i){
		smin_x[i] = min(x[i],smin_x[i+1]);
		smin_y[i] = min(y[i],smin_y[i+1]);
		smax_x[i] = max(x[i],smax_x[i+1]);
		smax_y[i] = max(y[i],smax_y[i+1]);
	}
	
	ll res = INF;
	
	for(int i = 0;i<n;++i){
        ll xmin = INF;
		ll xmax = -INF;
		ll ymin = INF;
		ll ymax = -INF;
        if(i>0){
            xmin = min(xmin, pmin_x[i-1]);
            ymin = min(ymin, pmin_y[i-1]);
            xmax = max(xmax, pmax_x[i-1]);
            ymax = max(ymax, pmax_y[i-1]);
        }
        if(i<n-1){
            xmin = min(xmin, smin_x[i+1]);
            ymin = min(ymin, smin_y[i+1]);
            xmax = max(xmax, smax_x[i+1]);
            ymax = max(ymax, smax_y[i+1]);
        }
        vector<ll> near_x = {x[i], xmin-1, xmax+1};
        vector<ll> near_y = {y[i], ymin-1, ymax+1};
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                ll nearx_min = min(xmin, near_x[j]);
                ll nearx_max = max(xmax, near_x[j]);
                ll neary_min = min(ymin, near_y[k]);
                ll neary_max = max(ymax, near_y[k]);
                ll area = (nearx_max-nearx_min+1)*(neary_max-neary_min+1);
                res = min(res, area);
            }
        }
    }
    cout << min(res,no_change) << '\n';
}

int main(){
	spd;
	int tc;cin>>tc;while(tc--){solve();}
	//solve();
	return 0;
}
