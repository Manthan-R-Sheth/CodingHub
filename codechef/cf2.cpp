#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 

int main()
{	
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n)
	{
		cin>>a[i];
	}
	ll carry=0;
	rep(i,0,n)
	{
		if(a[i]==0 && carry>0)
		{
			break;
		}
		if(a[i]%2==1)
		{
			carry++;
			if(carry%2==0)
				carry=0;
		}
	}	
	if(carry==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
}