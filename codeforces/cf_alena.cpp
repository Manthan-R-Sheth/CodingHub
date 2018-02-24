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
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bool univ=false;
	int univhrs=0;
	for(int i=0;i<n-1;i++)
	{
		if(univ==false && a[i]==0)
		{
			continue;
		}
		else
			if(a[i]==1)
			{
				univhrs++;
				univ=true;
			}
			else
				if(a[i]==0 && a[i+1]==1)
				{
					univhrs++;
				}
				else
					if(a[i]==0 && a[i+1]==0)
					{
						univ=false;
					}
	}
	if(a[n-1]==1)
	{
		univhrs++;
	}
	cout<<univhrs<<endl;

}