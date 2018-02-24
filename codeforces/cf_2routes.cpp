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
#include<iomanip>
#include<climits>
using namespace std;

int main()
{
	double e,sum;
	e=1;
	sum=1;
	for(int i=2;i<=10;i++)
	{
		e=1+(sum/(i-1));
		sum=sum+e;
		cout<<e<<endl;
	}
	cout<<setprecision(15)<<sum<<endl;
}