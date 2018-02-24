//************************************ TEMPLATE IS USED ..... LAMBDA EXP CAN ALSO BE USED*********************
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
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

template <class T,class S> struct pair_equal_to : binary_function <T,pair<T,S>,int> 
{
  	bool operator() (const T& y, const pair<T,S>& x) const
    {
        return x.first==y;
  	}
};

int binarysearch(int a[],int key,int imin,int imax)
{
  if (imax < imin)
    return -1;
  else
    {
      int imid =(imin+	imax)/2;

      if (a[imid] > key)
        return binarysearch(a, key, imin, imid - 1);
      else if (a[imid] < key)
        return binarysearch(a, key, imid + 1, imax);
      else
        return imid;
    }
}

int main()
{
	int t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m;
		cin>>n;
		int ans=-1,a[n];
		set<pair<int,int> > s;
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			int d;
			cin>>d;
			s.insert(make_pair(d,i));
		}
		int i=0;
		for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
		{
			a[i]=(it->first);
			i++;
		}
		int j=0;
		for(j=0;j<n;j++)
		{
			ans=binarysearch(a,m-a[j],0,n-1);
			if(ans==-1 || ans==j)
				continue;
			else
			{
				flag=true;
				break;				
			}
		}
		if(flag)
		{
			set< pair <int, int> >::iterator it = find_if(s.begin(),s.end(),bind1st(pair_equal_to<int,int>(),a[j]));
			s.erase(it);
			set< pair <int, int> >::iterator it1 = find_if(s.begin(),s.end(),bind1st(pair_equal_to<int,int>(),a[ans]));

			if((it->second) > (it1->second))
				cout<<(it1->second)+1<<" "<<(it->second)+1<<endl;
			else
				cout<<(it->second)+1<<" "<<(it1->second)+1<<endl;
		}
	}
}