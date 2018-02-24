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
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n],k[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			int h=0;
			for(int j=0;j<n;j++)
			{
				if(a[i]<=a[j])
				{
					h+=1;
				}
			}
			k[i]=h;
		}
		double ans=0.0;
		for(int i=0;i<n;i++)
		{
			ans+=(double)(1.0/(k[i]+1));
		}
		ans*=(n+1);
		printf("%.2f", ans);
		cout<<endl;
	}
}