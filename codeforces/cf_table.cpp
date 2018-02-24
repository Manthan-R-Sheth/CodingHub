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
    int n,k;
	cin>>n>>k;
	int ans[n][n];
	memset(ans,-1,sizeof(ans));

	for(int j=k-1,m=0;j<n;j++,m++)
	{
		for(int i=0;i<n;i++)
		{
			ans[i][j]=((n*n)-((i+1)*(n-k))-i)+m;
		}
	}
	int counter=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(k-1);j++)
		{
			if(ans[i][j]==-1)
			{
				ans[i][j]=counter+1;
				counter++;
			}
		
		}
	}
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(ans[i][k-1]);
	}
	cout<<sum<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}