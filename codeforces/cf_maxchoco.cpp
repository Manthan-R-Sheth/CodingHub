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

long long gcd(long long a, long long b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm( long long a, long long b)
{
	long long lcm=((a*b)/gcd(a,b));
	return lcm;
}

long long max( long long a, long long b)
{
	return (a>=b)?a:b;
}

int main()
{
	long long n,a,b,p,q,red,blue,common,compensate,total,lcm2;
	cin>>n>>a>>b>>p>>q;
	red=(p*(n/a));
	blue=(q*(n/b));
	lcm2=lcm(a,b);
	common=((p+q)*(n/lcm2));
	compensate=(max(p,q)*(n/lcm2));
	total=(red+blue-common+compensate);
	cout<<total<<endl;
}