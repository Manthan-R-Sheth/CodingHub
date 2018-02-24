
//**************************************ATTEMPT TO DP*************************
#include<bits/stdc++.h>
using namespace std;

int fib[20][100];

int main()
{
	int a,b,n,x;
	cin>>a>>b>>n;
	memset(fib, 0, sizeof(fib));
	fib[0][0]=a;
	fib[1][0]=b;
	for(int i=2;i<n;i++)
	{
		int a[100][100];
		memset(a, 0, sizeof(a));
		for(int j=0;j<100;j++)
		{
			int m=0,tmp=0,x=0;
			for(int k=0;k<100;k++)
			{
				x=fib[i-1][k]*fib[i-1][j]+tmp;
				a[j][k+j]=x%10;
				tmp=x/10;
			}
			while(tmp>0) 
             { 
               a[j][100+m+j]=tmp%10;
               tmp = tmp/10;
               m++; 
             }
		}
		int tmp=0;
		for(int k=0;k<100;k++)
		{
			int x=0;
			for(int j=0;j<100;j++)
			{
				x+=a[k][j];
			}
			x+=tmp;
			fib[i-1][k]=x%10;
			tmp=x/10;
		}
	}
}