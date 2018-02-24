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
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v[1001000];
    memset(v,0,sizeof(v));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		v[t]++;
	}
	int ans=0;
	for(int i=0;i<1001000;i++)
	{
		v[i+1]+=v[i]/2;
		v[i]%=2;
		if(v[i])
			ans++;
	}
	cout<<ans<<endl;
}