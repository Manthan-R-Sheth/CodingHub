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
	unsigned long long n;
	cin>>n;
	unsigned long long a[n],sum=0;
	for(unsigned long long i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	if(sum%2!=0)
	{
		for(unsigned long long i=0;i<n;i++)
		{
			if(a[i]%2!=0)
			{
				sum-=a[i];
				break;
			}
		}
	}
	cout<<sum<<endl;

}