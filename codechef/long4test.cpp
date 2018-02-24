#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++) 
#define INF 1e18
tnode st[400000];
lazynode lazy[400000];

struct lazynode
{
	ll x2=0,x5=0,y2=0,y5=0,yl=INF;
};

struct tnode
{
	ll fives,twos,trailz;
};

ll min(ll a,ll b) { return (a<b)?a:b;}

ll getfives(ll num)
{
	ll fives=0;
	while(num>=0)
	{
		if(num%5==0)
			fives++;
		else
			break;
		num/=5;
	}
	return fives;
}

ll gettwos(ll num)
{
	ll twos=0;
	while(num>=0)
	{
		if(num%2==0)
			twos++;
		else
			break;
		num/=2;
	}
	return twos;
}

ll getTrailingZeroFromfact(ll num)
{
	ll ans=0,i=1;
	while(true)
	{
		ans+=(num/pow(5,i));
		i++;
		if((num/pow(5,i))==0)
			break;
	}
	return ans;
}

ll getSum(tnode st[], ll ss, ll se, ll qs, ll qe, ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe)
        return 1;
 
    ll mid = ss+((se-ss)/2);
    ll a= getSum(st, ss, mid, qs, qe, 2*si+1);
    ll b= getSum(st, mid+1, se, qs, qe, 2*si+2);

    return min(a,b);
}

void updateRange2(ll si, ll ss, ll se, ll l, ll r, ll val,tnode st[])
{
	if(lazy[si].yl!=INF)
	{
		st[si].fives=(se-ss+1)*lazy[si].y5;
		st[si].two=(se-ss+1)*lazy[si].y2;
		st[si].trailz=min(st[si].fives,st[si].twos)+getTrailingZeroFromfact(se-lazy[si].yl+1)
						-getTrailingZeroFromfact(ss-lazy[si].yl+1);
		if (ss != se)
        {
            lazy[si*2 + 1].y5   = lazy[si].y5;
            lazy[si*2 + 2].y5  = lazy[si].y5;
            lazy[si*2 + 1].y2   = lazy[si].y2;
            lazy[si*2 + 2].y2  = lazy[si].y2;
            lazy[si*2 + 1].yl   = lazy[si].yl;
            lazy[si*2 + 2].yl  = lazy[si].yl;
            lazy[si*2 + 1].x5   = 0;
            lazy[si*2 + 2].x5  = 0;
            lazy[si*2 + 1].x2   = 0;
            lazy[si*2 + 2].x2  = 0;
        }
        lazy[si].y2 = 0;
        lazy[si].y5 = 0;
        lazy[si].yl=INF;
        lazy[si].x2 = 0;
    	lazy[si].x5 = 0;
	}
    if (ss > se or ss > r or se < l)
        return;

    if (ss>=l && se<=r)
    {
    	ll f=getfives(val);
    	ll t=gettwos(val);
        st[si].fives=(se-ss+1)*f;
		st[si].two=(se-ss+1)*t;
		st[si].trailz=min(st[si].fives,st[si].twos)+getTrailingZeroFromfact(se-l+1)
						-getTrailingZeroFromfact(ss-l+1);
		
        if (ss != se)
        {
            lazy[si*2 + 1].y5   = f;
            lazy[si*2 + 2].y5  = f;
            lazy[si*2 + 1].y2   = t;
            lazy[si*2 + 2].y2  = t;
            lazy[si*2 + 1].yl   = l;
            lazy[si*2 + 2].yl  = l;
            lazy[si*2 + 1].x5   = 0;
            lazy[si*2 + 2].x5  = 0;
            lazy[si*2 + 1].x2   = 0;
            lazy[si*2 + 2].x2  = 0;
        }
        return;
    }
 

    ll mid = ss+((se-ss)/2);
    updateRange2(si*2+1, ss, mid, l, r, val,st);
    updateRange2(si*2 + 2, mid + 1, se, l, r, val,st);

    st[si]= st[si*2+2]* st[si*2+1];
}

void updateRange(ll si, ll ss, ll se, ll l, ll r, ll val,tnode st[])
{

	if(((lazy[si].x2 !=0) || (lazy[si].x5 !=0)))
	{
		st[si].fives+=(se-ss+1)*lazy[si].x5;
		st[si].two+=(se-ss+1)*lazy[si].x2;
		st[si].trailz=min(st[si].fives,st[si].twos);
		if (ss != se)
        {
            lazy[si*2 + 1].x5   += lazy[si].x5;
            lazy[si*2 + 2].x5  += lazy[si].x5;
            lazy[si*2 + 1].x2   += lazy[si].x2;
            lazy[si*2 + 2].x2  += lazy[si].x2;
        }
        lazy[si].x2 = 0;
        lazy[si].x5 = 0;
	}
    if (ss > se or ss > r or se < l)
        return;

    if (ss>=l && se<=r)
    {
    	ll f=getfives(val);
    	ll t=gettwos(val);
        st[si].fives+=(se-ss+1)*f;
		st[si].two+=(se-ss+1)*t;
		st[si].trailz=min(st[si].fives,st[si].twos);
 
        if (ss != se)
        {
            lazy[si*2 + 1].x2  += t;
            lazy[si*2 + 2].x2  += t;
            lazy[si*2 + 1].x5   += f;
            lazy[si*2 + 2].x5  += f;
        }
        return;
    }

    ll mid = ss+((se-ss)/2);
    updateRange(si*2+1, ss, mid, l, r, val,st);
    updateRange(si*2 + 2, mid + 1, se, l, r, val,st);

    st[si].fives= st[si*2+2].fives + st[si*2+1].fives;
    st[si].twos= st[si*2+2].twos + st[si*2+1].twos;
    st[si].trailz=min(st[si].fives,st[si].twos);
}

tnode constructST(ll arr[], ll ss, ll se, tnode st[], ll si)
{
    if (ss == se)
    {
        st[si].fives=getfives(arr[ss]);
        st[si].twos=gettwos(arr[ss]);
        st[si].trailz=min(st[si].fives,st[si].twos);
        return st[si];
    }
    ll mid = ss+((se-ss)/2);
    st[si].fives=constructST(arr, ss, mid, st, si*2+1).fives + 
    				constructST(arr, mid+1, se, st, si*2+2).fives;
    st[si].twos=constructST(arr, ss, mid, st, si*2+1).twos + 
    				constructST(arr, mid+1, se, st, si*2+2).twos;
    st[si].trailz= min(st[si].fives,st[si].twos);
    return st[si];
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
		constructST(arr, 0, n-1, st, 0);
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