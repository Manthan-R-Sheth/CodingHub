#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<int> v;
vector<int> sorted;

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		v.push_back(d);
	}

	if(k>=n)
	{
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			cout<<v[n-1-i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=n;i>(n-k);i--)
		{
			sorted.push_back(i);
		}
		for(int i=k;i<n;i++)
		{
			if(v[i]<=(n-k))
			{
				sorted.push_back(v[i]);
			}
			else
			{
				while(v[i]>(n-k))
				{
					int tmp;
					tmp=v[i];
					v[i]=v[v.size()-tmp];
					v[v.size()-tmp]=tmp;
				}
				sorted.push_back(v[i]);
			}	
		}

		for(int i=0;i<n;i++)
		{
			cout<<sorted[i]<<" ";
		}
		cout<<endl;
	}
}