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

int min(int a,int b)
{
	return (a<=b)?a:b;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int amount[n],cost[n];
	for(int i=0;i<n;i++)
	{
		cin>>amount[i]>>cost[i];
	}

	int total=0,curcost=cost[0];
	for(int i=0;i<n;i++)
	{
		curcost=min(cost[i],curcost);
		total+=(amount[i]*curcost);
	}
	cout<<total<<endl;
}