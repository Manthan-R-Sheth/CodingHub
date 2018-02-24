#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<utility> 
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

long long max(long long a,long long b,long long c)
{
	return max(max(a,b),c);
}

long long max(long long a,long long b)
{
	return (a>b)?a:b;
}

int main()
{
	int n,t;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long dp[n+1];
		dp[1]=0;
		dp[2]=1;
		dp[3]=2;
		for(long long i=4;i<=n;i++)
		{
			long long maxi=1;
			for(long long j=2;j<i;j++)
			{
				maxi=max(maxi,(dp[i-j]*j),(j*(i-j)));
			}
			dp[i]=maxi;
		}
		cout<<dp[n]<<endl;
	}	
}	