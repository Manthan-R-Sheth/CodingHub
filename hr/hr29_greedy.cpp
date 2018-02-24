#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		bool ans=true;
		cin>>n;
		char a[n][n];
		memset(a,' ',sizeof(a));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}

		for(int i=0;i<n;i++)
		{
			sort(a[i],a[i]+n);
		}

		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=i+1;k<n;k++)
				{
					if(a[i][j]>a[k][j])
					{
						ans=false;
						break;
					}
				}
			}
		}

		if(ans)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}