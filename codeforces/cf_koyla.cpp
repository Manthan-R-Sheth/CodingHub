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
	string s;
	int k,ans=INT_MIN;
	cin>>s;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		s.append("#");
	}
	int len=s.length();

	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j+=2)
		{
			int n=(j-i+1)/2;
			bool flag=true;
			for(int m=0;m<n;m++)
			{
				if(s[m+i]!=s[n+m+i] && s[m+n+i]!='#')
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				
				ans=max(ans,n);
			}
		}
	}

	cout<<(2*ans)<<endl;
}