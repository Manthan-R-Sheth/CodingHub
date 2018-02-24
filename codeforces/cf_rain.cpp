#include<sstream>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
#include<string>
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

#define PI 3.14159265358979

int main()
{
	double d,h,v,e;
	cin>>d>>h>>v>>e;
	if(((4.0*v)/(PI*d*d)) > e)
	{
		cout<<"YES"<<endl;
		double t =0.0;
		double v1= (4.0*v)/(PI*d*d);
		t= h/(v1-e);
		cout.precision(13);
		cout<<t<<endl;
	}
		
	else
	{
		cout<<"NO"<<endl;
	}
	
}
