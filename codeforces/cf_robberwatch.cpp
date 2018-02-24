#include<map>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long n,m,len1,len2,ans=0;
	cin>>n>>m;
	len1=floor(log(n)/log(7))+1;
	len2=floor(log(m)/log(7))+1;

	if (len1 + len2 <= 7)
        for (long long i = 0; i != n; ++i)
            for (long long j = 0; j != m; ++j) 
            {
                vector<long long> used(7, 0);
                
                for (long long a = i, k = 0; k != len1; a /= 7, ++k)
                    used[a % 7] += 1;
                for (long long b = j, k = 0; k != len2; b /= 7, ++k)
                    used[b % 7] += 1;
                
                if (*std::max_element(used.begin(), used.end()) <= 1)
                    ++ans;
            }
    
    cout << ans << "\n";
}