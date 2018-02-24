#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<string>
#include<cmath>
using namespace std;


int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int count=0;
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
		if(a[0]>=b[0])
		{
			count++;
		}
		for(int i=1;i<n;i++)
		{
			if((a[i]-a[i-1])>=b[i])
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}