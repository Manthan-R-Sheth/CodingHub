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
	int n;
	cin>>n;
	long long a[n],steps=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n-1;i++)
	{
		steps+=abs(a[i+1]-a[i]);
	}
	steps+=abs(a[0]);
	cout<<steps<<endl;
}