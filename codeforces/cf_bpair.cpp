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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int happy=0;

	bool b[n];
	memset(b,false,sizeof(b));
	for(int i=0;i<n;i++)
	{
		b[i]=true;
		for(int j=i;j<n;j++)
		{
			if(a[j]>a[i] && b[j]==false)
			{
				b[j]=true;
				happy++;
				break;
			}
		}		
	}
	
	cout<<happy<<endl;
}