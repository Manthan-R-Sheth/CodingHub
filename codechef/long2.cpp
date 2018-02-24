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
		long long n,m,c;
		cin>>n>>m;
		cin>>c;
		long long pro=(n*m);
		if(pro<c)
		{
			cout<<"0"<<endl;
			continue;
		}
		long long pairs=0;
		for(long long i=1;i<=c;i++)
		{
			if(c%i==0)
			{
				long long h=i,w=(c/i);
				if(h<=n&&w<=m)
					pairs++;
			}
		}
		cout<<pairs<<endl;
	}
}