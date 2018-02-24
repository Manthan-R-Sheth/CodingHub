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
	int nerased;
	cin>>nerased;
	pair<int,int> coor[nerased];
	for(int i=0;i<nerased;i++)
	{
		cin>>coor[i].first>>coor[i].second;
	}

	if(nerased==1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	else
		if(nerased==2)
		{
			if((coor[0].first==coor[1].first) || (coor[0].second==coor[1].second))
			{
				cout<<"-1"<<endl;
				return 0;
			}
			else
			{
				int a=abs(coor[0].first-coor[1].first);
				int b=abs(coor[0].second-coor[1].second);
				cout<<(a*b)<<endl;
			}
		}
		else
		{
			if(nerased==4)
			{
				sort(coor,coor+nerased);
				int a=abs(coor[0].second-coor[1].second);
				int b=abs(coor[2].first-coor[1].first);
				cout<<(a*b)<<endl;
			}
			else
			{
				sort(coor,coor+nerased);
				int a,b;
				if(coor[0].first==coor[1].first)
				{
					a=abs(coor[0].second-coor[1].second);
					if(coor[2].second==coor[0].second)
						b=abs(coor[0].first-coor[2].first);
					else
						b=abs(coor[1].first-coor[2].first);
				}

				else
				{
					a=abs(coor[2].second-coor[1].second);
					if(coor[2].second==coor[1].second)
						b=abs(coor[1].first-coor[2].first);
					else
						b=abs(coor[0].first-coor[2].first);
				}
				cout<<(a*b)<<endl;
			}
		}
}