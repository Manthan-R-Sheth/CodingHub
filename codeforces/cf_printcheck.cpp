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
	map<int,pair<int, int> > rowtime;
	map<int,pair<int, int> > coltime;
	
	int n,m,k;
	cin>>n>>m>>k;
	int paper[n+1][m+1];
	for(int i=1;i<=k;i++)
	{
		int type,param,color;
		cin>>type>>param>>color;
		if(type==1)
		{
			rowtime[param]=make_pair(i,color);	
		}
		else
			if(type==2)
			{
				coltime[param]=make_pair(i,color);
			}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(rowtime[i].first >= coltime[j].first)
			{
				paper[i][j]=rowtime[i].second;
			}

			if(rowtime[i].first < coltime[j].first)
			{
				paper[i][j]=coltime[j].second;
			}
			cout<<paper[i][j]<<" ";
		}
		cout<<endl;
	}



}