#include<iostream>
#include<cstdio>
using namespace std;
int maximise(int a[],int n);
int maxsubarray(int a[],int n){
	int max=0,max_end=0,count=0;
	for(int i=0;i<n;i++){
		max_end=max_end+a[i];
		if(max_end<0)
			max_end=0;
		if(max_end>max){
				max=max_end;
				count++;
			}
	}
	if(count>0)
		return max;
	
	else{
		int m=maximise(a,n);
		return m;}
}
int maxsubarraynoncontiguous(int a[],int n){
	int maxnonconti=0,count=0;;
	for(int i=0;i<n;i++){
		if(a[i]<0)
			continue;
		else{
			count++;
			maxnonconti+=a[i];
		}
	}
	if(count>0){
	return maxnonconti;}
	else{
		int m=maximise(a,n);
		return m;}
}

int maximise(int a[],int n){
	int i=0,max= -10000;
	for(i=0;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

int main()
{
	int t,n;
	int a[100000];
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<maxsubarray(a,n)<<" "<<maxsubarraynoncontiguous(a,n)<<endl;
	}
}