#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

void swap(int*a,int*b){
	int*tmp;
	*tmp=*a;
	*a=*b;
	*b=*tmp;
}

void bubbleSort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
}

void printArr(int arr[] , int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArr(arr, n);
    return 0;
}