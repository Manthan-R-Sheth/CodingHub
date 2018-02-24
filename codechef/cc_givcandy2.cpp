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

long long min(long long a,long long b)
{
	return (a>b)?b:a;
}

long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    long long x1, y1; 
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int main()
{
	int t;
	long long a,b,c,d,x,y,gcd;
	cin>>t;
	while(t--)
	{
		x=0,y=0;
		cin>>a>>b>>c>>d;
		gcd=gcdExtended(c,d,&x,&y);
		cout<<min(abs(a-b)%(gcd),gcd-(abs(a-b)%(gcd)))<<endl;
	}
}