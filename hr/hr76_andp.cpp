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
	int t;
	long long a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int l=(log(a)/log(2));
		int u=(log(b)/log(2));

		if(u>l)
		{
			cout<<"0"<<endl;
		}
		else
		{
			int d=floor(log(a)/log(2))+1;
			unsigned long long check;
			if(d==32)
				check=4294967296;
			else
				if(d==31)
					check=2147483648;
				else
					check=(1<<d);

			long long ans=0;
			while(d>0)
			{
				if((a & (check/2)) && (b & (check/2)))
				{
					ans+= pow(2,d-1);
					d--;
					check/=2;	
				}
				else
					if(!(a & (check/2)) && !(b & (check/2)))
					{
						check/=2;
						d--;
					}
					else
					{
						break;
					}
			}
			cout<<ans<<endl;
		}
	}
}
