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
#include<iomanip>
using namespace std;

int main()
{	
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		string l1,l2,l3;
		cin>>l1>>l2>>l3>>n;
		long long rep=0,reprep=0;
		bool flag=true;
		reverse(l1.begin(),l1.end());
		reverse(l2.begin(),l2.end());
		reverse(l3.begin(),l3.end());
		for(long long i=0;i<l3.length();i++)
		{
			if(l3[i]=='1')
				rep++;
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			for(long long i=0;i<l2.length();i++)
			{
				if(l2[i]=='1')
					reprep++;
				else
				{
					flag=false;
					break;
				}
			}
			if(!flag)
				rep+=reprep;
			if(flag)
			{
				reprep*=n;
				for(long long i=0;i<l1.length();i++)
				{
					if(l1[i]=='1')
						rep++;
					else
					{
						flag=false;
						break;
					}
				}
				rep+=reprep;
			}
		}
		long long ones=1,onesrep=0;
		for(long long i=0;i<l1.length();i++)
		{
			if(l1[i]=='1')
				ones++;
		}
		for(long long i=0;i<l2.length();i++)
		{
			if(l2[i]=='1')
				onesrep++;
		}
		for(long long i=0;i<l3.length();i++)
		{
			if(l3[i]=='1')
				ones++;
		}

		ones+=(onesrep*n);
		ones-=rep;
		cout<<ones<<endl;
	}
}