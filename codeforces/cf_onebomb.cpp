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
	int n,m,walls=0;
	cin>>n>>m;
	char depot[n+1][m+1];
	int rows[n+1];
	int cols[m+1];
	memset(rows,0,sizeof(rows));
	memset(cols,0,sizeof(cols));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>depot[i][j];
			if(depot[i][j]=='*')
			{
				rows[i]++;
				cols[j]++;
				walls++;
			}
		}
	}
	int ansrow,anscol;
	int tmpwalls=0;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(depot[i][j]=='.')
			{
				tmpwalls=(rows[i]+cols[j]);
			}
			else
			{
				tmpwalls=(rows[i]+cols[j]-1);
			}
			if(tmpwalls==walls)
			{
				flag=true;
				ansrow=i;
				anscol=j;
			}
		}
	}

	if(flag)
	{
		cout<<"YES"<<endl;
		cout<<ansrow<<" "<<anscol<<endl;
	}	
	else
	{
		cout<<"NO"<<endl;
	}
}