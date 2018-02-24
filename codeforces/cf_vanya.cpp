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
	int n,h,ans=0;
	cin>>n>>h;
	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n;i++)
	{
		if(a[i]<=h)
			ans+=1;
		else
			ans+=2;
	}
	cout<<ans<<endl;	
}