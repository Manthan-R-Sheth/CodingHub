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
	int n;
	cin>>n;
	int v[n+1],d[n+1],p[n+1];
	bool visited[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>d[i]>>p[i];
		visited[i]=false;
	}
	visited[1]=true;
	int visitedtillnow;
	for(int i=2;i<=n;i++)
	{
		visitedtillnow=0;
		for(int j=i-1;j>0;j--)
		{
			if(visited[j]==true)
			{	
				visitedtillnow++;
				if((v[j]-(visitedtillnow)+1) >=0)
					p[i]-=(v[j]-(visitedtillnow)+1);
			}
		}
		if(p[i]<0)
		{
			visited[i]=false;
			for(int j=i+1;j<=n;j++)
			{
				p[j]-=d[i];
			}
		}
		else
			visited[i]=true;
	}
	int count=0;

	for(int i=1;i<=n;i++)
	{
		cout<<p[i]<<endl;
	}

	for(int i=1;i<=n;i++)
	{
		if(visited[i]==true)
			count++;
	}
	cout<<count<<endl;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==true)
			cout<<i<<" ";
	}
	cout<<endl;
}