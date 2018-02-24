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

int main()
{
	long sum=0;
	for(int i=1;i<1000;i++)
	{
		if(i%3==0)
			sum+=i;
		if(i%5==0)
			sum+=i;
		if(i%15==0)
			sum-=i;
	}
	cout<<sum<<endl;
}