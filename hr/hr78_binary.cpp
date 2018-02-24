//**************** 4k ^ 4k+1 ^ 4k+2 ^ 4k+3 =0 ************************

#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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

void binary(int num)
{
	int i=0,r;
	int arr[64];
	if(num==0)
	{
		cout<<"0";
		return;
	}

    while(num!=0)
	{
	  r = num%2;
	  arr[i++] = r;
	  num /= 2;
	}

	for(int j=i-1;j>=0;j--)
	 	cout<<arr[j];
}


int main()
{
	int res=0;
	for(int i=1;i<=127;i++)
	{
		res^=i;
		cout<<i<<"     ";
		binary(res);
		cout<<endl;
	}	
}
