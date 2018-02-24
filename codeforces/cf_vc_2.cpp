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
	int n;
	string s;
	cin>>n;
	cin>>s;
	int a[26];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		a[s[i]-'a']++;
	}

	int mini=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]>1)
		{
			mini+=(a[i]-1);
		}
	}
	if(n<27)
		cout<<mini<<endl;
	else
		cout<<"-1"<<endl;
}