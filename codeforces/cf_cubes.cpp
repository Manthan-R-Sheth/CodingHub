#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
#include<string>
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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);

	long long result=0;
	result=a[n-1];
	long long tmp=0;
	for(int i=0;i<n;i++)
	{
		tmp+=a[i];
	}
	tmp-=a[n-1];
	result-=tmp;
	result+=1;
	cout<<result<<endl;
	
}
