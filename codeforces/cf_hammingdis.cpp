#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int cnt[2][m + 1];
    cnt[0][0] = 0;
    cnt[1][0] = 0;
    for (int i = 0; i < m; i++)
    {
        cnt[0][i + 1] = cnt[0][i];
        cnt[1][i + 1] = cnt[1][i];
        if (b[i] == '0')
            cnt[0][i + 1]++;
        else
            cnt[1][i + 1]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
            ans += (ll)(cnt[1][m - (n - i) + 1] - cnt[1][i]);
        else
            ans += (ll)(cnt[0][m - (n - i) + 1] - cnt[0][i]);
    }
    cout << ans << endl;
    return 0;
}