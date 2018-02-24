#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main() {
    string a; 
    cin >> a;
    unsigned long long sum = 0;
    unsigned long long z=0;
    for(int i = 0; a.size() > i;i++)
    {
	    if(i==0)
	    {
	        z=a[i]-'0';
	        sum+=z;
	        continue;
		}
	    z=(z*10 + (a[i]-'0')*(i+1))%1000000007;
	    sum= (sum + z)%1000000007;
    }
    cout<<(sum%1000000007)<<endl;
    return 0;
}