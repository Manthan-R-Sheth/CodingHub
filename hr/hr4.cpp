#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
using namespace std;

map<string, int> occur;

int main(){
	int n,q;
	string s,ret;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(occur.find(s)!= occur.end()){
			occur[s]++;
		}
		else{
			occur.insert(pair<string,int>(s,1));
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>ret;
		if(occur.find(ret)!= occur.end()){
			cout<<occur[ret]<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
}