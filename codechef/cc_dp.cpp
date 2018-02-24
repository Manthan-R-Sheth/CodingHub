

//**********************************************************DP BY MEMOISATION********************************


#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int getMinSteps(int n)
{
	int memo[n+1];
	memset(memo,-1,sizeof(memo));
	if(n==1)
	{
		return 0;
	}
	if(memo[n]!=-1)
	{
		return memo[n];
	}

	int r=1+getMinSteps(n-1);
	if(n%2==0)
	{
		r=min(r,1+getMinSteps(n/2));
	}
	if(n%3==0)
	{
		r=min(r,1+getMinSteps(n/3));
	}
	memo[n]=r;
	return r;

}

int main()
{
	int q,n,minSteps;
	cin>>q;
	while(q--)
	{
		cin>>n;
		minSteps=getMinSteps(n);
		cout<<minSteps<<endl;
	}
}