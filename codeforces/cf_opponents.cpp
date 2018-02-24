#include<map>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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

int max(int a,int b)
{
	return (a>=b)?a:b;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n,d;
	long long count=INT_MIN,tmpcount=0;
	cin>>n>>d;
	string s[d];
	for(int i=0;i<d;i++)
	{
		cin>>s[i];
		bool flag=false;
		for(int j=0;j<s[i].length();j++)
		{
			if(s[i][j]=='0')
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			tmpcount++;
		}
		else
		{
			tmpcount=0;
		}
		count=max(count,tmpcount);
	}

	cout<<count<<endl;
}