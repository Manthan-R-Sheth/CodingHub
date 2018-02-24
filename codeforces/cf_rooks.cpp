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
	long long n,m;
	cin>>n>>m;
	long long row[n+1],col[n+1];
	memset(row,-1,sizeof(row));
	memset(col,-1,sizeof(col));
	long long r,c,currrow=n,currcol=n,cellsfree;
	vector<long long> v;
	
	cin>>r>>c;
	row[r]++;
	col[c]++;
	currrow--;
	currcol--;
	v.push_back(currcol*currrow);
	cellsfree=currcol*currrow;
	
	for(long long i=2;i<=m;i++)
	{
		cin>>r>>c;
		if(row[r]==-1 && col[c]==-1)
		{
			row[r]++;
			col[c]++;
			currrow--;
			currcol--;
			v.push_back(currcol*currrow);
			cellsfree=currcol*currrow;
		}
		else
		{
			if(row[r]==-1 && col[c]!=-1)
			{
				cellsfree-=currcol;
				currrow--;
				row[r]++;				
			}
			else
			{
				if(row[r]!=-1 && col[c]==-1)
				{	cellsfree-=currrow;
					currcol--;
					col[c]++;
				}
			}
			v.push_back(cellsfree);
		}
	}
	for(long long i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;	
}