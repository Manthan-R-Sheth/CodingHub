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
	unsigned long long t,n,c,a=2,b,m,sum,y,m1;
	bool flag;
	cin>>t;
	while(t--)
	{
		flag=false;
		cin>>n>>c;
		if(n%2!=0 && c%n!=0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		//if(n!=1)
			// if(c%(n/2)!=0)
			// {
			// 	cout<<"NO"<<endl;
			// 	continue;
			// }	
		if(n==1)
		{
			cout<<"YES"<<endl;
			continue;
		}
			
		m=((2*c)/n);
		m1=m;
		b=(n-1);
		sum=a+b;
		while(m>=sum)
		{
			m-=b;
			if(m%a==0)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			cout<<"YES"<<endl;
			cout<<(m1-m)/b<<endl;

		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}