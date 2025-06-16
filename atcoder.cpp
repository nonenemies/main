#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>

#define ll long long
#define mod 1000000000

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.length();
	int ans = 0;
	for(int i=0;i<n;++i){
		if(i%2==0&&s[i]=='o'){
			++n;
			++ans;
			s.insert(i,1,'i');
		}
		if(i%2==1&&s[i]=='i'){
			++n;
			++ans;
			s.insert(i,1,'o');
		}
	}
	if(s.length()%2==1){
		++ans;
	}
	cout << ans;
}
