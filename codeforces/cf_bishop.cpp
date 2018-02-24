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
	long long n;
	cin>>n;
	std::map<int, int> add;
	std::map<int, int> sub;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add[x+y]++;
		sub[x-y]++;
	}
	std::map<int, int>::iterator it;
	long long sum=0;
	for(it=add.begin();it!=add.end();it++)
	{
		if((*it).second >1)
		{
			int tmp=(*it).second;
			sum+=(tmp*(tmp-1)/2);
		}
	}

	for(it=sub.begin();it!=sub.end();it++)
	{
		if((*it).second >1)
		{
			int tmp=(*it).second;
			sum+=(tmp*(tmp-1)/2);
		}
	}
	cout<<sum<<endl;
}