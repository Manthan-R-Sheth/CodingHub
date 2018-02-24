#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	int grundy[3000];
	vector<int> values;
	grundy[0]=0;
	for(int i=1;i<3000;i++)
	{
		values.clear();
		values.push_back(grundy[i/2]);
		values.push_back(grundy[i/3]);
		values.push_back(grundy[i/4]);
		values.push_back(grundy[i/5]);
		values.push_back(grundy[i/6]);
		int s=0;
		while(true)
		{
			vector<int>::iterator it=find(values.begin(),values.end(),s);
			if(it==values.end())
			{
				grundy[i]=s;
				break;
			}
			s++;
		}
		cout<<i<<"    "<<grundy[i]<<endl;
	}
}