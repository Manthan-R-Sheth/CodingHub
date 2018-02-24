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
	long long n,k;
	cin>>n>>k;
	long long a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(k-i-1>0)
		{
			k=k-i-1;
		}
		else
		{
			ans=a[k-1];
		}
	}
	cout<<ans<<endl;
}