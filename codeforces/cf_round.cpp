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
	int n,a,b;
	cin>>n>>a>>b;
	if(b>=0)
	{
		int res=(a+b)%n;
		if(res==0)
			res=n;
		cout<<res<<endl;
	}
	else
	{
		int c=abs(b);
		int res;
		c%=n;
		if(c>(a-1))
		{
			c-=(a-1);
			res=(n-c+1);
			cout<<res<<endl;
		}
		else
		{
			res=a-c;
			cout<<res<<endl;
		}
	}
}