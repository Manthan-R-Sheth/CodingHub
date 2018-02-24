#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<climits>
#include<string>
#include<cmath>
using namespace std;

#define inf 0x7fffffff
long long max(long long a, long long b) { return (a > b)? a : b; }

long long max(long long a, long long b, long long c) { return max(max(a, b), c); }

int main()
{
	// freopen("input.txt","r",stdin);
	long long t,n;
	vector<long long> a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a.clear();
		for(long long i=0;i<n;i++)
		{
			long long d;
			cin>>d;
			a.push_back(d);
		}
		long long dp[n+1][2];
		memset(dp,0,sizeof(dp));

		dp[0][0]=a[0];
		dp[0][1]=a[0];
		dp[1][0]=max(a[1],a[0]+a[1]);
		dp[1][1]=a[1];
		for(long long i=2;i<a.size();i++)
		{
			dp[i][0] = max(dp[i-1][0] + a[i],a[i]);
			dp[i][1] = max(dp[i-2][0] + a[i],dp[i-1][1] + a[i]);
		}

		long long mx = -inf;
		for (long long i = 0; i < a.size(); ++i)
		{
			mx = max(mx,dp[i][0]);
			mx = max(mx,dp[i][1]); 
		}

		cout<<mx<<endl;
	}
}