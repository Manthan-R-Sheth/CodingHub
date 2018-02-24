
// **************Attempt to DP***************8

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000000];
int min=1000000000;
int countMoves(int n)
{
	for(int i=0; i*i<n;i++)
	{
		if(n%i==0)
		{
			int max=max(i,n/i);
			dp[max]=(dp[max]==0)?countMoves(max):dp[max];
			if(dp[max]<min)
			{
				min=dp[max];
			}
		}

	}
	if(min!=1000000000)
	{
		int a=min;
		dp[n-1] = (dp[n-1] == 0) ? countMoves(n-1) : dp[n-1];
        dp[n] = min(a, dp[n-1]) + 1;
        return dp[n];
	}
	else
	{
		dp[n-1] = (dp[n-1] == 0) ? countMoves(n-1) : dp[n-1];
		dp[n] = dp[n-1] + 1;
        return dp[n];
	}
}

int main() 
{
	int q,n;
    cin>>q;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    while(q--)
    {
    	cin>>n;
    	int ans=countMoves(n);
    	cout<<n<<endl;
    }
    return 0;
}
