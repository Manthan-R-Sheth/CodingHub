#include<map>
#include<set>
#include<list>
#include<cmath>
#include<sstream>
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
string result="1";

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

string factorof10(string a)
{
	string zeroes;
	char ld;
	while(a.size()!=0)
	{
		ld=a[a.size()-1];
		if(ld=='0')
		{
			zeroes.append("0");
		}
		a.erase(a.size()-1,1);
	}
	return zeroes;
}

bool beautiful(string a)
{
	int ones=0;
	char ld;
	string tmp=a;
	while(a.size()!=0)
	{
		ld=a[a.size()-1];
		if(ld=='1' || ld=='0')
		{
			if(ld=='1')
				ones++;
		}
		else
		{
			return false;
		}
		a.erase(a.size()-1,1);
	}
	if(ones==1 || tmp.compare("0")==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	unsigned long long n;
	cin>>n;
	string a[n],nonbeautiful="-1";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(!beautiful(a[i]))
		{
			nonbeautiful=a[i];
			break;
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i].compare(nonbeautiful)!=0)
		{
			if(a[i].compare("0")==0)
			{
				cout<<"0"<<endl;
				return 0;
			}
			if(a[i].compare("1")==0)
			{
				if(result[0]!='1')
				{
					result[0]='1';
					continue;
				}
				else
				{
					continue;
				}
			}
			result.append(factorof10(a[i]));
		}
	}
	if(nonbeautiful.compare("-1")==0)
	{
		cout<<result<<endl;
		return 0;
	}
	
	result.replace(0,1,to_string(nonbeautiful));
	cout<<result<<endl;
}