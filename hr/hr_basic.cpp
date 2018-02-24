#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


int main() 
{
	int v,n,ans;
	cin>>v;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(v==a[i])
		{
			ans=i;
		}
	}
	cout<<ans<<endl;
}