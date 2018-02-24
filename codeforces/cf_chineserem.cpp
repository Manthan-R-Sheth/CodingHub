#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second

using namespace std;

ll gcd(ll n1,ll n2){
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
int arr[upperlimit+1];
int fac[upperlimit+1];
int v1[upperlimit+1];
int v2[upperlimit+1];
void compute(int num){
	while(num!=1){
		int temp=fac[num];
		int temp2=0;
		while(num%temp==0){
			num/=temp;
			temp2++;
		}
		v2[temp]=max(v2[temp],temp2);
	}
}
int main()
{
	int n,i,j,k;
	bool f=true;
	sd(n);
	sd(k);
	for(i=1;i<=upperlimit;i++)fac[i]=i;
	for(i=2;i*i<=upperlimit;i++)if(fac[i]==i)for(j=i*i;j<=upperlimit;j+=i)fac[j]=i;
	while(k!=1){
		int temp=fac[k];
		int temp2=0;
		while(k%temp==0){
			k/=temp;
			temp2++;
		}
		v1[temp]=max(v1[temp],temp2);
	}
	for(i=1;i<=n;i++){
		sd(arr[i]);
		compute(arr[i]);
	}
	for(i=1;i<=upperlimit;i++)if(v1[i]>v2[i])f=false;
	if(f)cout<<"Yes";
	else cout<<"No";
	return 0;
}