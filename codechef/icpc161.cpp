#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long int dp[800000];
 
int main()
{
	int t;
	cin >> t;
     while(t--)
     {
     	int n;
     	cin >> n;
     	vector<long long int> vec;
     	int x;
     	for(int i=0;i<n;i++)
     	{
     		cin >> x;
     		vec.push_back(x);
		 }
     	
     	for(int i=0;i<800000;i++)
     		dp[i]=0;
     	sort(vec.begin(),vec.end());
     	for(int i=n-1;i>=0;i--)
     	{
     		if(vec[i]!=1)
     		{
			 
     		dp[vec[i]]++;
     		for(int j=vec[i]+vec[i];j<=vec[n-1];j=j+vec[i])
     		{
     			dp[vec[i]] = (dp[vec[i]]%mod + dp[j]%mod)%mod;
			 }
		 }
		 }	
		 if(vec[0]==1)
		 {
		 	dp[vec[0]]++;
		 	for(int i=1;i<n;i++)
		 	{
		 		
		 		dp[vec[0]]=(dp[vec[0]]%mod+dp[vec[i]]%mod)%mod;
			 }
		 }
		 long long int ans=0;
		 for(int i=0;i<n;i++)
		 {
		 	ans = (ans%mod + dp[vec[i]]%mod)%mod;
		 }
		 cout << ans << endl;
     	
	 }
	return 0;
} 