//**************************************LINEARITY OF EXPECTATION IS USED************************************

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
double p;
double getdbyprime(double a)
{
	return floor(a/p);
}

double getdbyprimesinrange(double l,double r)
{
	return (getdbyprime(r)-getdbyprime(l-1));
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	double n;
	double probab,probabsum=0.0,expec;
	cin>>n>>p;
	vector<pair<double,double> >pairs;
	for(int i=0;i<n;i++)
	{
		double li,ri;
		cin>>li>>ri;
		pairs.push_back(make_pair(li,ri));
	}
	for(int i=0;i<n-1;i++)
	{
		probab=(1.0-(((pairs[i].second-pairs[i].first+1- getdbyprimesinrange(pairs[i].first,pairs[i].second))/(pairs[i].second-pairs[i].first+1))*((pairs[i+1].second-pairs[i+1].first+1- getdbyprimesinrange(pairs[i+1].first,pairs[i+1].second))/(pairs[i+1].second-pairs[i+1].first+1))));
		probabsum+=probab;
	}
	probab=(1.0-(((pairs[n-1].second-pairs[n-1].first+1- getdbyprimesinrange(pairs[n-1].first,pairs[n-1].second))/(pairs[n-1].second-pairs[n-1].first+1))*((pairs[0].second-pairs[0].first+1- getdbyprimesinrange(pairs[0].first,pairs[0].second))/(pairs[0].second-pairs[0].first+1))));
	probabsum+=probab;
	expec=2000*probabsum;
	cout.precision(13);
	cout<<expec<<endl;
}