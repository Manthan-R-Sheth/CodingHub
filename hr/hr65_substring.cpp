#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
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

void lcs(string a,string b)
{
	bool flag=false;
	for(int i=0;i<26;i++)
	{
		if(a.find(i+'a')<a.length() && b.find(i+'a')<b.length())
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;
}

int main()
{
	int t;
	cin>>t;
	string a,b;
	while(t--)
	{
		cin>>a;
		cin>>b;
		lcs(a,b);		
	}
}