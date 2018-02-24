#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

struct configs
{
	long long z,o,config10,config01;
};

int main()
{	
	long long a,b,c,d,o=-1,z=-1,l=-1;
	bool flag=false;
	cin>>a>>b>>c>>d;
	z=((1+sqrt(1+(8*a))))/2;
	o=((1+sqrt(1+(8*d))))/2;
	long long length=(a+b+c+d);
	l=((1+sqrt(1+(8*length))))/2;
	if(z==0 && o==0 && l==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(z==-1 || o==-1 || l==-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	//cout<<z<<" "<<o<<" "<<l<<endl;
	string s="0";
	queue<pair<string,configs*> > reqs;
	configs* present=(configs*)malloc(sizeof(configs));
	present->z=1;
	present->o=0;
	present->config10=0;
	present->config01=0;
	reqs.push(make_pair(s,present));
	while(!reqs.empty())
	{
		string s=reqs.front().first;
		configs* last=reqs.front().second;
		reqs.pop();
		string p=s;
		//append 0
		configs* present=(configs*)malloc(sizeof(configs));
		present->z=last->z+1;
		present->o=last->o;
		present->config10=last->config10+last->o;
		present->config01=last->config01;
		p+="0";
		if(present->z <= z &&
			present->o <= o &&
			present->config01 <=b &&
			present->config10 <= c &&
			p.length()<=l)
		{
			if(p.length()==l &&
				present->z == z &&
				present->o == o &&
				present->config01 ==b &&
				present->config10 == c)
			{
				cout<<p<<endl;
				flag=true;
				break;
			}
			reqs.push(make_pair(p,present));
		}

		//append 1
		configs* present1=(configs*)malloc(sizeof(configs));
		present1->z=last->z;
		present1->o=last->o+1;
		present1->config10=last->config10;
		present1->config01=last->config01+last->z;
		s+="1";
		if(present1->z <= z &&
			present1->o <= o &&
			present1->config01 <=b &&
			present1->config10 <= c &&
			s.length()<=l)
		{
			if(s.length()==l &&
				present1->z == z &&
				present1->o == o &&
				present1->config01 ==b &&
				present1->config10 == c)
			{
				cout<<s<<endl;
				flag=true;
				break;
			}
			reqs.push(make_pair(s,present1));
		}
	}
	if(!flag)
	{
		cout<<"Impossible"<<endl;
	}
}