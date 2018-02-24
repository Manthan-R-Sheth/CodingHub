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
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int sum=0,leftsum=0;
		bool flag=false;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=0;i<n;i++)
		{
			sum=sum-a[i];
			if(leftsum==sum)
			{
				flag=true;
				break;
			}
			leftsum+=a[i];
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}