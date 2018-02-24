#include<bits/stdc++.h>
 
#define MOD 1000000007
#define MAX 100005
#define P 1 << 15
#define ll long long 
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for( typeof(container.begin()) it =container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define inf 1000000
using namespace std;
ll mod = 1000000007;
int n , k,u,v,visited[100];
ll fac[55];
vector< int > adj[55];
 void call()
 {
 	fac[0]=1;
 	for(int i=1;i<=51;i++)
 	   fac[i]=(fac[i-1]*i)%mod;
 }
 ll power(ll a , ll b)
 {
 	if(b==0)return 1;
 	if(b==1)return a%mod;
 	 ll temp = power(a,b/2);
 	  temp= (temp*temp)%mod;
 	if(b%2)
 	  temp=(temp*a)%mod;
 	
	 return temp;  
 }
 void reg(int  n )
 {
 	for(int i=0;i<=n;i++)
 	  adj[i].clear();
 }
 ll dp[55][55];
 
 
 void dfs(int n )
 {
 	
 	ll temp[k+1],flag=0;
 	for(int i=0;i<=k;i++)temp[i]=0;
 	tr(adj[n],it)
 	{	int p=*it;
 		if(visited[p]==0)
 		{
 		flag=1;
 		visited[p]=1;
 		dfs(p);
 		
 		for(int i=0;i<=k;i++)
 		{
 			for(int j=0;(i+j)<=k;j++)
 			   temp[i+j]=(temp[i+j]+dp[p][i]*dp[n][j])%mod;
		 }
		 for(int i=0;i<=k;i++)
		  {
		  	dp[n][i]=temp[i];
		  	temp[i]=0;
		  }
	   }
	 }
	  
	  if(flag==0)
	    dp[n][0]=1,dp[n][1]=1;
	    else
	     {
	     	for(int i=k;i>0;i--)
	     	{
	     		dp[n][i]=(dp[n][i]+dp[n][i-1])%mod;
			 }
		 }
		 
 }
void dfs2(int n)
 {

    visited[n]=1;
    ll temp[k+1],flag=0;
 	for(int i=0;i<=k;i++)temp[i]=0;
 	tr(adj[n],it)
 	{	int p=*it;
 		if(visited[p]==0)
 		{
 		flag=1;
 		visited[p]=1;
 		dfs(p);
 		for(int i=0;i<=k;i++)
 		{
 			for(int j=0;(i+j)<=k;j++)
 			   temp[i+j]=(temp[i+j]+dp[p][i]*dp[n][j])%mod;
		 }
		 for(int i=0;i<=k;i++)
		  {
		  	dp[n][i]=temp[i];
		  	temp[i]=0;
		  }
	   }
	 }
	  if(flag==0)
	    dp[n][0]=1,dp[n][1]=1;
 }
 ll npr(ll n , ll r)
 {
 	return  (fac[n]*power(fac[n-r],mod-2))%mod;
 }
 
int main()
{
	ios::sync_with_stdio(false);
	call();
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>k;
		for(int i=0;i<n-1;i++)
		{
		   cin>>u>>v;
		   adj[u].pb(v);
		   adj[v].pb(u);	
		}
		for(int i=0;i<=n;i++)
		{
			visited[i]=0;
			for(int j=0;j<=k;j++)
			  dp[i][j]=0;
	   }
		for(int i=0;i<=n;i++)dp[i][0]=1;
		dfs2(1);
		ll ans =0;
		for(int i=0;i<min(n,k);i++)
		{
			ans = (ans+  dp[1][i]*npr(k,i+1) % mod)%mod;
		}
		//ans= (ans+k)%mod;
		cout<<ans<<endl;
	}
}