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
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long tc=0;

	for(int i=0;i<k;i++)
	{
		tc+=a[n-i-1];
	}
	int i=0,x=1,count=0;
	while(i<(n-k))
	{
		tc+=(x+1)*a[n-k-1-i];
		i++;
		count++;
		if(count==k)
		{
			x++;
			count=0;
		}
	}

	cout<<tc<<endl;
}