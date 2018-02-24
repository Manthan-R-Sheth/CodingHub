#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
using namespace std;

long answer(long N)
{
	int n = ((N)?floor( log10(N)/log10(2) ) + 1:0); //calculate number of digits in advance floor(log2(N)) + 1
	vector <int> bin(32);
	for(int i=0;i<32;i++)
	{
		bin[i]=1;
	}
	int i = 0;
	while(N!=0) 
	{
		if(N%2==0)
			bin[i]=1;
		else
			bin[i]=0;
	    N/=2;
	    i++;
	}
	long d = 0,pre=31;
	while (pre>=0) 
	{
	    if (bin[pre]==1) 
	    {
	    	d += pow(2,pre);	    	
	    }
	    pre--;
	}
	return d;
}

int main()
{
	long n,d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		long ans=answer(d);
		cout<<ans<<endl;
	}
}