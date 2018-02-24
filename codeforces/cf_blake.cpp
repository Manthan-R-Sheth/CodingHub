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
	unsigned long long aor=0,bor=0,res;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		aor|=tmp;
	}
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		bor|=tmp;
	}
	res=(aor+bor);
	cout<<res<<endl;
}