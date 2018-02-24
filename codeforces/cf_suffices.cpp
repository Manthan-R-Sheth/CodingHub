//********************************** IMP DP QUESTION*********************************************

#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
#include<string>
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

bool check(string a,string b)
{
	if(a.compare(b)==0)
		return true;
	return false;
}

int main()
{
	string s;
	cin>>s;

	reverse(s.begin(),s.end());
	set<string> v;
	int n=s.length()-5;
	bool dp2[n+1],dp3[n+1];

	memset(dp2,false,sizeof(dp2));
	memset(dp3,false,sizeof(dp3));

	dp2[2]=dp3[3]=true;
	if(!check(s.substr(0,2),s.substr(2,2)))
	{
		dp2[4]=true;
	}
	dp2[5]=dp3[5]=true;

	for(int i=6;i<=n;i++)
	{
		dp2[i]=dp3[i-2] || (dp2[i-2] && !check(s.substr(i-4,2),s.substr(i-2,2)));
		dp3[i]=dp2[i-3] || (dp3[i-3] && !check(s.substr(i-6,3),s.substr(i-3,3)));
	}
	
	for(int i=2;i<=n;i++)
	{
		if(dp2[i])
		{
			string tmp=s.substr(i-2,2);
			reverse(tmp.begin(),tmp.end());
			v.insert(tmp);
		}
			
		if(dp3[i])
		{
			string tmp=s.substr(i-3,3);
			reverse(tmp.begin(),tmp.end());
			v.insert(tmp);
		}
	}
	cout<<v.size()<<endl;
	if(v.size()!=0)
	{
		for(set<string>::iterator it=v.begin();it!=v.end();it++)
			cout<<(*it)<<endl;
	}
}
