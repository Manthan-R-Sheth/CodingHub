#include <cstdio>
#include <map>
#include<iostream>

using namespace std;

map<int, long long> dp;

long long maximise(int n){
	if(n==0) return 0;
    
    if(dp[n]!=0) return dp[n];
    
    long long max=maximise(n/2)+maximise(n/3)+maximise(n/4);
    
    if(max>n) dp[n]=max;
    else dp[n]=n;
    
    return dp[n];
}

int main(){    
    int n;
        
    while(std::cin>>n)
    {
    std::cout<<maximise(n)<<endl;
    }
    
    return 0;
}