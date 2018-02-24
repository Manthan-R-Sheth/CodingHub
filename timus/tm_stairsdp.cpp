#include<map>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	long long dp[n+1][n+1],ans=0;
	memset(dp,0,sizeof(dp));

	dp[1][1]=1;
	dp[2][2]=1;
	dp[3][3]=1;
	dp[3][2]=1;
	dp[4][4]=1;
	dp[4][3]=1;

	for(int i=0;i<=n;i++)
	{
		dp[i][i]=1;
	}

	for(int i=5;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(i>j)
					dp[i][j]+=dp[i-j][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=dp[n][i];
	}
	cout<<ans-1<<endl;
}