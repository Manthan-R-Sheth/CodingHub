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
	int n;
	cin>>n;
	if(n==3)
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(n==4)
	{
		cout<<"4"<<endl;
		return 0;
	}
	long long ans=pow((n-2),2);
	cout<<ans<<endl;
}