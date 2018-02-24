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

int main()
{
	int n;
	cin>>n;
	list<pair<int,int> > vertices;

	for(int i=0;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		vertices.push_back(make_pair(x,y));
	}
	cout<<((n-4)/2)<<endl;
}