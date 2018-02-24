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
#define maxn 1000011
int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int power[maxn],dp[maxn],mx=INT_MIN;
	memset(dp,0,sizeof(dp));
	memset(power,0,sizeof(power));
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		cin>>power[tmp];
	}
	if(power[0]!=0)
		dp[0]=1;

	for(int i=1;i<maxn;i++)
	{
		if(power[i]==0)
			dp[i]=dp[i-1];
		else
		{
			if(power[i]>=i)
				dp[i]=1;
			else
				dp[i]=dp[i-power[i]-1]+1;
		}

		if(dp[i]>mx)
			mx=dp[i];
		
	}
	cout<<(n-mx)<<endl;
	return 0;
}