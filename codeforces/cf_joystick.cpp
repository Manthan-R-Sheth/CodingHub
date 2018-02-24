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
	int a1,a2;
	cin>>a1>>a2;
	long long minute=0;
	while(a1>0 && a2>0)
	{
		minute++;
		if(a1<a2)
		{
			a1+=1;
			a2-=2;

		}
		else
		{
			a1-=2;
			a2+=1;
		}
		if(a2<0 || a1<0)
			minute--;
	}
	cout<<minute<<endl;
}