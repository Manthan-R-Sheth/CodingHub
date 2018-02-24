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

long long min(long long a,long long b)
{
	return (a<=b)?a:b;
}

int main()
{
	long long n;
	cin>>n;
	char dir[n];
	long long pos[n];
	for(int i=0;i<n;i++)
	{
		cin>>dir[i];
	}	

	for(int i=0;i<n;i++)
	{
		cin>>pos[i];
	}
	long long res=INT_MAX;

	for(int i=0;i<n;i++)
	{
		if((i==0 && dir[i]=='L') || (i==n-1 && dir[i]=='R'))
			continue;
		else
		{
			if(dir[i]=='L' && dir[i-1]=='R')
			{
				res=min(res,((pos[i]-pos[i-1])/2));
			}
			else
				if(dir[i]=='R' && dir[i+1]=='L')
				{
					res=min(res,((pos[i+1]-pos[i])/2));
				}
		}
	}
	if(res==INT_MAX)
		cout<<"-1"<<endl;
	else
		cout<<res<<endl;
}