#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 

ll min(ll a,ll b) { return (a<b)?a:b;}

ll trailingzeros(ll num)
{
	ll fives=0,twos=0;
	ll tmp=num;
	while(tmp>=0)
	{
		if(tmp%5==0)
			fives++;
		else
			break;
		tmp/=5;
	}
	while(num>=0)
	{
		if(num%2==0)
			twos++;
		else
			break;
		num/=2;
	}
	return min(fives,twos);
}

ll getSum(double *st, ll ss, ll se, ll qs, ll qe, ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe)
        return 1;
 
    ll mid = ss+((se-ss)/2);
    ll a= getSum(st, ss, mid, qs, qe, 2*si+1);
    ll b= getSum(st, mid+1, se, qs, qe, 2*si+2);

    return a*b;
}

void updateRange2(ll si, ll ss, ll se, ll l, ll r, ll val,double* st)
{
    if (ss > se or ss > r or se < l)
        return;

    if (ss == se)
    {
        st[si]= ((ss-l+1)*val);
        return;
    }

    ll mid = ss+((se-ss)/2);
    updateRange2(si*2+1, ss, mid, l, r, val,st);
    updateRange2(si*2 + 2, mid + 1, se, l, r, val,st);

    st[si]= st[si*2+2]* st[si*2+1];
}

void updateRange(ll si, ll ss, ll se, ll l, ll r, ll val,double* st)
{
    if (ss > se or ss > r or se < l)
        return;

    if (ss == se)
    {
        st[si] =st[si]*(val);
        return;
    }

    ll mid = ss+((se-ss)/2);
    updateRange(si*2+1, ss, mid, l, r, val,st);
    updateRange(si*2 + 2, mid + 1, se, l, r, val,st);

    st[si]= st[si*2+2]* st[si*2+1];
}

double constructSTUtil(ll arr[], ll ss, ll se, double *st, ll si)
{
    if (ss == se)
    {
        st[si]=(arr[ss]);
        return st[si];
    }
    ll mid = ss+((se-ss)/2);
    st[si]=  constructSTUtil(arr, ss, mid, st, si*2+1) *constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

double* buildtree(ll arr[], ll n)
{
    ll max_size = 2*n - 1; 
    double*st = new double[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}


int main()
{	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll a[n];
		rep(i,0,n)
		{
			cin>>a[i];
		}
		double* st=buildtree(a,n);
		ll ans=0;
		rep(i,0,m)
		{
			ll type;
			ll l,r,x,y;
			cin>>type;
			if(type==1)
			{
				cin>>l>>r>>x;
				l--;
				r--;
				updateRange(0,0,n-1,l,r,x,st);
			}
			else if(type==2)
			{
				cin>>l>>r>>y;
				l--;
				r--;
				updateRange2(0,0,n-1,l,r,y,st);
			}
			else
			{
				cin>>l>>r;
				l--;
				r--;
				ll anstmp=getSum(st,0,n-1,l,r,0);
				ans+=trailingzeros(anstmp);
			}
		}
		cout<<ans<<endl;
	}
}