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
	int k,n;
	cin>>n>>k;
	long long dp[n+1][k],ans=0;
	memset(dp,0,sizeof(dp));

	for(int j=0;j<k;j++)
	{
		dp[1][j]=1;
	}

	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			for(int l=0;l<k;l++)
			{
				if(j==0 && l==0)
					continue;
				dp[i][j]+=dp[i-1][l];
			}
		}
	}

	for(int j=1;j<k;j++)
	{
		ans+=dp[n][j];
	}

	cout<<ans<<endl;
}