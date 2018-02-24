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

int main()
{
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		int len=s.length();
		if(len%2==1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			int len1=(len/2);
			int freqs1[26],freqs2[26];
			memset(freqs1,0,sizeof(freqs1));
			memset(freqs2,0,sizeof(freqs2));
			for(int i=0;i<len1;i++)
			{
				freqs1[s[i]-'a']++;
				freqs2[s[i+len1]-'a']++;
			}
			int ans=0;
			for(int i=0;i<26;i++)
			{
				ans+=abs(freqs1[i]-freqs2[i]);
			}
			cout<<ans/2<<endl;
		}
	}
}