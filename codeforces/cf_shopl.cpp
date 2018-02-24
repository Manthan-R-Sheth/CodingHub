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
	int n;
	cin>>n;
	int row1[n-1],row2[n-1],av[n];
	for(int i=0;i<n-1;i++)
	{
		cin>>row1[i];
	}
	int sumrow1[n-1];
	sumrow1[0]=row1[0];
	for(int i=1;i<n-1;i++)
	{
		sumrow1[i]= row1[i]+ sumrow1[i-1];
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>row2[i];
	}
	int sumrow2[n-1];
	sumrow2[0]=row2[n-2];
	for(int i=1;i<n-1;i++)
	{
		sumrow2[i]= row2[n-2-i]+ sumrow2[i-1];
	}
	for(int i=0;i<n;i++)
	{
		cin>>av[n-1-i];
	}

	long long d[n];
	for(int i=0;i<n;i++)
	{
		int di=av[i];
		if(i==0)
			di+=sumrow1[n-2];
		else
			if(i==n-1)
				di+=sumrow2[n-2];
			else
				di+=sumrow1[n-2-i]+sumrow2[i-1];
		d[i]=di;
	}
	sort(d,d+n);
	int mintime=(d[0]+d[1]);
	cout<<mintime<<endl;
}