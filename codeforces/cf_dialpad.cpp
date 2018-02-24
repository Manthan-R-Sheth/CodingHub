#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int X[] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
const int Y[] = {2, 1, 2, 3, 1, 2 ,3, 1 ,2, 3};
int map[5][5], n, x, y;
char ch[100];

int main() 
{
	cin >> n;
	if (n == 1) 
	{
		cout << "NO" << endl;
		return 0;
	}
	scanf("%s", ch);
	map[4][1] = map[4][3] = 1;
	int ans = 0;
	for (int i = 0; i < 10; ++i) 
	{
		x = X[i], y = Y[i];
		bool flag = true;
		for (int j = 1; j < n; ++j) 
		{
			x = x + X[ch[j] - '0'] - X[ch[j - 1] - '0'];
			y = y + Y[ch[j] - '0'] - Y[ch[j - 1] - '0'];
			if (x > 4 || x < 1 || y < 1 || y > 3 || map[x][y] == 1) 
			{
				flag = false;
				break;
			}
		}
		if (flag) 
		{
			cout<<ans<<endl;
			ans++;
		}
	}
	if (ans == 1) cout << "YES" << endl; else cout << "NO" << endl;
}