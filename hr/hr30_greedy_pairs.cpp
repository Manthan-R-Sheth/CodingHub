//*********************************************ATTEMPT TO GREEDY ALGO*********************************************

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

vector<pair<int,int> > v;
int main()
{
	int n,count=0;
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

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				v.push_back(make_pair(i,j));
			}
		}
	}

	for(int i=0;i<v.size();i++)
	{
		int flag=0;
		for(int j=0;j<v.size();j++)
		{
			if((v[i].first==v[j].first) || (v[i].second==v[j].second))
			{
				flag++;
			}
		}
		if(flag==1)
		{
			count++;
		}
	}
	cout<<count<<endl;

}