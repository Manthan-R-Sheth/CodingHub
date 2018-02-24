#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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

int main()
{
	long long n;
	cin>>n;
	bool flag=false;
	
	while(true)
	{
		if(n>0)
		{
			n-=(1234567);
			cout<<n<<endl;
		}
		else
			if(n==0)
			{
				flag=true;
				break;
			}
			else
			{
				break;
			}
	}
	n+=(1234567);

	while(true)
	{
		if(n>0)
		{
			n-=(123456);
			cout<<n<<endl;
		}
		else
			if(n==0)
			{
				flag=true;
				break;
			}
			else
			{
				break;
			}
	}
	n+=(123456);

	while(true)
	{
		if(n>0)
		{
			n-=(1234);
		}
		else
			if(n==0)
			{
				flag=true;
				break;
			}

			else
			{
				break;
			}
	}

	if(flag)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
