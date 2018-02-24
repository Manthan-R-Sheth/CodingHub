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
	int tmp=0;
	for(int i=1,m=1;i<decrypt.size();i++,m++)
	{
		if(m<k)
		{
			tmp^=decrypt[i-1];
		}
		else
		{
			tmp^=decrypt[i-k];
			tmp^=decrypt[i-1];
		}
		decrypt[i]=tmp^encrypt[i];
	}
	for(int i=0;i<decrypt.size();i++)
	{
		cout<<decrypt[i];
	}
	cout<<endl;

}