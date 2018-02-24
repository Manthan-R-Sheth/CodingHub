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
	int n,m,q;
	cin>>n>>m>>q;
	int states[n+1][m+1];
	int maxconsec[n+1];
	for(int i=1;i<=n;i++)
	{
		int row=0,maxinrow=0;
		for(int j=1;j<=m;j++)
		{
			cin>>states[i][j];
			if(states[i][j]==1)
			{
				row++;
				if(maxinrow<row)
					maxinrow=row;
			}
			else
				row=0;
		}
		maxconsec[i]=maxinrow;
	}

	for(int i=1;i<=q;i++)
	{
		int r,c;
		cin>>r>>c;
		if(states[r][c]==1)
		{
			states[r][c]=0;
		}
		else
		{
			states[r][c]=1;
		}
		int row=0,maxinrow=0;
		for(int j=1;j<=m;j++)
		{
			if(states[r][j]==1)
			{
				row++;
				if(maxinrow<row)
					maxinrow=row;
			}
			else
				row=0;
		}
		maxconsec[r]=maxinrow;
		int maxi=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(maxconsec[i]>maxi)
				maxi=maxconsec[i];
		}
		cout<<maxi<<endl;
	}
}