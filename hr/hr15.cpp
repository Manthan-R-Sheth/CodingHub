#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string s="";
	int q,type,k;
	stack<pair<int,string> > undo;
	pair<int,string> undoop;
	cin>>q;
	while(q--)
	{
		cin>>type;
		if(type==1)
		{
			string w="";
			cin>>w;
			s.append(w);
			undo.push(pair<int,string>(1,w));
		}
		else
			if(type==2)
			{
				string erased="";
				cin>>k;
				for(int i=s.length()-k;i<s.length();i++)
				{
					erased+=s[i];
				}
				s.erase(s.length()-k,k);
				undo.push(pair<int,string>(2,erased));
			}
			else
				if(type==3)
				{
					cin>>k;
					cout<<s[k-1]<<endl;
				}
				else
				{
					undoop=undo.top();
					undo.pop();
					if(undoop.first==1)
					{
						s.erase(s.length()-(undoop.second).length(),(undoop.second).length());
					}
					else
					{
						s.append(undoop.second);
					}
				}
	}
}