#include<cmath>
#include<cstdio>
#include<vector>    
#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

priority_queue<int, std::vector<int>, std::greater<int> > minheap;
priority_queue<int> maxheap;

int main() 
{
    int n,maxh,minh,minhup,maxhup;
    cin>>n;
    minheap.push(100001);
    maxheap.push(-1);
    for(int i=1;i<=n;i++)
    {
        double d;
        cin>>d;

        if(maxheap.top()<=d)
        {
            minheap.push(d);
        }

        else
        {
            maxheap.push(d);
        }
        minh=minheap.size();
        maxh=maxheap.size();
        if(minh-maxh>1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else
        {
            if(maxh-minh>1)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        minhup=minheap.size();
        maxhup=maxheap.size();
        if(maxhup==minhup)
        {
           cout<<(minheap.top()+maxheap.top())/2.0<<endl;
        }
        else
        {
            if(minhup>maxhup)
            {
                cout<<minheap.top()<<endl;
            }
            else
            {
                cout<<maxheap.top()<<endl;
            }
        }
    }
}
