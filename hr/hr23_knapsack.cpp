#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int DP(vector<int> a,int k,int dp[],int n)
{
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>i)
			{
				continue;
			}
			dp[i]=max(dp[i],a[j]+dp[i-a[j]]);
		}
	}
	return dp[k];
}

int main() 
{
	int t,k,n;
	cin>>t;
	vector<int> a;
	while(t--)
	{
		cin>>n>>k;
		int dp[k+1];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			int d;
			cin>>d;
			a.push_back(d);
		}
		sort(a.begin(),a.end());
		cout<<DP(a,k,dp,n)<<endl;
	}
}
	