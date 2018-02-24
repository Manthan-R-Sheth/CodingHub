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

int main()
{	
	int n,k;
	cin>>n>>k;
	if(n&(1<<(k-1)))
	{
		n&=~(1<<(k-1));
		cout<<n<<endl;
	}
	else
	{
		cout<<n<<endl;
	}
}