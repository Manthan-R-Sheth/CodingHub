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
	long long n,ans=1;
	cin>>n;
	long long a[n];
	std::vector<long long> counts;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			counts.push_back(i);
		}
	}
	if(counts.size()==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0;i<(counts.size()-1);i++)
	{
		ans*=(counts[i+1]-counts[i]);
	}
	cout<<ans<<endl;
}