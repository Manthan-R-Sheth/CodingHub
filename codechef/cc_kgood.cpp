#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		string s;
		int hash[30];
		cin>>s>>n;
		int x=s.length();
		for(int i=0;i<26;i++)
		{
			hash[i]=0;
		}
		for(int i=0;i<x;i++)
		{
			hash[s[i]-97]++;
		}
		sort(hash,hash+26);
		int i=0,k=0,ans,res=INT_MAX;
		int arr[x];
		for(int i=0;i<x;i++)
		{
			arr[i]=0;
		}
		while(i<26)
		{
			if(hash[i]==0)
				i++;
			else
				arr[k++]=hash[i++];
		}
		if(k==1)
			res=0;
		else
		{
			ans=0;
			int check = arr[0]+n;
			for(int i=0;i<k;i++)
			{
				if(arr[i]>check)
				{
					ans+=(arr[i]-check);
				}
			}
			if(ans<res)
		     res=ans;
		    int temp=0;
			for(int j=0;j<k;j++)
			{
				int check = arr[j+1]+n;
				ans=temp+arr[j];
				temp=ans;
				for(int i=j+1;i<k;i++)
				{
					if(arr[i]>check)
					{
						ans+=(arr[i]-check);
					}
				}
				if(ans<res)
				res=ans;
			}
    	}
    	cout<<res<<endl;	
	}
}