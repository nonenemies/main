#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("LCS2.inp","r",stdin);
    //freopen("LCS2.out","w",stdout);
	string s1;
	string s2;
	cin >> s1 >> s2;
	long long mino[400][400];
	long long hang,cot;
	for(hang = 0;hang<=s1.size();hang++)
	{
		for(cot = 0;cot<=s2.size();cot++)
		{
			if(hang==0||cot==0)
			{
				mino[hang][cot]=0;
			}
			else if(s1[hang-1]==s2[cot-1])
			{
				mino[hang][cot]=mino[hang-1][cot-1]+1;
			}
			else 
			{
				mino[hang][cot] = max(mino[hang-1][cot],mino[hang][cot-1]);
			}
		}
	}
	for(hang =0;hang<=s1.size();hang++)
	{
		for(cot=0;cot<=s2.size();cot++)
		{
			cout << mino[hang][cot] << " ";
		}
		cout << endl;
	}
	return 0;
	string result = "";
	int len1 = s1.size();
	int len2 = s2.size();
	while(mino[len1][len2]!=0)
	{
		if(s1[len1-1]==s2[len2-1])
		{
			result+=s1[len1-1];
			len1--;
			len2--;
		}
		else 
		{
			if(mino[len1-1][len2]>=mino[len1][len2-1])
			{
				len1--;
			}
			else
			{
			    len2--;
			}
		}
	}
	int i;
	for(i=result.size()-1;i>=0;i--)
	{
	    cout << result[i];
	}
}
