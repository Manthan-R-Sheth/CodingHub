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
#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)
{
	if(a.second!=b.second)
	{
		return (a.second<b.second);
	}
	else
	{
		return (b.first<a.first);
	}
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main()
{	
	int n,m,d;
	cin>>n>>m>>d;
	int dis[n+1];
	dis[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>dis[i];
	}

	if(m==0)
	{
		int mindist=dis[n]+abs(d-dis[n]);
		cout<<mindist<<endl;
		return 0;
	}

	pair<int,int>p[m];
	for(int i=0;i<m;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p,p+m,mycomp);


	// for(int i=0;i<m;i++)
	// {
	// 	cout<<p[i].first<<" pair "<<p[i].second<<endl;
	// }

	vector<pair<int,int> > s;
	s.push_back(make_pair(p[0].first,p[0].second));
	for(int i=1;i<m;i++)
	{
		if(p[i].second!=p[i-1].second)
		{
			s.push_back(make_pair(p[i].first,p[i].second));
		}
	}

	// for(int i=0;i<s.size();i++)
	// {
	// 	cout<<s[i].first<<" set s "<<s[i].second<<endl;
	// }


	vector<pair<int,int> > finals;
	int prevhigh=s[0].first;
	int prevlow=s[0].second;
	for(int i=0;i<s.size();i++)
	{
		if(s[i].second>prevhigh)
		{
			finals.push_back(make_pair(prevhigh,prevlow));
			prevlow=s[i].second;
			prevhigh=s[i].first;
		}
		else
		{
			prevhigh=max(prevhigh,s[i].first);
		}
	}
	finals.push_back(make_pair(prevhigh,prevlow));


	// for(int i=0;i<finals.size();i++)
	// {
	// 	cout<<finals[i].first<<" final s  "<<finals[i].second<<endl;
	// }	


	long long mindist=0;
	mindist=dis[(finals[0].second)-1];
	int prevdist=(finals[0].second-1);
	for(int i=0;i<finals.size();i++)
	{
		mindist+=(dis[finals[i].first]-dis[prevdist])+(dis[finals[i].first]-dis[finals[i].second]);
		prevdist=(finals[i].second);
	}
	if(finals[finals.size()-1].first==n)
		mindist+=abs(d-dis[prevdist]);
	else
	{
		mindist+=(dis[finals[finals.size()-1].first+1]-dis[prevdist]);
		mindist+=(dis[n]-dis[finals[finals.size()-1].first+1]);
		mindist+=abs(d-dis[n]);
	}
	cout<<mindist<<endl;
}	