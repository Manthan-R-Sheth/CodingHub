#include<bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

#define N 200010

int n,m;
int ar[N];
VI vec[N];

int depth[N],ans;

int dfs(int a,int p)
{
    depth[a] = depth[p]+1;
    int len = vec[a].size(),cnt=0;
    if(ar[a] == 1)cnt++;
    for(int i=0;i<len;i++)
    {
        if(vec[a][i]!=p)
        {
            cnt += dfs(vec[a][i],a);
        }
    }
    if(cnt < m && cnt > 0)
    {//cout<<a<<" "<<p<<" "<<ans<<endl;
        ans++;
    }
    return cnt;
}

void solve()
{
    int a,b;
    sd(n);sd(m);
    for(int i=1;i<n;i++)
    {
        sd(a);sd(b);
        vec[a].PB(b);
        vec[b].PB(a);
    }
    for(int i=0;i<m;i++)
    {
        sd(a);
        ar[a] = 1;
    }
    dfs(1,0);
    int mxd = 0,idx;
    for(int i=1;i<=n;i++)
    {
        if(ar[i] == 1)
        {
            if(depth[i] > mxd)
            {
                mxd = depth[i];
                idx = i;
            }
        }
    }
    //cout<<idx<<endl;
    dfs(idx,0);
    mxd = 0;
    int idx1;
    for(int i=1;i<=n;i++)
    {
        if(ar[i] == 1)
        {
            if(depth[i] > mxd)
            {
                mxd = depth[i];
                idx1 = i;
            }
        }
    }
    cout<<mxd<<endl;
    cout<<min(idx,idx1)<<endl<<ans-mxd + 1<<endl;


}

int main()
{
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
}