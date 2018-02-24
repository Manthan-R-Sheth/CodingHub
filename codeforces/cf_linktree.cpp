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
	unsigned long long l,r,k,m=1,flag=0;
	cin>>l>>r>>k;
	while(m<=r && m<=1e18)
	{
		if(m>=l)
		{
			flag=1;
			cout<<m<<" ";
		}
		if(m>(r/k))
			break;
		m*=k;
	}
	if(flag==0)
		cout<<"-1";
	cout<<endl;
}