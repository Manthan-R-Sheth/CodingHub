#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define INF 1000000000
#define INFL 1000000000000000000LL
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ssl(x) scanf(" %[^\n]s",x)
#define gcd __gcd
#define MOD 1000000007LL
#define N 750001
 
ll dp[N];
bool inc[N];
 
ll power(ll a,ll e){
	ll ans=1LL;
	while(e){
		if(e&1){
			ans*=a;
			ans%=MOD;
		}
		a*=a;
		a%=MOD;
		e>>=1;
	}
	return ans;
}
 
int main(){
	int t;
	sd(t);
	while(t--)
	{
		for(int i=0;i<N;i++)
		{
			dp[i]=0;
			inc[i]=0;
		}
		int n;
		sd(n);
		while(n--){
			int x;
			sd(x);
			inc[x]=1;
		}
		ll ans=0;
		for(int i=N-1;i>0;i--) {
			if(inc[i]==1) {
				dp[i]=1;
				int j=2*i;
				while(j<N){
					dp[i]+=dp[j];
					if(dp[i]>=MOD)
						dp[i]-=MOD;
					j+=i;
				}
			}
			ans+=dp[i];
			if(ans>=MOD)
				ans-=MOD;
		}
		printf("%lld\n",ans);
	}
}