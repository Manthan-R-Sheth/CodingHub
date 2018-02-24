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
	int chess[9][9];
	memset(chess,0,sizeof(chess));
	for(int i=1;i<9;i++)
	{
		for(int j=1;j<9;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='B')
				chess[i][j]=-1;
			if(ch=='W')
				chess[i][j]=1;
		}
	}

	set<pair<int,int> > result;
	for(int i=1;i<9;i++)
	{
		for(int j=1;j<9;j++)
		{
			int count=0;
			bool flag=true;
			if(chess[i][j]!=0)
			{
				if(chess[i][j]==1)
				{
					for(int k=i-1;k>0;k--)
					{
						if(chess[k][j]!=0)
						{
							flag=false;
							break;
						}
						count++;
					}
					if(flag)
					{
						result.insert(make_pair(count,1));
					}
				}
				else
				{
					for(int k=i+1;k<9;k++)
					{
						if(chess[k][j]!=0)
						{
							flag=false;
							break;
						}
						count++;
					}
					if(flag)
					{
						result.insert(make_pair(count,-1));
					}
				}
			}
		}
	}
	set<pair<int,int> >::iterator it=result.begin();
	int minmove=(*it).first;
	int playermin=(*it).second;
	it++;
	int nextminmove=(*it).first;
	int nextplayermin=(*it).second;
	if(minmove==nextminmove)
	{
		cout<<"A"<<endl;
		return 0;
	}
	if(playermin==1)
		cout<<"A"<<endl;
	else
		cout<<"B"<<endl;
}