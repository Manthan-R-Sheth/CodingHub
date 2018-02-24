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

int main()
{
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		int year=0,yrvalue=0;
		cin>>s;
		int len= s.length()-4;

		for(int i=0;i<len;i++)
		{
			year+= (int)(s[s.length()-len+i]-'0')*pow(10,len-i-1);
		}

		
	}
}
