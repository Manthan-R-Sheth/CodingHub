#include<map>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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

vector<long long> gifts;

void knapsack(set<long long> &has,long long n,long long m)
{
	set<long long>::iterator it;
	long long number=0;
	for(int i=1;i<200000;i++)
	{
		if(i>m)
		{
			break;
		}
		it=has.find(i);
		if(it==has.end())
		{
			number++;
			m=m-i;
			gifts.push_back(i);
		}
	}

	cout<<number<<endl;
	for(int i=0;i<gifts.size();i++)
	{
		cout<<gifts[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	long long n,m,hastoy;
	cin>>n>>m;
	set<long long> has;

	for(int i=0;i<n;i++)
	{
		cin>>hastoy;
		has.insert(hastoy);
	}

	knapsack(has,n,m);
}