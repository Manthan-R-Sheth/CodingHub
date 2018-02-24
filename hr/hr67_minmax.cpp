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

int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);

	int unfairness=INT_MAX;

	for(int i=0;i<=n-k;i++)
	{
		int j=i+k-1;
		int tmp=a[j]-a[i];
		if(tmp<unfairness)
		{
			unfairness=tmp;
		}
	}
	cout<<unfairness<<endl;
}	