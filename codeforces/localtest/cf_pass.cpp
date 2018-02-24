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
	int i=2;
	while(i--)
	{
		ios_base::sync_with_stdio(false);
	    cin.tie(0);
		int n,s;
		cin>>n>>s;
		pair<int,int> pas[n];
		for(int i=0;i<n;i++)
		{
			cin>>pas[i].first>>pas[i].second;
		}
		sort(pas,pas+n);
		long long totime=0,tmptime,waitime=0;
		for(int i=n-1;i>=0;i--)
		{
			tmptime=(s - pas[i].first);
			s=pas[i].first;

			for(int j=0;j<=i;j++)
			{
				pas[j].second-=tmptime;
			}

			if(pas[i].second > 0)
			{
				waitime=pas[i].second;
			}
			else
				waitime=0;

			for(int j=0;j<i;j++)
			{
				pas[j].second-=waitime;
			}
			totime+=(tmptime+waitime);
		}
		totime+=(s);
		cout<<totime<<endl;
	}
}