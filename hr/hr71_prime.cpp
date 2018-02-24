#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<utility> 
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

bool primeFactors(unsigned long long n)
{
	unsigned long long maxi=0;
	unsigned long long tmp=n;
	if(n==1)
		return false;
	
    while (n%2 == 0)
    {
    	if(2>maxi)
    		maxi=2;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
        	if(i>maxi)
    			maxi=i;
            n = n/i;
        }
    }
    if (n > 2)
    {
    	if(n>maxi)
    		maxi=n;
    }

    unsigned long long count=0;
    while (tmp%maxi == 0)
    {
    	count++;
        tmp = tmp/maxi;
    }
    if(count>1)
    	return true;
    else
    	return false;
}
 

int main()
{
	int t;
	unsigned long long n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		if(primeFactors(n))
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}	
}	