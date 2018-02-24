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

string bfs(int n)
{
	if(n==1)
		return "1";
	string ans;
	queue<pair<string,long long> > q;
	q.push(make_pair("1",1));
	while(!q.empty())
	{
		string tmp=q.front().first;
		long long a=q.front().second;
		q.pop();
		long long rem=(a*10)%n;
		if(rem==0)
		{
			ans=tmp+"0";
			break;
		}
		else
		{
			q.push(make_pair(tmp+"0",rem));
		}

		rem=(a*10 + 1)%n;
		if(rem==0)
		{
			ans=tmp+"1";
			break;
		}
		else
		{
			q.push(make_pair(tmp+"1",rem));
		}
	}
	return ans;
}

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string ans=bfs(n);
		cout<<ans<<endl;
	}
}