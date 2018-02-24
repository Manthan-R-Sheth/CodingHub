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
	long long dp[n+1][3];
	
	dp[1][0]=1;
	dp[1][1]=1;
	dp[1][2]=0;

	dp[2][0]=1;
	dp[2][1]=1;
	dp[2][2]=2;

	for(int i=3;i<=n;i++)
	{
		dp[i][0]=dp[i-1][1]+dp[i-2][1];
		dp[i][1]=dp[i-1][0]+dp[i-2][0];
		dp[i][2]=dp[i-1][0]+dp[i-1][1];
	}
	cout<<(dp[n][0]+dp[n][1])<<endl;
}