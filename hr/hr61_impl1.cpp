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
	int t,n;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			int count=0;
			for(int j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					count++;
				}
			}
			ans+=count;
		}
		if(ans%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}