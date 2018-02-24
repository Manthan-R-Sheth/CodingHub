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
	string a,b,c;
	int k;
	cin>>a;
	cin>>k;
	bool flag=true;
	int i=0;

	if(a.length() % k !=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	int len=a.length()/k;
	while(i<a.length())
	{
		b=a.substr(i,len);
		c=b;
		reverse(c.begin(),c.end());
		if(b.compare(c)!=0)
		{
			flag=false;
			break;
		}
		else
		{
			i+=len;
		}
	}

	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}