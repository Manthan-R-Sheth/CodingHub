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


int main()
{
	string s;
	int n,k;
	cin>>n>>k;
	std::vector<int> encrypt(n+k-1);
	std::vector<int> decrypt(n);
	cin>>s;
	for(int i=0;i<(n+k-1);i++)
	{
		int d=(int) s[i] -48;
		encrypt[i]=d;
	}
	decrypt[0]=encrypt[0];
	for(int i=1;i<decrypt.size();i++)
	{
		int tmp=decrypt[i-1];
		for(int j=2;j<k;j++)
		{
			if(i-j>=0)
			{
				tmp^=decrypt[i-j];
			}
			else
			{
				tmp^=0;	
			}
		}
		decrypt[i]=tmp^encrypt[i];
	}
	for(int i=0;i<decrypt.size();i++)
	{
		cout<<decrypt[i];
	}
	cout<<endl;

}