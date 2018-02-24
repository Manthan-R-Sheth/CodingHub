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
	int q;
	long long a,b;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		long long res=0;
		cin>>a>>b;

		if((b-a+1)%2==0)
		{
			for(int j=a+1;j<=b;j+=2)
			{
				res^=j;
			}
		}
		else
		{
			res=1;
			for(int j=2;j<=a;j++)
			{
				res^=j;
			}
			for(int j=a+2;j<=b;j+=2)
			{
				res^=j;
			}
		}
		cout<<res<<endl;
	}
	
}
