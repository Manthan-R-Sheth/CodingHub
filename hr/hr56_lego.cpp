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

int max(int a,int b)
{
	return (a>=b)?a:b;
}

void lcs(int a[],int b[],int n,int m)
{
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
				continue;
			}
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
				continue;
			}
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	int index=dp[n][m];
	int lcssize=index;
	int lcsi[index];

   int i = n, j = m;
   while (i > 0 && j > 0)
   {
      
      if (a[i-1] == b[j-1])
      {
	    lcsi[index-1] = a[i-1]; 
	    i--; 
	    j--; 
	    index--;
      }
 
      else 
      	if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
   	}
 
	for(int i=0;i<lcssize;i++)
	{
		cout<<lcsi[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}

	lcs(a,b,n,m);
}