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

long long max(long long a,long long b)
{
	return (a>=b)?a:b;
}

long long min(long long a,long long b)
{
	return (a<=b)?a:b;
}

long long distance(long long xi,long long yi,long long x,long long y)
{
	long long dis=pow(abs(xi-x),2)+pow(abs(yi-y),2);
	return dis;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long n,x1,y1,x2,y2;
	cin>>n>>x1>>y1>>x2>>y2;
	std::vector<pair<long long,long long> > dis;
	for(int i=0;i<n;i++)
	{
		long long xi,yi;
		cin>>xi>>yi;
		dis.push_back(make_pair(distance(xi,yi,x1,y1),distance(xi,yi,x2,y2)));
	}

	//****************************IMP STEP*******************************
	dis.push_back({0, 0});
	

	long long result=1e18;
	for(int i=0;i<dis.size();i++)
	{
		long long r1=dis[i].first;
		long long r2=0;
		for(int j=0;j<dis.size();j++)
		{
			if(dis[j].first > r1)
			{
				r2=max(r2,dis[j].second);
			}
		}
		result=min(result,(r1+r2));
	}

	cout<<result<<endl;
}