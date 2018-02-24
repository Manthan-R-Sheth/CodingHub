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
#include<iomanip>
using namespace std;

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int s,v;
		cin>>s>>v;
		double tim=(s/(v+(v/2.0)));
		cout<<setprecision(20)<<tim<<endl;
	}
}