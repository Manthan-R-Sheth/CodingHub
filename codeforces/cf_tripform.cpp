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
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	double n,l,v1,v2,k;
	cin>>n>>l>>v1>>v2>>k; 
    int p = ceil(n/k);
    p= int(p);
    double a = 1+ 2*v1*(p-1)/(v1+v2);
    cout<<a<<endl;
    double x=l/a;
    double ans= x/v2+(l-x)/v1;
    
    cout<<setprecision(12)<<ans<<endl;
}