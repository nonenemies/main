#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

long long checkeven(long long a, long long b, long long arr[199999]){
	long long chan = 0;
	for(long long i=a;i<b;i++){
		if(arr[i]%2==0){
			chan++;
		}
	}
	return chan;
}
long long demso(long long a, long long arr[199999]){
	long long chan = 0;
	long long le = 0;
	for(long long i=0;i<a;++i){
		if(arr[i]%2==1){
			le++;
		}
		else{
			chan++;
		}
	}
	sort(arr,arr+a);
	long long step = 0;
	long long i=0;
	if(le==0||chan==0){
		return 0;
	}
	else if(arr[a-1]%2==1){
		return chan;
	}else if(arr[a-1]%2==0){
		do{
			if(arr[i]%2==0){
				for(long long j=a-1;j>=i;--j){
					if(arr[j]%2==1){
						arr[i] = arr[i]+arr[j];
						sort(arr,arr+a);
						step++;
						i = 0;
						break;					
					}
					if(j==i){
						return step+checkeven(i,a,arr)+1;
					}
				}
			}
			else{
				i++;
			}
		}while(checkeven(0,a,arr)!=0);
	}
	return step;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a;
	cin >> a;
	long long ans[a-1];
	for(long long i=0;i<a;++i){
		long long sophantu;
		cin >> sophantu;
		long long arr[sophantu-1];
		for(long long j=0;j<sophantu;++j){
			cin >> arr[j];
		}
		ans[i] = demso(sophantu,arr);
	}
	for(long long i=0;i<a;++i){
		cout << ans[i] << endl;
	}
}


