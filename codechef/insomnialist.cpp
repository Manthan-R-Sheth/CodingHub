#include<list>
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const long MAX=1000000007;
list<int> row;
void product(int,int);

int main(){
	int soldier,command,l,r,ind,b;
	char c;

	cin>>soldier>>command;

	for(int i=0;i<soldier;i++){
		cin>>b;
		row.push_back(b);
	}

	for(int i=0;i<command;i++){
		cin>>c;
		if(c=='C'){
			cin>>l>>r;
			product(l,r);
		}
		else if(c=='D'){
				row.pop_front();
				}

			  else if(c=='I'){
			  	cin>>ind;
			  	row.insert(row.begin(),ind);
			  }
	}
}

void product(int l,int r){
	long long ans=1,count=0;
    list<int>::iterator i;

	for(i=row.begin(); i != row.end(); ++i){
		count++;
		if(count>=l && count<=r)
			ans*=(*i);
		else if(count>r)
			break;
	}
   cout << (ans%MAX) << endl;
}