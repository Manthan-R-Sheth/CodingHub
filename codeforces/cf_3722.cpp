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
	long long mod=1000000000000000000;
	int n;
	cin>>n;
	cout<<2<<endl;
	for(int i=2;i<(n+1);i++)
	{
		long long a=((i+1)%mod)*((i+1)%mod);
		long long ans=((a*i)%mod)-(i-1);
		cout<<ans<<endl;
	}
}