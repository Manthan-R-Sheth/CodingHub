#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<utility> 
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	map<int, int> scilang;
	map<int, int>::iterator it;
	for(int i=0;i<n;i++)
	{
		int lang;
		cin>>lang;
		it=scilang.find(lang);

		if(it==scilang.end())
		{
			scilang.insert(make_pair(lang,1));
		}
		else
		{
			scilang[lang]++;
		}
	}
	cin>>m;
	int audio[m+1],subt[m+1];
	audio[0]=subt[0]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>audio[i];
	}

	for(int i=1;i<=m;i++)
	{
		cin>>subt[i];
	}

	pair<int,int> res;
	res=make_pair(0,0);
	
	int resmovie=0;
	for(int i=1;i<=m;i++)
	{
		if(res<=make_pair(scilang[audio[i]],scilang[subt[i]]))
		{
			res=make_pair(scilang[audio[i]],scilang[subt[i]]);
			resmovie=i;
		}
	}
	cout<<resmovie<<endl;

}	