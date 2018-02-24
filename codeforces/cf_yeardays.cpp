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
	int friends[367];
	friends[0]=0;
	multimap<int,int>::iterator it;
	for(int i=1;i<367;i++)
	{
		int innerval=0,male=0,female=0;
		for(it=freetime.begin();it!=freetime.end();it++)
		{
			if( (i >= (*it).first) && (i<= (*it).second) )
			{
				if(gen[innerval]=='M')
					male++;
				else
					female++;
			}
			innerval++;
		}
		friends[i]=2*min(male,female);
	}
	sort(friends,friends+367);
	cout<<friends[366]<<endl;
}