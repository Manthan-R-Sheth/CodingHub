#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<utility> 
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

//Objective Function
bool maxpossible(int cur,int a[],int b[],int k,int n)
{
	unsigned long long cnt=0;
	for(int i=0;i<n;i++)
	{
		unsigned long long tmp=a[i]*cur;
		if(tmp>b[i])
		{
			cnt+=(tmp-b[i]);
		}
		if(cnt>k)
			return false;
	}
	return true;
}

int main()
{
	int n,k;
	cin>>n>>k;

	int a[n],b[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];	
	}
	int cur,lo=0,hi=INT_MAX;
	
	while(lo<hi)
	{
		cur=lo + (hi-lo)/2;
		if(maxpossible(cur,a,b,k,n))
		{
			lo=cur+1;
		}
		else
		{
			hi=cur;
		}
		
	}
	cout<<cur<<endl;
}