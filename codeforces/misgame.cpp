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
int mis=0,chris=0;
for(int i=0;i<n;i++)
{
	int m,c;
	cin>>m>>c;
	if(m>c)
	{
		mis++;
	}
	else
		if(c>m)
		{
			chris++;
		}
}
if(mis>chris)
{
	cout<<"Mishka"<<endl;
}
else
	if(chris>mis)
	{
		cout<<"Chris"<<endl;
	}
	else
		cout<<"Friendship is magic!^^"<<endl;
}