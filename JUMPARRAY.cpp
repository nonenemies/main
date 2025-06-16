#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("JUMPARRAY.inp","r",stdin);
    freopen("JUMPARRAY.out","w",stdout);
	int a;
	cin >> a;
	int mino[a+1];
	int i,j;
	for(i=0;i<a;i++)
	{
		cin >> mino[i];
	}
	int minumstep[a+1];
	minumstep[0]=0;
	for(i=1;i<a;i++)
	{
		minumstep[i]=3002;
	}
	for(i=1;i<a;i++)
	{
		for(j=0;j<i;j++)
		{
			if(i<=j+mino[j])
			{
			   minumstep[i]=min(minumstep[i],minumstep[j]+1);
		    }
		}
	}
    cout << minumstep[a-1];
}
