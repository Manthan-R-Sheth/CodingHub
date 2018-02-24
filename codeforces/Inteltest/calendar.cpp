#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
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

string days[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{	
	string first,second;
	cin>>first;
	cin>>second;
	int firstin,secondin;
	for(int i=0;i<7;i++)
	{
		if(first.compare(days[i])==0)
			firstin=i;
		if(second.compare(days[i])==0)
			secondin=i;
	}
	if(((firstin+2)%7==secondin) || ((firstin+3)%7==secondin) || (firstin)%7==secondin)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}