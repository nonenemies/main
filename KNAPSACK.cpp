#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("KNAPSACK.inp","r",stdin);
    freopen("KNAPSACK.out","w",stdout);
	long long n;
	cin >> n;
	long long C;
	cin >> C;
	long long items[n+1];
	long long weight[n+1];
	long long i;
	for(i=0;i<n;i++)
	{
		cin >> weight[i] >> items[i];
	}
	long long maxvalue[n+1][C+1];
	long long mondo;
	long long trongluong;
	long long hientai;
	for(mondo = 0;mondo<=n;mondo++)
	{
		hientai=mondo-1;
		for(trongluong=0;trongluong<=C;trongluong++)
		{
			if(mondo==0||trongluong==0)
			{
				maxvalue[mondo][trongluong]=0;
			}
			else if(weight[hientai]>trongluong)
			{
				maxvalue[mondo][trongluong] = maxvalue[mondo-1][trongluong];
			}
			else 
			{
				long long neulaymondo = items[hientai] + maxvalue[mondo-1][trongluong-weight[hientai]];
				long long neukolaymondo = maxvalue[mondo-1][trongluong];
				maxvalue[mondo][trongluong] = max(neulaymondo,neukolaymondo);
			}
		}
	}
	cout << maxvalue[n][C];
}
