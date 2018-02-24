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
	int l,d;
	cin>>l>>d;
	string s;
	cin>>s;
	int len=l;
	char anew[26];

	for(int j=0;j<26;j++)
	{
		anew[j]='M';
	}

	for(int i=0;i<len;i++)
	{
		int ch=(s[i]-'a');
		anew[ch]=(s[i]);
	}

	for(int i=0;i<d;i++)
	{
		char old,next;
		cin>>old>>next;
		for(int j=0;j<26;j++)
		{
			bool flag=true;
			if(anew[j]==(old))
			{
				anew[j]=next;
				flag=false;
			}

			if(anew[j]==(next) && flag==true)
			{
				anew[j]=old;
			}
		}
	}
	char result[len];
	for(int i=0;i<len;i++)
	{
		char newchar= anew[s[i]-'a'];
		result[i]=newchar;
		cout<<result[i];
	}
	cout<<endl;
}