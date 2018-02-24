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

bool wayToSort(int i, int j) { return i > j; }

int max(int a,int b)
{
	return (a>=b)?a:b;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	double p[n],ans=-1.0;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}

	sort(p,p+n);
	for(int i=0;i<n;i++)
	{
		double a=0.0,pro=1.0;
		for(int j=i;j<n;j++)
		{
			a=((a*(1-p[j]))+(pro*p[j]));
			pro*=(1-p[j]);
			ans=max(ans,a);
		}
	}
	cout<<setprecision(16);
	cout<<ans<<endl;
}