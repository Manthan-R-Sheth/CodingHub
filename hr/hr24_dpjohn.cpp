#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

bool primes[1000001];

int getans(int n,int dp[][5])
{
	dp[1][4]=dp[2][4]=dp[3][4]=1;
	dp[4][4]=2;
	for(int i=5;i<=n;i++)
	{
		dp[i][4]=dp[i-4][4]+dp[i-1][4];				
	}
	return dp[n][4];
}
//****************************SEIVE OF ERATOSTHENES************************
void genprimes(int a)
{
	memset(primes,true,sizeof(primes));
	primes[0]=false;
	primes[1]=false;
	for(int p=2;p*p<=a;p++)
	{
		if(primes[p]==true)
		{
			for(int i=p*2;i<=a;i+=p)
			{
				primes[i]=false;
			}
		}
	}
}

int getprimes(int a)
{
	int counter=0,tracker=0;
	while(tracker<=a)
	{
		if(primes[tracker]==true)
		{
			counter++;
		}
		tracker++;
	}
	return counter;
}

int main() 
{
	int t,n;
	genprimes(1000000);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int dp[n+1][5];
		memset(dp,0,sizeof(dp));
		int a=getans(n,dp);
		cout<<getprimes(a)<<endl;
	}

}
