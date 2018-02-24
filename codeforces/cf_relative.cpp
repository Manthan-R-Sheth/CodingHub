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
int min(int a,int b)
{
	return (a<=b)?a:b;
}
int main()
{
	int n;
	cin>>n;
	vector<char> gen;
	multimap<int,int> freetime;

	for(int i=0;i<n;i++)
	{
		char g;
		int a,b;
		cin>>g>>a>>b;
		gen.push_back(g);
		freetime.insert(make_pair(a,b));
	}
	int friends[n],value=0;
	multimap<int,int>::iterator it,it2;

	for(it=freetime.begin();it!=freetime.end();it++)
	{
		int female=0,male=0,innerval=0;
		if(gen[value]=='M')
		{
			male++;
		}
		else
		{
			female++;
		}
		for(it2=freetime.begin();it2!=freetime.end();it2++)
		{
			if(value!=innerval)
			{
				if( ( ((*it).first >= (*it2).first) && ((*it).first <= (*it2).second) ) 
					|| (((*it).second >= (*it2).first) && ((*it).second <= (*it2).second)))
				{
					if(gen[innerval]=='M')
						male++;
					else
						female++;
				}
			}
			innerval++;
		}
		friends[value]=2*min(male,female);
		value++;
	}
	sort(friends,friends+n);
	cout<<friends[n-1]<<endl;
}