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
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long m;
		for(m=1;m<n;)
		{
			if(m*2 > n)
				break;
			m*=2;
		}
		cout<<m<<endl;
	}
}