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
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		if(n==1)
		{
			cout<<a[0]<<endl;
			continue;
		}

		sort(a,a+n);
		if(a[n-1]==0)
		{
			cout<<"0"<<endl;
			continue;
		}

		int d= floor(log(a[n-1])/log(2)) + 1;
		int zeroans=n-1;
		unsigned long long result=0;
		int ans[100];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)
		{
			int tmp=floor(log(a[i])/log(2)) + 1;
			while(tmp>=0)
			{
				tmp--;
				if(a[i] & (1<<tmp))
				{
					ans[tmp+1]++;
				}
			}
		}

		for(int i=1;i<=d;i++)
		{
			int base=0;
			if(ans[i]>0)
				base=1;
			result= (result+(unsigned long long)pow(2*base,zeroans+i-1)) % 1000000007;
		}
		cout<<(result % 1000000007)<<endl;
	}	
}
