#include<iostream>
using namespace std;
int minx(int a,int b,int c)
{
	if(a<=b&&a<=c)
	{
		return a;
	}
	else if(b<=a&&b<=c)
	{
		return b;
	}
	else if(c<=a&&c<=b)
	{
		return c;
	}
}
int main()
{
	//freopen("EDITDISTANCE.inp","r",stdin);
    //freopen("EDITDISTANCE.out","w",stdout);
	string s1;
	string s2;
	cin >> s1 >> s2;
	int hang;
	int cot;
	int mino[s1.size()+1][s2.size()+1];
	for(hang = 0;hang <= s1.size();hang++)
	{
		for(cot=0;cot<=s2.size();cot++)
		{
			if(hang==0)
			{
				mino[hang][cot] = cot;
			}
			else if(cot==0)
			{
				mino[hang][cot] = hang;
			}
			else if(s2[cot-1]==s1[hang-1])
			{
				mino[hang][cot] = mino[hang-1][cot-1];
			}
			else 
			{
				mino[hang][cot] = minx(mino[hang-1][cot],mino[hang][cot-1],mino[hang-1][cot-1])+1;
			}
		}
	}
    cout << mino[s1.size()][s2.size()];
}
