//*********************************************TURAN THEOREM IS USED*****************************

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() 
{
	int n,m,t;
	cin>>t;
	while(t--)
	{
		int k;
    	cin>>n>>m;
    	for(k=1;k<1000000;k++)
		{
			int e=floor(((k-1)*pow(n,2))/(2*k));
			if(m<=e)
				break;
		}
    	cout<<k<<endl;
    }

}
	