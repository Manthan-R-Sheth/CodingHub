#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 

ll min(ll a,ll b)
{
	return (a<b?a:b);
}

int main()
{	
	string a;
	cin>>a;
	ll rot=0;
	char ch='a';
	rep(i,0,a.length())
	{
		if((122-ch)>(ch-97))
			rot+=min(abs(a[i]-ch),(abs(a[i]-122)+abs(ch-97))+1);
		else
			rot+=min(abs(a[i]-ch),(abs(a[i]-97)+abs(ch-122))+1);
		ch=a[i];
	}
	cout<<rot<<endl;
}