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

int main()
{	
	string s;
	bool mainflag=false;
	int a[26];
	for(int i=0;i<26;i++)
	{
		a[i]=0;
	}
	cin>>s;
	int i;
	for(i=0;i<s.length();i++)
	{
		bool flag=true;
		if(i+26<=s.length())
		{
			for(int j=0;j<26;j++)
			{
				if(s[i+j]!='?')
				{
					if(a[s[i+j]-'A']==0)
					{
						a[s[i+j]-'A']++;
					}			
					else
					{
						flag=false;
						break;
					}	
				}
			}
			if(flag)
			{
				mainflag=true;
				break;
			}
			for(int m=0;m<26;m++)
			{
				a[m]=0;
			}
		}
		else
		{
			break;
		}
	}
	if(mainflag)
	{
		for(int p=i;p<(i+26);p++)
		{
			if(s[p]=='?')
			{
				for(int k=0;k<26;k++)
				{
					if(a[k]==0)
					{
						s[p]=(char)(65+k);
						a[k]++;
						break;
					}
				}
			}
		}
		for(int m=0;m<s.length();m++)
		{
			if(s[m]=='?')
			{
				s[m]='A';
			}
		}
		cout<<s<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
}