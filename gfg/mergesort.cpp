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
#include<functional>
#include<cstring>
#include<climits>
using namespace std;
void merge(int a[],int l,int r,int mid)
{
	int n1=mid- l + 1;
	int n2=r-mid;
	int i=0,j=0,k = l;

	int L[n1],R[n2];
	for(int m=0;m<n1;m++)
		L[m]=a[m+l];
	for(int m=0;m<n2;m++)
		R[m]=a[m+mid+1];

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(r+l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,r,mid);
	}
}

int main()
{	
	int a[9]={3,5,1,100,54,57,2,1,1};

	mergesort(a,0,8);
	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<endl;
	}
}