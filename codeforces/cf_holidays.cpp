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

int minioff(int n)
{
	int week=(n/7);
	int nfweek=(n%7);
	int ans=(week*2);
	if(nfweek>=5)
		ans+=(nfweek-5);
	
	return ans;
}

int maxioff(int n)
{
	int week=(n/7);
	int nfweek=(n%7);
	int ans=(week*2);
	if(nfweek>=2)
		ans+=2;
	else
		ans+=nfweek;

	return ans;
}

int main()
{
	int n;
	cin>>n;
	int mini=minioff(n);
	int maxi=maxioff(n);
	cout<<mini<<" "<<maxi<<endl;
}