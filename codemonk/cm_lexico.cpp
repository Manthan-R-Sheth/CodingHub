#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int flag[456];

void ans(string x,int i,int j)
{
    if(i>j) return;
	char maxw = -1;
	int maxi = i;
	for(int k=i;k<=j;k++) {
		 if(flag[x[k]]==0 && maxw<x[k]){maxw = x[k]; maxi=k;}
	}
	if(maxw == -1) return;
	if(flag[maxw] == 0){
	   printf("%c",maxw);
	   flag[maxw] = 1;  
	}
	ans(x,maxi+1,j);
}
int main()
{
	int n;
	memset(flag,0,sizeof(flag));
	cin >> n;
    string x;
    cin >> x;
    ans(x,0,x.length()-1);
    return 0;
}