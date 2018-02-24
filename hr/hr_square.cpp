#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int squareroots(int a,int b){
	int c=ceil(sqrt(a));
	int d=floor(sqrt(b));
	int count=d-c+1;
	return count;
}
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<squareroots(a,b)<<endl;
	}
}