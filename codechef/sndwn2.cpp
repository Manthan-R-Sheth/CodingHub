#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<string>
#include<cmath>
using namespace std;
int maxs,maxe;
int max(int a, int b) { return (a > b)? a : b; }
 
int max(int a, int b, int c) { return max(max(a, b), c); }

int maxcross(long a[],int s,int e,int m)
{
	int sum = 0;
    int leftsum = INT_MIN;
    for (int i = m; i >= s; i--)
    {
        sum = sum + a[i];
        if (sum > leftsum)
          leftsum = sum;
    }
    sum = 0;
    int rightsum = INT_MIN;
    for (int i = m+1; i <= e; i++)
    {
        sum = sum + a[i];
        if (sum > rightsum)
          rightsum = sum;
    }
    return leftsum + rightsum;

}

int maxarray(long a[],int s,int e)
{
	if(s==e)
	{
		return a[s];
	}
	else
	{
		int m=(s+e)/2;
		maxs=s;
		maxe=e;
		return max(maxarray(a,s,m),maxarray(a,m+1,e),maxcross(a,s,e,m));
	}
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int maxsum=maxarray(a,0,n-1);
		cout<<maxsum<<endl;
		cout<<maxs<<" "<<maxe<<endl;
	}
}