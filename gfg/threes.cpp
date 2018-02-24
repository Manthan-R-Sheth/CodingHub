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


int threes(int i)
{
	int d,ans=0;
	while(i>0)
	{
		d=i%10;
		if(d==3)
		{
			ans++;
		}
		i=i/10;
	}
	return ans;
}

int main()
{	
	int c=0;
	for(int i=100;i<10000;i++)
	{
		c+=threes(i);
	}
	cout<<c<<endl;
}