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
long long dp[251];

void getWays(int a[],int n,int m)
{
	dp[0]=1;
	for(int i=0; i<m; i++)
	{
        for(int j=a[i]; j<=n; j++)
        {
            dp[j] += dp[j-a[i]];
        }
    }
	cout<<dp[n]<<endl;
}

int main()
{
	int n,m;
	fill(dp,dp+251,0);
	cin>>n>>m;
	int a[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	getWays(a,n,m);
}