
//***********************************************DP BY BOTTOM-UP *************************************

#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

int getMinSteps(int n)
{
	int dp[n+1];
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=1+dp[i-1];
		if(i%2==0)
		{
			dp[i]=min(1+dp[i/2],dp[i]);
		}
		if(i%3==0)
		{
			dp[i]=min(1+dp[i/3],dp[i]);
		}

	}
	return dp[n];

}

int main()
{
	int q,n,minSteps;
	cin>>q;
	while(q--)
	{
		cin>>n;
		minSteps=getMinSteps(n);
		cout<<minSteps<<endl;
	}
}