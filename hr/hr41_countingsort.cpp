#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


int main() 
{
	int n;
	string s;
	cin>>n;
	int count[100],output[n],a[n];
	memset(count,0,sizeof(count));
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>s;
		count[a[i]]++;
	}
	for(int i=1;i<100;i++)
	{
		count[i]+=count[i-1];
	}
	// for(int i=0;i<n;i++)
	// {
	// 	output[count[a[i]]-1]=a[i];
	// 	--count[a[i]];
	// }
	for(int i=0;i<100;i++)
	{
		cout<<count[i]<<" ";
	}
	cout<<endl;
}
