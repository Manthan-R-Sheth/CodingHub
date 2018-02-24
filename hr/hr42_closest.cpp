#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main() 
{
	int n,mini=INT_MAX;
	cin>>n;
	vector<int> a;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		a.push_back(d);
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++)
	{
		if(abs(a[i]-a[i-1])<=mini)
		{
			mini=abs(a[i]-a[i-1]);
		}
	}
	for(int i=1;i<n;i++)
	{
		if(abs(a[i]-a[i-1])==mini)
		{
			v.push_back(make_pair(a[i-1],a[i]));
		}
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<" ";
	}
	cout<<endl;
}