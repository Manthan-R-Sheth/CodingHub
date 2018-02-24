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

#define mod 1000000007

long long gcd(long long n1,long long n2)
{
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}

// To compute x^y under modulo m
long long power(long long x, unsigned long long y, unsigned long long m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}


// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
long long inv(long long a, long long m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
       return 0;
 
    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
}