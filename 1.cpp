#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

//hàm check xem mảng còn bao nhiêu số chẵn
long long checkeven(long long a, long long b, long long arr[199999]){
	long long chan = 0;
	for(long long i=a;i<b;++i){
		if(arr[i]%2==0){
			chan++;
		}
	}
	return chan;
}

//hàm check số chẵn lớn nhất của mảng
long long maxeven(long long a, long long arr[199999]){
	long long max = 0;
	for(long long i=0;i<a;++i){
		if(arr[i]%2==0&&arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

//hàm check số chẵn nhỏ nhất của mảng
long long mineven(long long a, long long arr[199999]){
	long long min = 1000000000;
	for(long long i=0;i<a;++i){
		if(arr[i]%2==0&&arr[i]<min){
			min = arr[i];
		}
	}
	return min;
}

//hàm check số chẵn lớn nhất nhỏ hơn số lẻ lớn nhất
long long maxeven2(long long a, long long arr[199999]){
	long long max2 = 0;
	long long maxod = 0;
	//tìm số lẻ max
	for(long long i=0;i<a;++i){
		if(arr[i]%2==1&&arr[i]>maxod){
			maxod = arr[i];
		}
	}
	//hàm
	for(long long i=0;i<a;++i){
		if(arr[i]%2==0&&arr[i]>max2&&arr[i]<maxod){
			max2 = arr[i];
		}
	}
	return max2;
}

//hàm check số lẻ lớn nhất
long long maxodd(long long a, long long arr[199999]){
	long long max = 0;
	for(long long i=0;i<a;++i){
		if(arr[i]%2==1&&arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

//hàm thực hiện
long long demso(long long a, long long arr[199999]){
	//th1, ko có số chẵn hoặc số lẻ nào
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
	long long step = 0; // biến đếm số lần đã thực hiện(số lần lấy chẵn + lẻ)
	if(le==0||chan==0){
		return 0; // đáp án trg hợp 1
	}
	else if(maxodd(a,arr)>maxeven(a,arr)){
		return chan; // nếu số lẻ là số lớn nhất của mảng (số đứng cuối), thì chỉ cần in ra số số chẵn do t lấy số lẻ max + với tất cả các số chẵn kia là xong
	}else if(maxodd(a,arr)<maxeven(a,arr)){    //trg hợp chẵn lớn nhất
		while(maxodd(a,arr)<maxeven(a,arr)){  //t sẽ lấy số lẻ lớn nhất cộng với số chẵn lớn nhất bé hơn nó, nó sẽ cộng liên tục với mục tiêu là vượt qua số chẵn lớn nhất và quay về trường hợp trên
			for(long long i=0;i<a;++i){
				if(arr[i]==maxeven2(a,arr)){ // số chẵn lớn nhất nhỏ hơn số lẻ lớn nhất
					arr[i] = arr[i]+maxodd(a,arr);
					++step; //cộng biến đếm
					break; //break check điều kiện
				}
			}
			if(maxodd(a,arr)<mineven(a,arr)){ //nếu số lẻ lớn nhất bé hơn số chẵn nhỏ nhất(case 4) thì chỉ cần lấy số chẵn lớn nhất cộng với bất kì số lẻ nào đấy thì sẽ được số lẻ lớn nhất và lại quay về trường hợp kia, cộng thêm 1 bởi tốn thêm bước cộng số chẵn max vs số lẻ nào đấy
				return step + checkeven(0,a,arr) + 1; //đáp án
			}
		}
		return step + checkeven(0,a,arr); //đáp án - số bước đã thực hiện cộng với số số chẵn còn lại
	}
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
		long long arr[sophantu+1];
		for(long long j=0;j<sophantu;++j){
			cin >> arr[j];
		}
		ans[i] = demso(sophantu,arr);
	}
	for(long long i=0;i<a;++i){
		cout << ans[i] << endl;
	}
}
