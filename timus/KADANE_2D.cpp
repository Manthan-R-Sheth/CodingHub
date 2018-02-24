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

int max(int a ,int b)
{
	return (a>=b)?a:b;
}

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	int tmparray[n];
	int l=0,r=0,maxsum=INT_MIN;
	for(l=0;l<n;l++)
	{
		for(int i=0;i<n;i++)
		{
			tmparray[i]=a[i][l];
		}
		for(r=l;r<n;r++)
		{
			if(l!=r)
			{
				for(int i=0;i<n;i++)
				{
					tmparray[i]+=a[i][r];
				}
			}
			int currsum=maxSubArraySum(tmparray,n);
			maxsum=max(maxsum,currsum);
		}
	}
	cout<<maxsum<<endl;
}