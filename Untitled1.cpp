#include<stdio.h>
#include<string.h>

void solve(){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n+1];
	gets(s);
	int left = 0;
	int right = 0;
	for(int i=0;i<strlen(s);++i){
		if(s[i]=='<'){
			++left;
		}else{
			break;
		}
	}
	for(int i=strlen(s)-1;i>=0;--i){
		if(s[i]=='>'){
			++right;
		}else{
			break;
		}
	}
	printf("%d", (left>right)?left:right);
}

int main(){
	solve();
	return 0;
}
