
//**********************************WORKING*****************************************************

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {
  	return lhs>rhs;
  }
};

int main()
{
	int q,type,v;
	set<int> a;
	cin>>q;
	while(q--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>v;
			a.insert(v);
		}
		else
			if(type==2)
			{
				cin>>v;
				set<int>:: iterator it=a.find(v);
				a.erase(*it);
			}
			else
			{
				set<int>:: iterator it=a.begin();
				cout<<*it<<endl;
			}
	}
    return 0;
}