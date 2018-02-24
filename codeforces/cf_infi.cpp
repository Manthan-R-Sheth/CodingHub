#include<map>
#include<set>
#include<list>
#include<cmath>
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
	long long a,b,d;
	cin>>a>>b>>d;
	if(d!=0)
	{
		if((b-a)%d==0 && (b-a)*d >= 0)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	else
		if(a==b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
}