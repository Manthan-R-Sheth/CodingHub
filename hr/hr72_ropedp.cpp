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

int main()
{
	int t,n,cost;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		cost=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		priority_queue<int, std::vector<int>, std::greater<int> > p(a,a+n);

		while(p.size()>1)
		{
			int a= p.top();
			p.pop();
			
			int b=p.top();
			p.pop();

			cost+=(a+b);
			p.push((a+b));
		}

		cout<<cost<<endl;
	}
}
