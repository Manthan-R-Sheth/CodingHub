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

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n,k;
	cin>>n>>k;
	long long a[n+1],ans[n+1];
	double dp[n+1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=1000000007;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=log2(a[1]);
	ans[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		double mini=1000000007.0;
		int pos=0;
		for(int j=1;j<=k;j++)
		{
			if((i-j)>0)
				if(dp[i-j]<mini)
				{
					mini=dp[i-j];
					pos=(i-j);
				}
		}
		dp[i]=log2(a[i])+dp[pos];
		ans[i]=(long long)(a[i]*ans[pos])%1000000007;
	}
	cout<<ans[n]<<endl;
}