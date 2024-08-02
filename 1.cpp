#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

long long luythua(int a, int b){
	long long res =1;
	for(int i=0;i<b;i++){
		res*=a;
	}
	return res;
}

bool check(string s){
	for(int i = 1; i < s.size(); ++i){
        if(s[i] == 'C' && s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){
            return true;
        }
    }
    return false;
}

void truonghop1(string s){
	int int1 = 0;
	int int2 = 0;
	int tmp;
	for(int i = 1; i < s.size()-1; ++i){ 
        if(s[i] >= '0' && s[i] <= '9'){
            int1 = int1 * 10 + (s[i] - '0'); 
        }
        else{ 
        	tmp=i;
            break;
        }
    }
	for(int i = tmp+1; i < s.size(); ++i){ 
    	if(s[i] >= '0' && s[i] <= '9'){     
            int2 = int2 * 10 + (s[i] - '0');
        }
    }
    string ans[s.size()];
    int dem = 0;
    if(int2%26!=0){
    	do{
    		if(int2==26){
    			ans[dem]='Z';
    			break;
			}
            ans[dem] = char(int2 % 26 - 1 + 'A');   
            int2 = int2 / 26;
		    dem++;           
        }while (int2 != 0);
        for(int i=dem;i>=0;--i){
    	cout << ans[i];
	}
	}
	else{
		cout << char(int2/26-2+'A') << "Z";
	}
    cout << int1 << endl;
}

void truonghop2(string s){
	int int3 = 0;
	int int4 = 0;
	int tmp = 0;
	int count2 = 0;
	for (int i = 0; i < s.size(); ++i){
        if (s[i] >= '0' && s[i] <= '9') {
            int3 = int3 * 10 + (s[i] - '0'); 
        }
        else{
            tmp = i;    
        }
    }
    for (int i = tmp; i >= 0; --i){    
        int4 = int4 + int((s[i] - 'A' + 1)) * luythua(26, count2);    
        count2++;
    }
    cout << "R" << int3 << "C" << int4 << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s[n];
	for(int i=0;i<n;++i){
		cin >> s[i];
	}
	for(int i=0;i<n;++i){
		if(check(s[i])==true){
			truonghop1(s[i]);
		}
		else{
			truonghop2(s[i]);
		}
	}
}
