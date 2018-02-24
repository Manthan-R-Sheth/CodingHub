#include<map>
#include<set>
#include<list>
#include<cmath>
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

long long findMaxProduct(int A[], int n, int k)
{
	long long ans=1,maxans=1;
	for(int i=0;i<k;i++)
	{
		ans*=A[i];
	}
	maxans=ans;
	for(int i=k;i<n;i++)
	{
		ans*=A[i];
		ans/=A[i-k];
		if(ans>maxans)
			maxans=ans;
	}
	return maxans;
}

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		int a[n];
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long ans=findMaxProduct(a,n,k);
		cout<<ans<<endl;
	}
}