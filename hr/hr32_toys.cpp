#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
    long long n, k; 
    int answer = 0;
    cin >> n >> k;
    vector<long> prices;
    for(long i = 0; i < n; i++)
    {
        long p; 
        cin >> p;
        prices.push_back(p);
    }
    sort(prices.begin(),prices.end());
    for(long i = 0; i < prices.size(); i++)
    {
        if(k>=prices[i])
        {
            k=k-prices[i];
            answer++;
        }
        else
        {
            break;
        }
    }
    cout << answer << endl;
}
