#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int n,a[10000];
	cin>>n;
	if(n!=0){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}

		for (int i=0;i<n;i++){
			cout<<a[n-1-i]<<" ";
		}
	}
}
