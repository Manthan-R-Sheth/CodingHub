//*************** SMART THINKING*******************************

#include <bits/stdc++.h>
using namespace std;

map<int, int> mp1, mp2;
map<pair<int, int>, int> v;

int main() {
	///freopen("c.in", "r", stdin);
	int n, x, y;
	scanf("%d", &n);
	long long ans = 0;
	for(int i =1 ; i <= n; i ++) {
		scanf("%d %d", &x, &y);
		ans += mp1[x] ++;
		ans += mp2[y] ++;
		ans -= (v[make_pair(x, y)] ++);
	}
	printf("%I64d\n", ans);
}