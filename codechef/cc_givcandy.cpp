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
	int t;
	long long a,b,c,d,min;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;

		min=(c>d)?d:c;
		a%=min;
		b%=min;
		c%=min;
		d%=min;

		if(c==0)
		{
			if(abs(a-b)==d)
			{
				cout<<"0"<<endl;
			}
			else
			{
				long long mindiff=abs(a-b);
				while(mindiff>=0 && d!=0)
				{
					mindiff-=d;
				}
				cout<<(mindiff+d)<<endl;
			}
		}
		else
		{
			if(d==0)
			{
				if(abs(a-b)==c)
				{
					cout<<"0"<<endl;
				}
				else
				{
					long long mindiff=abs(a-b);
					while(mindiff>=0 && c!=0)
					{
						mindiff-=c;
					}
					cout<<(mindiff+c)<<endl;
				}
			}
		}		
	}
}