//*******************************GOOD CONCEPT****************************

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>

using namespace std;

int p[5*100010];
int pl[5*100010], pr[5*100010];
set<pair<int,int> > s;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> p[i];
        s.insert(make_pair(p[i], i));
        pr[i] = i+1;
        pl[i] = i-1;
    }
    pr[n-1] = -1;
    long long ans = 0;
    int pos, d, prev = 0;
    while(s.size() > 1)
    {
        pos = s.begin()->second;
        d = s.begin()->first;
        s.erase(s.begin());
        
        if(pl[pos] >= 0 && pr[pos] >= 0)
            ans += min(p[pl[pos]]-d, p[pr[pos]]-d);

        ans += (d-prev)*(s.size()-1);
        
        if(pr[pos]>=0)
            pl[pr[pos]] = pl[pos];
        if(pl[pos]>=0)
            pr[pl[pos]] = pr[pos];
        
        prev = d;
    }
    cout << ans << "\n";
    return 0;
}