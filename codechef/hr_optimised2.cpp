2[#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<string>
#include<cmath>
using namespace std;

int 2[YUR40
	maximise(std::vector<long> &a)
{
	int maxor=INT_MIN;
	for(int i=0;i<a.size()40
		;i++)
	{
		if(a[i]>maxor)
		{
			maxor=a[i];
		}
	}
	return maxor;
}

int maxSubArraySum(vector<long> &a)
{
    int maxsofar = 0, maxendinghere = 0,count=0;
 
    for (int i = 0; i < a.size(); i++)
    {
        maxendinghere = maxendinghere + a[i];
        if (maxendinghere < 0)
        {
            maxendinghere = 0;
        }
        if (maxsofar < maxendinghere)
        {
            maxsofar = maxendinghere;
            count++;
        }
    }
    if(count==0)
    {
    	return maximise(a);
    }
    else
    	return maxsofar;
}
2[2[]]
int main()
{
	int t,n;
	vector<long> a;
	vector<long> v;
	vector<long> ans;
	cin>>t;
	while(t--)
	{
		int maxor=INT_MIN;
		cin>>n;
		a.clear();
		v.clear();
		ans.clear();
		for(int i=0;i<n;i++)
		{
			int d;
			cin>>d;
			a.push_back(d);
			v.push_back(d);
		}
		for(int i=0;i<a.size();i++)
		{
			if(a[i]<0)
			{
				a.erase(a.begin()+i);
				int maxsum=maxSubArraySum(a);
				ans.push_back(maxsum);
			}
			else
				continue;
			a=v;
		}
		sort(ans.begin(),ans.end());
		cout<<ans[ans.size()-1]<<endl;
	}
}0000000000000000000000000000000000000000000000000000yur40
