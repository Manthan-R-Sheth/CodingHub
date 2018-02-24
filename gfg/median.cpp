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
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		int m[2*n];
		int i=0,j=0,k=0;
		while(i<n && j<n)
		{
			if(a[i]>=b[j])
			{
				m[k]=b[j];
				k++;
				j++;
			}
			else
			{
				m[k]=a[i];
				k++;
				i++;
			}
		}
		while(i<n)
		{
			m[k]=a[i];
			k++;
			i++;
		}

		while(j<n)
		{
			m[k]=b[j];
			k++;
			j++;
		}
		int sum=m[n-1]+m[n];
		cout<<sum<<endl;
	}
}