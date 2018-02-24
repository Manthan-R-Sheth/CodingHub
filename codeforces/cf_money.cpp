//****************************************PREFIX ARRAY SUM***************************************
//**************************************IT IS ANALOGOUS TO INTEGRATION*******************************

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    map<long long, int> d;
    long long sum = 0;
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
        d[sum]++;
        ans = min(ans, n - d[sum]);
    }
    for(map<long long, int>:: iterator it=d.begin();it!=d.end();it++)
    {
        cout<<it->first<<"  "<<it->second<<endl;
    }

    cout << ans << endl;
}