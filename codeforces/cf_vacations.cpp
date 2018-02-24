#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int min(int a,int b)
{
	return (a<=b)?a:b;
}

int main()
{
	int n;
	cin>>n;
	int days[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>days[i];
	}

	int dp[n+1][3];
	memset(dp,10000,sizeof(dp));
	if(days[1]==0)
		dp[1][0]=1;
	else
	{
		if(days[1]==1)
		{
			dp[1][2]=0;
		}
		if(days[1]==2)
		{
			dp[1][1]=0;
		}
		if(days[1]==3)
		{
			dp[1][1]=dp[1][2]=0;
		}
	}

	for(int i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if(days[i]==0)
		{
			dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		}
		if(days[i]==1)
		{
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
		if(days[i]==2)
		{
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		}
		if(days[i]==3)
		{
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
	}
	cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;
}	