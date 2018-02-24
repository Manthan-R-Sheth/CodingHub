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
	long long n,x,distressed=0,current=0;
	cin>>n>>x;
	long long d;
	current=x;
	for(long long i=0;i<n;i++)
	{
		char ch;
		cin>>ch>>d;
		if(ch=='+')
		{
			current+=d;
		}
		else
			if(current>=d)
			{
				current-=d;
			}
			else
			{
				distressed++;
			}
	}
	cout<<current<<" "<<distressed<<endl;
}