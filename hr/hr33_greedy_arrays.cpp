#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> b;

int main() 
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
    	bool flag=true;
    	a.clear();
    	b.clear();
    	cin>>n>>k;
    	for(int i=0;i<n;i++)
    	{
    		int tmp;
    		cin>>tmp;
    		a.push_back(tmp);
    	}
    	for(int i=0;i<n;i++)
    	{
    		int tmp;
    		cin>>tmp;
    		b.push_back(tmp);
    	}
    	sort(a.begin(),a.end());
    	sort(b.begin(),b.end());

    	for(int i=0;i<n;i++)
    	{
    		if(a[i]+b[n-1-i]<k)
    		{
    			flag=false;
    			break;
    		}
    	}
    	if(flag)
    	{
    		cout<<"YES"<<endl;
    	}
    	else
    	{
    		cout<<"NO"<<endl;
    	}
    }
}
