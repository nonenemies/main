#include<stdio.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<ctype.h>

int giaithua(int n){
	int res = 1;
	for(int i=1;i<=n;++i){
		res*=i;
	}
	return res;
}

int ckn(int k, int n){
	return (giaithua(n)/giaithua(k)/giaithua(n-k));
}

int cmp(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

void solve() {
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i=0;i<n;++i){
    	scanf("%d", &num[i]);
	}
	qsort(num,n,sizeof(int),cmp);
	int a1 = num[0];
	int a2 = num[1];
	int a3 = num[2];
	int dem1 = 0;
	int dem2 = 0;
	int dem3 = 0;
	for(int i=0;i<n;++i){
		if(num[i]==a1){
			++dem1;
		}
		if(num[i]==a2){
			++dem2;
		}
		if(num[i]==a3){
			++dem3;
		}
	}
	if(a1!=a2&&a1!=a3){
		printf("%d", dem1*dem2*dem3);
	}else if(a1==a2&&a1==a3){
		printf("%d", ckn(3,dem1));
	}else if(a1==a2&&a1!=a3){
		printf("%d", ckn(2,dem1)*dem3);
	}else if(a1==a3&&a1!=a2){
		printf("%d", ckn(2,dem1)*dem2);
	}else if(a2==a3&&a1!=a2){
		printf("%d", ckn(2,dem2)*dem1);
	}
}

int main() {
    solve();
    return 0;
}
