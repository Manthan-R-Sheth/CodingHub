#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int bs(int[],int,int,int);

int main(){
	int arr[]={1,2,3,4,5,6};
	cout<<bs(arr,0,5,3);
}

int bs(int arr[],int low,int up, int find){
	int mid=(low+up)/2;
	
	if(up>=low){	
		if(arr[mid]>find)
			return bs(arr,low,mid-1,find);
		
		if(arr[mid]<find)
			return bs(arr,mid+1,up,find);
		
		return mid;
	}

	return -1;
}
