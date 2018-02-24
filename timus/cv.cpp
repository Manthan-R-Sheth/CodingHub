#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
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
   sort(a, a+n);
   int diff = 1e9,maxi,mini;
   int att;
   if(n%4==0)
   	att = 0.75*n;
   else
   	att = 0.75*n +1;
   if(n==1)
   {
   	cout<<a[0]<<" "<<a[0]+1<<endl;
   	return 0;
   }
   for (int i=n-1; i>=1; i--)
   {
   		if(i-att+1 >=0)
   		{
   			if (a[i] - a[i-att+1] < diff)
			{
				maxi=a[i];
				mini=a[i-att+1];
				diff = a[i] - a[i-att+1];
			}
		}
   }
    cout<<mini<<" "<<maxi+1<<endl;
}
