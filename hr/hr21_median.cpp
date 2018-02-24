//**********************************************************Working but not optimised**************************

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

vector<double> median;

int main() 
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double d,median1,median2;
		cin>>d;
		median.push_back(d);
		sort(median.begin(),median.end());

		if(median.size()%2!=0)
		{
			cout<<median[(median.size())/2]<<endl;
		}	

		else	
		{
			median1= median.size()/2;
			median2= (median.size()/2)-1;
			cout<<(median[median1]+median[median2])/2.0<<endl;
		}    
	}	
}
