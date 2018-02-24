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
	long long n,k;
	cin>>n>>k;
	long long beauty[n],capital[k],capitalbeauty[k];
	long long sumbeauty=0;
	for(int i=0;i<n;i++)
	{
		cin>>beauty[i];
		sumbeauty+=beauty[i];
	}
	for(int i=0;i<k;i++)
	{
		int capitacity;
		cin>>capitacity;
		capital[i]=capitacity-1;
	}
	capitalbeauty[0]=0;
	if(capital[1]!=capital[0]+1)
		capitalbeauty[1]=beauty[capital[0]];
	else
		capitalbeauty[1]=0;
	for(int i=2;i<k;i++)
	{
		if(capital[i]!=capital[i-1]+1)
		{
			if(capital[i]==(n-1)&& capital[0]==0)
				capitalbeauty[i]=capitalbeauty[i-1]+beauty[capital[i-1]]-beauty[0];
			else
				capitalbeauty[i]=capitalbeauty[i-1]+beauty[capital[i-1]];
		}
			
		else
		{
			if(capital[i]==(n-1)&& capital[0]==0)
				capitalbeauty[i]=capitalbeauty[i-1]-beauty[0];
			else
				capitalbeauty[i]=capitalbeauty[i-1];		
		}
	}
	long long cost=0;
	for(int i=0;i<n;i++)
	{
		cost+=beauty[i%n]*beauty[(i+1)%n];
	}
	for(int i=0;i<k;i++)
	{
		cost+=beauty[capital[i]]*(sumbeauty-beauty[capital[i]]-beauty[(capital[i]+1)%n]);
		if((capital[i]-1)==-1)
			cost-=beauty[n-1]*beauty[capital[i]];
		else
			cost-=beauty[capital[i]-1]*beauty[capital[i]];
		cost-=beauty[capital[i]]*capitalbeauty[i];
	}
	cout<<cost<<endl;
}