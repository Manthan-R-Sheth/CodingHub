#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
	double a= pow(49.0,3.0)+pow(10.0,3.0)+pow(5.0,3.0);
	double sum;
	cout<<a<<"\n";
	for(int i=35;i<49;i++){
		sum=a+pow(i,3.0);
		cout<<sum<<"\n";
	}
}