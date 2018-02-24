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
		return (b.first>a.first);
	}
}

int max(int a,int b)
{
	return (a>b)?a:b;
}
int ans=0;
int county=0;
int func(int a)
{
	if(a==1)
		return a;
	a--;
	ans+=func(a);
	county++;
	cout<<a<<endl;
	return a;
}

int main()
{	
	// set<int,int> s;
	// s.insert(make_pair(1,2));
	// set<int,int>::iterator it=s.begin();
	// for(;it!=s.end();it++)
	// {
	// 	cout<<(*it).first<<" "<<(*it).second<<endl;
	// }
	// ans=func(3);
	// cout<<ans<<endl;
	char* s;
	s="helloertertrtertert";
	// string s;
	cout<<sizeof(s)<<endl;
}