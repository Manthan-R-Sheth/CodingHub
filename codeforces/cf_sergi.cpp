#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <complex>
#include <queue>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;
typedef double D;
typedef vector<int> VI;
typedef pair<D, D> pdd;
typedef pair<pdd, pii> ddii;
typedef pair<LL, int> pli;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sd(x) scanf("%d", &x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007

#define N 1123456

int cc[N] = {0};
int n, k;
LL ans = 0;
VI adj[N];

inline void dfs(int u, int p) {
    rep (i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
            cc[u] += cc[v];
        }
    }
    cout<<cc[u]<<endl;
    ans += min(cc[u], k + k - cc[u]);
    cout<<ans<<" "<<u<<endl;
}

int main() {
    cin >> n >> k;
    rep (i, 0, k + k) {
        int u;
        cin >> u;
        cc[u]++;
    }
    rep (i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}