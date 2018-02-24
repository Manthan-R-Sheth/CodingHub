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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long n;
	cin>>n;
	long long ans=1,x=n;
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	
	for(long long i = 2;i * i <= n; i++)	
		if(x % i == 0)
		{
			ans *= i;
			while(x % i == 0)
				x /= i;
		}
	if(x > 1)
		ans *= x;

	cout<<ans<<endl;
}