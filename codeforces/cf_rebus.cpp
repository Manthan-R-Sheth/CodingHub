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

template <typename T>
  string tostring ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

int main()
{
	char questionmark,op[101],equality,value;
	int n,plus=0,minus=0,i=0;
	while(true)
	{
		cin>>questionmark;
		cin>>value;
		if(value=='+')
		{
			op[i]=value;
			plus++;
		}
		else
			if(value=='-')
			{
				op[i]=value;
				minus++;
			}
			else
			{
				op[i]=value;
				break;
			}
		i++;
	}
	cin>>n;

	int mini= (plus-(n*minus));
	int maxi= ((n*plus)-minus);

	if(n<mini && n>maxi)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		int s=0,cursgn;
		string result="";

		cout<<"Possible"<<endl;

		for(int i=0;i<101;i++)
		{
			if(op[i]=='=')
			{
				result.append(tostring(abs(n-s))+ "= "+ tostring(n));
				break;
			}

			if(op[i]=='+')
			{
				cursgn= 1;
				plus--;
			}

			else
			{
				cursgn= -1;
				minus--;
			}

			for(int x=1;x<=n;x++)
			{
				int curmax= (s+(cursgn*x)+(plus*n)-(minus));
				int curmin= (s+(cursgn*x)+(plus)-(n*minus));
				if(x>=curmin && x<=curmax)
				{
					result.append(tostring(x)+" "+op[i]+" ");
					s+=cursgn*x;
					break;
				}
			}
		}
		cout<<result<<endl;
	}

}