#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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
	unsigned long long n,m;
	cin>>n>>m;

	unsigned long long a[5],b[5];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));

	for(int i=1;i<=n;i++)
	{
		a[(i%5)]++;
	}

	for(int i=1;i<=m;i++)
	{
		b[(i%5)]++;
	}

	unsigned long long res=0;

	res+=(a[0]*b[0]);
	for(int i=1;i<5;i++)
	{
		res+=(a[i]*b[5-i]);
	}
	cout<<res<<endl;
}
