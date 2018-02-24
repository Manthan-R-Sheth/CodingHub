#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 100005
#define P 1 << 15
#define ll long long 
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define slld(t) scanf("%lld",&t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define eph 0.0000000001
#define slf(x) scanf("%0.12lf",&x)
#define plf(x) printf("%0.12lf\n",x)
using namespace std;
 
struct cmp
{
    bool operator()(pii a ,pii b){
        return a.second > b.second;
    }
};
 
ll modpow(ll base, ll exp, ll mod) 
{
  base %= mod;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
 
ll dist[MAX];
vector<pii> in;
vector<pii> ans;
 
void update(int &a, int &b)
{
	for(int i=ans.size()-1; i>=0; i--)
	{
		if((a<=ans[i].first && a>=ans[i].second) || (b<=ans[i].first && b>=ans[i].second)) {
			a=max(a,ans[i].first);
			b=min(b,ans[i].second);
			ans.pop_back();
		}
		else if((ans[i].first<=a && ans[i].first>=b) || (ans[i].second<=a && ans[i].second>=b)) {
			a=max(a,ans[i].first);
			b=min(b,ans[i].second);
			ans.pop_back();
		}
		else break;
	}	
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("C:/Users/HP/Desktop/codejam/1A_large_input.txt","r",stdin);//redirects standard input
	//freopen("C:/Users/HP/Desktop/codejam/1A_large_output.txt","w",stdout);//redirects standard output
	int n,m;
	ll d;
	sd(n);
	sd(m);
	slld(d);
	for(int i=1; i<=n; i++)
	{
		slld(dist[i]);
	}
	int a,b;
	for(int i=0; i<m; i++)
	{
		sd(a);
		sd(b);
		in.pb(mp(a,b));
	}
	sort(in.begin(),in.end());
	/*for(int i=0; i<in.size(); i++)
	{
		cout<<" "<<in[i].first<<" "<<in[i].second<<endl;
	}
	cout<<endl;*/
	in.pb(mp(-1,-1));
	
	for(int i=1; i<m; i++)
	{
		if((in[i].first<=in[i-1].first && in[i].first>=in[i-1].second) || (in[i].second<=in[i-1].first && in[i].second>=in[i-1].second))
		{
			in[i].first=max(in[i].first,in[i-1].first);
			in[i].second=min(in[i].second,in[i-1].second);
			update(in[i].first,in[i].second);
		}
		else if((in[i-1].first<=in[i].first && in[i-1].first>=in[i].second) || (in[i-1].second<=in[i].first && in[i-1].second>=in[i].second))
		{
			in[i].first=max(in[i].first,in[i-1].first);
			in[i].second=min(in[i].second,in[i-1].second);
			update(in[i].first,in[i].second);
		}
		else {
			ans.pb(mp(in[i-1].first,in[i-1].second));
		}
		if(i==m-1) {
			ans.pb(mp(in[i].first,in[i].second));
		}
	}
	
	for(int i=0; i<ans.size(); i++)
	{
		cout<<" "<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	
	ans.pb(mp(MOD,MOD));
	//cout<<" "<<ans.size()<<endl;
	bool flag=0;
	ll res=dist[n]+abs(dist[n]-d);
	//cout<<" "<<res<<" "<<ans[0].second<<endl;
	if(ans[0].second>=MOD || dist[ans[0].second]>d) {
		// res+=abs(dist[n]-d);
		// cout<<ans[0].second-1<<endl;
		// cout<<" enter "<<endl;
		;
	}
	else {
		for(int i=0; i<ans.size(); i++)
		{
			if(ans[i].second==MOD) break;
			if(dist[ans[i].first]>d) {
				cout<<ans[i-1].second<<endl;
				cout<<" heya"<<d<<" "<<ans[i].second<<endl;
				if(dist[ans[i].second]<=d) {
					cout<<" yo  "<<ans[i].second<<" "<<dist[ans[i].second]<<endl;
					res+=2*abs(d-dist[ans[i].second]);
				}
				break;
			}
			else {
				res+=2*(dist[ans[i].first]-dist[ans[i].second]);
			}
		}
	}
	
	cout<<res<<endl;
	
	return 0;
} 