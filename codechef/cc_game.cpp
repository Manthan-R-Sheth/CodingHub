#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int dp[6];
int grundy(long long i)
{
	while(i>5)
	{
		i/=12;
	}
	return dp[i];
}

int main()
{
	int t,n;
	cin>>t;
	dp[0]=0;
	dp[1]=1;
	dp[2]=dp[3]=2;
	dp[4]=dp[5]=3;
	while(t--)
	{
		cin>>n;
		long long a[n];
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ans^=grundy(a[i]);
		}
		if(ans==0)
		{
			cout<<"Derek"<<endl;
		}
		else
		{
			cout<<"Henry"<<endl;
		}
	}
}