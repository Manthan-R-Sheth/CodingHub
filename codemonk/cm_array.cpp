#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int q;
	string s;
	cin>>q;
	while(q--)
	{
		cin>>s;
		reverse(s.begin(),s.end());
		cout<<s.length()<<endl;
	}
    return 0;
}