#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
	cin >> n;
	long long a[10000000];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long maxattime[10000000];
	maxattime[0] = 1;
	long long answer = 1;
    for(int i = 1; i < n; i++)
    {
        long long mac = 0;
        for(int j = 0; j < i; j++)
        {
        	if(a[i]>a[j]&&maxattime[j]>mac)
        	{
			   mac = maxattime[j];
		    }	
        }
        maxattime[i] = mac + 1;
        answer = max(answer,maxattime[i]);
	}
    cout << answer;
}
