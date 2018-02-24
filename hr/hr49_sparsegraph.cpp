//*************************************************WORKED***************************************
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

class Graph
{
    int V;
    vector<int> *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v);
    void solve(int s,int n);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 

void Graph::solve(int src,int n)
{
    int dis[n+1];
    for(int i=0;i<=n;i++)
    {
        dis[i]=2147483647;
    }
    dis[src]=0;
    vector<int> v;
    v.push_back(src);
    
    vector<int> villageperma;
    for(int i=1;i<=n;i++)
    {
        villageperma.push_back(i);
    }

    while(!v.empty())
    {
        std::vector<int> villageroad=villageperma;
        int curr=v.back();
        v.pop_back();
        while(!villageroad.empty())
        {
            std::vector<int>::iterator it=find(adj[curr].begin(),adj[curr].end(),villageroad.back());
            if(it==adj[curr].end())
            {
                if(dis[villageroad.back()]>dis[curr]+1)
                {
                    dis[villageroad.back()]=dis[curr]+1;
                    v.push_back(villageroad.back());
                }
            }
            villageroad.pop_back();
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=src)
        {
            cout<<dis[i]<<" ";
        }
    }
    cout<<endl;
}
 
int main()
{
    int n,m,u,v,s,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        Graph g(n+1);
        
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            g.addEdge(u,v);
        }
        cin>>s;
        g.solve(s,n);
    }
}