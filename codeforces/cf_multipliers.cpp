#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const ll MOD = (ll)1e9 + 7;

ll binPow(ll a, ll q, ll MOD) {
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, MOD)) % MOD;
}

int main() {
    int n;
    cin>>n;
    map<int,int> cnt;
    while (n--) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    ll d = 1;
    ll ans = 1;
    map<int,int>::iterator it;
    for (it=cnt.begin();it!=cnt.end();it++) {
        ll cn = (*it).se;
        ll p = (*it).fi;
        ll fp = binPow(p, (cn + 1) * cn / 2, MOD);
        ans = binPow(ans, (cn + 1), MOD) * binPow(fp, d, MOD) % MOD;
        d = d * (cn + 1) % (MOD - 1);
    }
    cout << ans << endl;
    return 0;
}