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
	int n;
	cin>>n;
	int a[n+1],sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}

	int eachper=(2*sum)/n;
	bool taken[n+1];
	memset(taken,false,sizeof(taken));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i!=j))
			{
				if(a[j]==(eachper-a[i]) && !taken[j] && !taken[i])
				{
					taken[i]=true;
					taken[j]=true;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
}