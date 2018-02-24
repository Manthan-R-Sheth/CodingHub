#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<utility> 
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>

const long long linf = 0x3f3f3f3f3f3f3f3fLL;

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	long long bote,botenergy;
	long long lo=0,hi=linf;
	bool flag;

	while(lo<hi)
	{
		bote=(lo+hi)/2;
		botenergy=bote;
		for(int i=1;i<=n;i++)
		{
			flag=true;
			if(bote<a[i])
			{
				long long tmp=a[i]-bote;
				bote-=tmp;
			}
			else
			{
				long long tmp=bote-a[i];
				bote+=tmp;
			}
			if(bote<0)
			{
				flag=false;
				break;
			}
			if(bote>=linf)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			hi=botenergy;
		}
		else
		{
			lo=botenergy+1;
		}
	}
	cout<<botenergy<<endl;
}	