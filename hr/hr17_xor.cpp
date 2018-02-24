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
#include<limits>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

void printQueue(priority_queue<int,vector<int> , greater<int> > &pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}

int main() 
{
	priority_queue<int,vector<int> , greater<int> > pq;
	for(int i=0;i<25;i++)
	{
		pq.push(25-i);
	}
	printQueue(pq);
}