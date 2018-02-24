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

int max(int a, int b)  {    return a > b ? a : b;  }
int min(int a, int b)  {    return a < b ? a : b;  }
int max(int a,int b,int c){  return max(a,max(b,c));}
int min(int a,int b,int c){ return min(a,min(b,c)); }

int getmaxvalue(int a[],int i,int n)
{
	if(i>=n)
		return 0;
	cout<<a[i]<<endl;
	return max(a[i]+min(getmaxvalue(a,i+2,n),getmaxvalue(a,i+3,n),getmaxvalue(a,i+4,n)),
				a[i]+a[i+1]+min(getmaxvalue(a,i+3,n),getmaxvalue(a,i+4,n),getmaxvalue(a,i+5,n)),
				a[i]+a[i+1]+a[i+2]+min(getmaxvalue(a,i+4,n),getmaxvalue(a,i+5,n),getmaxvalue(a,i+6,n)));
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<getmaxvalue(a,0,n)<<endl;
	}
}