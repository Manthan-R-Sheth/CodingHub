#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<int> v;

int main()
{
	int n,cost=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		v.push_back(d);
	}
	sort(v.begin(),v.end());

	for(int i=0;i<v.size();)
	{
		int j=i+1;
		while(v[j]<=v[i]+4 && j<v.size())
		{
			j++;
		}
		i=j;
		cost++;
	}
	cout<<cost<<endl;

}