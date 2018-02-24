#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
int swapc=0,inserts=0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int low,int high)
{
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
			swapc++;
		}
	}
	swap(&a[i+1],&a[high]);
	swapc++;
	return (i+1);
}

void quickswaps(int a[],int low,int high)
{
	if(high>low)
	{
		int pi=partition(a,low,high);
		quickswaps(a,low,pi-1);
		quickswaps(a,pi+1,high);
	}
}

void insertshifts(int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=i-1;
		int tmp=b[i];
		while(j>=0 && b[j]>=tmp)
		{
			b[j+1]=b[j];
			j--;
			inserts++;
		}
		b[j+1]=tmp;
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	quickswaps(a,0,n-1);
	insertshifts(b,n);
	int diff= inserts- swapc;
	cout<<diff<<endl;
}