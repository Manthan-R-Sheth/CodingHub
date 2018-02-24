#include<map>
#include<set>
#include<list>
#include<cmath>
#include<string>
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

int main()
{
	string s;
	cin>>s;
	int len=s.length();
	int row=floor(sqrt(len));
	int col=ceil(sqrt(len));
	while(row*col < len)
	{
		row++;
	}
	while(s.length()!=(row*col))
	{
		s.append("$");
	}
	char m[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			m[i][j]=s[col*i+j];
		}
	}

	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			if(m[j][i]!='$')
			{
				cout<<m[j][i];
			}
		}
		if(i!=(col-1))
		{
			cout<<" ";
		}
	}
	cout<<endl;
}