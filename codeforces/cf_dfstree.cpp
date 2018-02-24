#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 200010
int a[N];
int mark[N]={0};
int d[N];
queue<int> q;
int main()
{
	int n,i;
	sd(n);
	for(i=1;i<=n;++i)
		sd(a[i]);
	d[1]=0;
	q.push(1);
	mark[1]=1;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		if(cur-1>=1 && !mark[cur-1])
		{
			d[cur-1]=1+d[cur];
			mark[cur-1]=1;
			q.push(cur-1);
		}
		if(!mark[a[cur]])
		{
			d[a[cur]]=1+d[cur];
			mark[a[cur]]=1;
			q.push(a[cur]);
		}
		if(cur+1<=n && !mark[cur+1])
		{
			d[cur+1]=1+d[cur];
			mark[cur+1]=1;
			q.push(cur+1);
		}
	}
	for(i=1;i<=n;++i)
		printf("%d ",d[i]);
}