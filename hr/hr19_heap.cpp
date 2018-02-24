#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void remove(vector<int> &qheap, int value)
{
	vector<int>::iterator p;
	p=find(qheap.begin(),qheap.end(),value);
	qheap.erase(p);
	cout<<*p<<endl;
}

int main() 
{
	int q,type,v;
	vector<int> qheap;
	cin>>q;
	while(q--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>v;
			qheap.push_back(v);
		}
		else
			if(type==2)
			{
				cin>>v;
				remove(qheap,v);
			}
			else
			{
				//pop_heap(qheap.begin(), qheap.end(), greater<int>());
				make_heap(qheap.begin(),qheap.end());
				for(int i=0;i<qheap.size();i++)
				{
					cout<<qheap[i]<<endl;
				}
			}
	}
    return 0;
}
	