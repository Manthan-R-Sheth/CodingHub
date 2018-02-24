#include<bits/stdc++.h>
#define oo INT_MAX

using namespace std;
int memo[100005][4];
int n;

int DP(int index, int prev, vector <vector<int> > &cost) 
{
	if (index >= n) 
	{
		return 0;
	}

	if (memo[index][prev] != -1)
	{ 
		return memo[index][prev];
	}

	int ans = oo;
	for (int i = 1; i <= 3; i++)
	{
		if (i != prev)
		ans = min(ans, DP(index + 1, i, cost) + cost[index][i]);
	}
	return memo[index][prev] = ans;
}

int main() 
{
	int t;
	cin >> t;
	while (t--) 
	{
		cin >> n;
		vector <vector<int> > cost(n, vector<int>(4, oo));
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < 3; j++)
			cin >> cost[i][j + 1];
		}
		cout << DP(0, 0, cost) << endl;
	}
	return 0;
}