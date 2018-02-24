#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 

// x^y mod m
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

bool isgood(string a)
{
	bool flag=true;
	rep(i,0,a.length()-2)
	{
		if(a[i]=='2'&&i!=a.length()-3)
		{
			if(a[i+1]=='2'&&a[i+2]=='1')
			{
				i+=2;
				continue;
			}
			else
			{
				flag=false;
				break;
			}
		}
		else
			if(i==a.length()-3&&a[i]=='2')
				flag=false;
	}
	if(flag)
		return true;
	else
		return false;
}

int main()
{	
	ll t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		bool flag=true;
		ll tcount=0,common1=0,diff=0,common2=0,countbet=0;
		ll len=a.length();
		ll agood[len],bgood[len];
		memset(agood,0,sizeof(agood));
		memset(bgood,0,sizeof(bgood));
		rep(i,0,len-2)
		{
			if(a[i]=='2')
			{
				if(a[i+1]=='1')
				{
					agood[i+1]=2;
				}
				if(a[i+2]=='2')
					agood[i+2]=1;
				i+=2;
			}
		}
		rep(i,0,len-2)
		{
			if(b[i]=='2')
			{
				if(b[i+1]=='1')
					bgood[i+1]=2;
				if(b[i+2]=='2')
					bgood[i+2]=1;
				i+=2;
			}
		}
		rep(i,0,len)
		{
			if(agood[i]==1&&bgood[i]==2)
				diff++;
			if(agood[i]==2&&bgood[i]==1)
				diff++;
			if(i<len-2)
				if((agood[i]==1&&bgood[i]==0 && bgood[i+2]==2 && agood[i+2]==0)||
					(agood[i]==2&&bgood[i]==0&&bgood[i+2]==1&&agood[i+2]==0))
				{
					countbet++;
					diff++;
					i+=2;
					continue;
				}
			if((agood[i]==1&&bgood[i]==0)||(agood[i]==0&&bgood[i]==1))
			{
				flag=false;
				break;
			}
			if((agood[i]==2&&bgood[i]==0)||(agood[i]==0&&bgood[i]==2))
			{
				flag=false;
				break;
			}
			if((agood[i]==1&&bgood[i]==1)||(agood[i]==2&&bgood[i]==2))
			{
				flag=false;
				break;
			}

		}
		if(a[len-2]=='2'||b[len-2]=='2')
			flag=false;
		if(!flag)
			cout<<0<<endl;
		else
		{
			rep(i,0,len-2)
			{
				if(a[i]=='2'&&b[i]=='1'&&b[i+1]=='1'&&b[i+2]=='1')
				{
					if(i!=0)
					{
						if(b[i-1]!='2')
						{
							common2++;
							i++;
						}
					}
				}
				if(b[i]=='2'&&a[i]=='1'&&a[i+1]=='1'&&a[i+2]=='1')
				{
					if(i!=0)
					{
						if(a[i-1]!='2')
						{
							common2++;
							i++;
						}
					}
				}
			}
			common2-=countbet;
			rep(i,0,len)
			{
				if(a[i]==b[i])
					common1++;
			}
			tcount+=power(2,(common1+common2),(pow(10,9)+7));
			cout<<common1<<" "<<common2<<endl;
			cout<<tcount<<endl;
		}

	}
}	