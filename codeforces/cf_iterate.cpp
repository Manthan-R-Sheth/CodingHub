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

const long long m= (long long)1e9+7;

long long power(long long x, unsigned long long y, unsigned long long mod)
{
    if (y == 0)
        return 1;
    long long p = power(x, y/2, mod) % mod;
    p = (p * p) % mod;
 
    return (y%2 == 0)? p : (x * p) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long a,b,n,x;
	cin>>a>>b>>n>>x;

	if(a==1)
	{
		long long anshere=(x+(n % m)*(b % m)) % m;
		cout<<anshere<<endl;
		return 0;
	}

	long long tmp=power(a,n,m);
	long long ans1=tmp;
	ans1*=(x % m);
	ans1%=m;
	long long ans2=power((a-1),m-2,m);
	ans2*=(b % m);
	ans2%=m;
	long long ans3= (tmp-1) % m;
	ans2*=ans3;	
	ans2%=m;
	long long ans=(ans1+ans2) % m;
	cout<<ans<<endl;
}