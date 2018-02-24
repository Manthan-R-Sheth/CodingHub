#include<bits/stdc++.h>
using namespace std;
int n,c;

int func(int a[],int mid)
{
	int cows=1,pos=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]-pos>=mid)
		{
			pos=a[i];
			cows++;
			if(cows==c)
				return 1;
		}
	}
	return 0;
}

int bs(int a[])
{
	int in=0,last=a[n-1],maxi=-1;
	while(in<last)
	{
		int mid=(in+last)/2;
		if(func(a,mid)==1)
		{
			if(maxi<mid)
				maxi=mid;
			in=mid+1;
		}
		else
		{
			last=mid;
		}
	}
	return maxi;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		int ans=bs(a);
		cout<<ans<<endl;
	}
}