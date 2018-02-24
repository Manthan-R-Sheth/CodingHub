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
	int t,n,m;
	char coll[11][11];
	int colldetect[11];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		memset(colldetect,0,sizeof(colldetect));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>coll[i][j];
				if(coll[i][j]=='1')
				{
					colldetect[j]=colldetect[j]+1;
				}
			}
		}

		long long sum=0;
		for(int j=1;j<=m;j++)
		{
			int tmp=colldetect[j];
			sum+=(tmp*(tmp-1)/2);
		}
		cout<<sum<<endl;
	}
}