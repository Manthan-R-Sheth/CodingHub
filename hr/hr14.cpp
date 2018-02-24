#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

bool isPair(char open, char close)
{
	if(open=='{' && close=='}')return true;
	else
		if(open=='[' && close==']')return true;
		else
			if(open=='(' && close==')')return true;
			else
				return false;
}

bool isBalanced(string s)
{
	stack<char> seq;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='[' || s[i]=='{' || s[i]=='(')
		{
			seq.push(s[i]);
		}
		else
		{
			if(seq.empty() || !isPair(seq.top(),s[i]))
			{
				return false;
			}
			seq.pop();
		}
	}
	return seq.empty()?true:false;
}

int main() {
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		if(isBalanced(s)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}   
}
