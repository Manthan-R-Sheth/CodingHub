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
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int j=0;
		s="";
		for(int i=0;i<n;i++)
		{
			if(j<26)
			{
				s+=(char)(97+j);
				j++;
			}
			else
			{
				j=0;
				i--;
			}
		}
		cout<<s<<endl;
	}
}