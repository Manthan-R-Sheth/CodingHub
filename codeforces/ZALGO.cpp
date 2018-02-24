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
	string s="abcadsabcef";
	int len=s.length();
	int z[len];
	int left=0,right=0;
	z[0]=0;
	for(int k=0;k<len;k++) //len is the length of the string
	{
		if(k>right)
		{
			left=right=k;
			while(right<len && s[right]==s[right-left])
			{
				right++;
			}
			z[k]=right-left;
			right--;
		}
		else
		{
			int k1=k-left;
			if(z[k1]<(right-k+1))
			{
				z[k]=z[k1];
			}
			else
			{
				left=k;
				while(right<len && s[right]==s[right-left])
				{
					right++;
				}
				z[k]=right-left;
				right--;
			}
		}
	}

	for(int i=0;i<len;i++)
	{
		cout<<z[i]<<"    ";
	}
	cout<<endl;
}