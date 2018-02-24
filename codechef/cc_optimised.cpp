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

int maxSubArraySum(long a[], int size)
{
    int maxsofar = 0, maxendinghere = 0;
 
    for (int i = 0; i < size; i++)
    {
        maxendinghere = maxendinghere + a[i];
        if (maxendinghere < 0)
        {
            maxendinghere = 0;
            maxs=i;
        }
        if (maxsofar < maxendinghere)
        {
            maxsofar = maxendinghere;
            maxe=i;
        }
    }
	if(maxs>maxe && (maxe!=0))
    {
    	maxs=maxe-1;
    }
    if(maxe==0)
    {
    	maxs=0;
    }
    return maxsofar;
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		maxs=0;
		maxe=0;
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int maxsum=maxSubArraySum(a,n);
		
		if(maxe==0 && maxs==0)
		{
			int maxi=INT_MIN;
			for(int i=0;i<n;i++)
			{
				if(a[i]>maxi)
				{
					maxi=a[i];
				}
			}
			cout<<maxi<<endl;
		}
		else
		{
			std::vector<long> resultarr;
			for(int i=maxs+1;i<=maxe;i++)
			{
				resultarr.push_back(a[i]);
			}

			sort(resultarr.begin(),resultarr.end());
			
			if(resultarr[0]<0)
			{
				maxsum-=resultarr[0];
			}
			cout<<maxsum<<endl;
		}
	}
}