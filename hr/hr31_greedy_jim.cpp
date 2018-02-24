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
	int n,t,d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t>>d;
		int order=t+d;
		v.push_back(make_pair(order,i+1));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		cout<<v[i].second<<" ";
	}
	cout<<endl;
}