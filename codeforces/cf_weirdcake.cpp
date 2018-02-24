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
	int n;
	cin>>n;
	char cake[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cake[i][j];
		}
	}
	long long ans=0;

	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(cake[i][j]=='C')
				count++;
		}
		ans+=(count*(count-1)/2);
	}

	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(cake[j][i]=='C')
				count++;
		}
		ans+=(count*(count-1)/2);
	}
	cout<<ans<<endl;
}