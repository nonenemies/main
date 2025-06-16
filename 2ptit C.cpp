#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define ll long long
#define dbl double

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define For_de(i,a,b) for(int i=(a);i<(b);--i)
#define For_random(i,a,b,c) for(int i=(a);i<(b);i+=c)
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

typedef struct{
	char name[100];
	char dateandbirth[100];
	dbl subject1;
	dbl subject2;
	dbl subject3;
	int position;
	dbl total;
} Goods;

int cmp(const void *a, const void *b){
	Goods *g1 = (Goods*)a;
	Goods *g2 = (Goods*)b;
	int z1 = g1->total;
	int z2 = g2->total;
	return z2-z1;
}

void solve(){
	int n;
	scanf("%d", &n);
	getchar();
	Goods list[n];
	for(int i=0;i<n;++i){
		gets(list[i].name);
		gets(list[i].dateandbirth);
		scanf("%lf", &list[i].subject1);getchar();
		scanf("%lf", &list[i].subject2);getchar();
		scanf("%lf", &list[i].subject3);getchar();
		list[i].position = i+1;
		list[i].total = list[i].subject1+list[i].subject2+list[i].subject3;
	}
	qsort(list,n,sizeof(Goods),cmp);
	for(int i=0;i<n;++i){
		printf("%d %s %s %.1lf\n", list[i].position, list[i].name, list[i].dateandbirth, list[i].total);
	}
}

int main(){
	//int t;scanf("%d", &t);while(t--){solve();}
	solve();
}
