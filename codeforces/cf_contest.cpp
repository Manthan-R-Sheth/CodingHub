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
	long long n,m,r;
	int score;
	cin>>n>>m;
	string s;
	
	set<pair<int,string> > *record;
	record=new set< pair<int, string> >[m+1];

	for(int i=0;i<n;i++)
	{
		cin>>s>>r>>score;
		record[r].insert(make_pair(score,s));
	}

	set< pair<int, string> >::iterator it;   

    for (int i=1;i<=m;i++)
    {
    	if(record[i].size()>2)
    	{
    		it=record[i].end();
    		it--;
    		int topper= (*it).first;
    		string toppername= (*it).second;

    		it--;
    		int topper2= (*it).first;
    		string topper2name=(*it).second;

    		it--;
    		int topper3= (*it).first;
    		if(topper3==topper2)
    		{
    			cout<<"?"<<endl;
    		}
    		else
    		{
    			cout<<toppername<<" "<<topper2name<<endl;
    		}
    	}
    	else
    	{
    		it=record[i].end();
    		it--;
    		cout<< (*it).second <<" ";
    		it--;
    		cout<< (*it).second <<endl;
    	}
    }

}