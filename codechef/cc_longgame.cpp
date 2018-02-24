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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		pair<int,int> winner[n];
		for(int i=0;i<n;i++)
		{
			int c;
			cin>>c;
			int points=c;
			pair<int,int> types[6];
			for(int m=0;m<6;m++)
			{
				types[m].first=0;
				types[m].second=m;
			}
			for(int j=0;j<c;j++)
			{
				int tmp;
				cin>>tmp;
				tmp--;
				for(int m=0;m<6;m++)
				{
					if(types[m].second==tmp)
						types[m].first++;
				}
			}
			sort(types,types+6);
			for(int m=0;m<3;m++)
			{
				points+=(types[m].first*(pow(2,2-m)));
				for(int k=m+1;k<6;k++)
					types[k].first-=types[m].first;
			}
			winner[i].first=points;
			winner[i].second=i;
		}
		sort(winner,winner+n);
		if(winner[n-1].first==winner[n-2].first)
		{
			cout<<"tie"<<endl;
		}
		else
		{
			if(winner[n-1].second==0)
			{
				cout<<"chef"<<endl;
			}
			else
			{
				cout<<(winner[n-1].second+1)<<endl;
			}
		}
	}
}