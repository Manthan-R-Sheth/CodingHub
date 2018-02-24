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
	int n;
	cin>>n;
	string s;
	int bef[n],aft[n];

	for(int i=0;i<n;i++)
	{
		cin>>s>>bef[i]>>aft[i];
	}
	bool flag=false;

	for(int i=0;i<n;i++)
	{
		if(bef[i]>=2400)
		{
			if(aft[i]>bef[i])
			{
				flag=true;
				break;
			}

			else
			{
				continue;
			}
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
