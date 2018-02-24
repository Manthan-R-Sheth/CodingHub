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
	int m,n;
	cin>>n>>m;
	int arr[n+1][m+1];
	bool flag=true;
	vector<vector<int> > info;
	memset(arr,0,sizeof(arr));

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tmp;
			cin>>tmp;
			arr[i][j]=tmp;
		}
	}

	vector<int> partialinfo;
	for(int i=1;i<=n;i++)
	{
		partialinfo.clear();
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j]==j)
			{
				continue;
			}
			else
			{
				int pos;
				for(int k=1;k<=m;k++)
				{
					if(arr[i][k]==j)
					{
						pos=k;
						break;
					}
				}
				partialinfo.push_back(pos);
			}
		}
		if(partialinfo.size()>4)
		{
			flag=false;
			break;
		}
		info.push_back(partialinfo);
	}
	if(!flag)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	if(info.size()==1)
	{
		if(info[0].size()==0)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		int cnt=0;
		for(int i=0;i<info[0].size();i++)
		{
			if(info[0][i]!=i)
				cnt++;
		}
		if(cnt>4)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}

	int maxe=0,max=0;
	for(int mf=1;mf<info.size();mf++)
	{
		if(info[mf].size()>max)
		{
			max=info[mf].size();
			maxe=mf;
		}
	}

	int a[max+1],flagarr[max+1];
	for(int i=1;i<=max;i++)
	{
		a[i]=info[maxe][i];
	}
	
	for(int k=1;k<=max;k++)
	{
		bool flaga=1;
		for(int i=0;i<info.size();i++)
		{
			bool partialflaga=0;
			for(int j=0;j<info[i].size();j++)
			{
				if(info[i][j]==a[k])
				{
					partialflaga=1;
					break;
				}
			}
			if(!partialflaga)
			{
				flaga=0;
				break;
			}
		}
		flagarr[k]=flaga;
	}
	int sum=0;
	for(int i=1;i<=max;i++)
	{
		sum+=flagarr[i];
	}
	if(sum>=2 || max==2)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}