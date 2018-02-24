#include<map>
#include<set>
#include<list>
#include<cmath>
#include<string>
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

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main()
{
	int a[5],b[101],best_remove=0;
	memset(b,0,sizeof(b));
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	sort(a,a+5);
	
	for(int i=0;i<5;i++)
	{
		if(i+1<5 && a[i]==a[i+1])
			best_remove=max(best_remove,2*a[i]);
		if(i+2<5 && a[i]==a[i+2])
			best_remove=max(best_remove,3*a[i]);
	}

	int sum=0;
	for(int i=0;i<5;i++)
	{
		sum+= a[i];
	}
	sum-=best_remove;
	cout<<sum<<endl;
}