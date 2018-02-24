#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e5) + 5;
using namespace std;
int ans = 0,ans2 = 0,cur;
int col[N],vis[N];
vi nei[N];
void dfs(int x,int lev = 1)
{
    vis[x] = 1;
    int i;
    if(cur == -1)
    {
        cur = x;
        ans2 = lev;
    }
    else
    {
        if(lev > ans2)
        {
            ans2 = lev;
            cur = x;
        }
    }
    rep(i,sz(nei[x]))
    {
        if(vis[nei[x][i]] || (col[nei[x][i]]==0))
            continue;
        dfs(nei[x][i],lev+1);
    }
}
void dfs1(int x,int par = -1,int lev = 1)
{
    ans = max(ans,lev);
    int i;
    rep(i,sz(nei[x]))
    {
        if(nei[x][i] != par && col[nei[x][i]])
            dfs1(nei[x][i],x,lev+1);
    }
}
int main()
{
      int i,j,n,t;
      ios::sync_with_stdio(false);
    cin>>n;
    assert(1 <= n && n <= int(1e5));
    ans = 0;
    rep(i,n)cin>>col[i+1];
    rep(i,n-1)
    {
        int a = i+2,b;
        cin>>b;
        assert(1 <= b && b <= i+2);
        nei[a].pb(b);
        nei[b].pb(a);
    }
    rep(i,n)
    {
        if(col[i+1] == 0 || vis[i+1])continue;
        cur = -1;
        dfs(i+1);

        dfs1(cur);
    }
    cout<<ans<<endl;

}