#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	set<int> v;
	map<int, int> info;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		info.insert(make_pair(a[i],i));
	}
	stack<int> s;
	s.push(a[0]);
	for(int i=1;i<n;i++)
	{
		int cur=a[i];
		if(!s.empty())
		{
			int e=s.top();
			s.pop();
			while(e<cur)
			{
				v.insert(cur);
				if(s.empty())
				{
					break;
				}
				e=s.top();
				s.pop();
			}
			if(e>cur)
			{
				s.push(e);
			}
		}
		s.push(cur);
	}
	while(!s.empty())
	{
		v.insert(-1);
		s.pop();
	}
	set<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		map<int, int>::iterator it1=info.find(*it);
		cout<<(it1->second)<<" ";
	}
	cout<<endl;
}

