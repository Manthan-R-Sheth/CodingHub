#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 
int dp[20007][500];
int main()
{	
	string s;
	cin>>s;
	ll q;
	cin>>q;
	rep(j,0,q)
	{
		ll m,l;
		cin>>m>>l;
		ll res=0;
		memset(dp,0,sizeof(dp));
		rep(i,1,s.length()YUR4
			)
		{
			dp[i-1][0]+=1;
			rep(k,0,500)
			{
				if(dp[i-1][k])
				dp[i][(k*10+s[i]-'0')%m]+=dp[i-1][k];
			}
			res+=dp[i][l];
		}
		cout<<res<<endl;
	}
}