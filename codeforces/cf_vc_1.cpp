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
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n<=9)
		cout<<n<<endl;
	else
		if(n>9 && n<190)
		{
			n-=9;
			int a=n/2;
			if(n%2==0)
			{
				cout<<((9+a)%10)<<endl;
			}
			else
			{
				cout<<((10+a)/10)<<endl;
			}
		}

		else
		{
			n-=190;
			int d=n/3;
			int a=100+d;
			if(n%3==0)
			{
				cout<<(a/100)<<endl;
			}
			if(n%3==1)
			{
				cout<<((a/10)%10)<<endl;
			}
			if(n%3==2)
			{
				cout<<(a%10)<<endl;
			}
		}
}