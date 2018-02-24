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
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
    void mst(int s,int n);
    pair<int,int> minkey(int key[],bool visited[],int n);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
pair<int,int> Graph::minkey(int key[],bool visited[],int n)
{
	int mini = INT_MAX, minindex;
   	for (int v = 1; v <=n; v++)
   	{
	     if (visited[v] == false && key[v] < mini)
	     {
	         mini = key[v];
	         minindex = v;
	     }
 	}
 	return make_pair(minindex,mini);
}

void Graph::mst(int src,int n)
{
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    int key[n+1];
    for(int i=0;i<=n;i++)
    {
    	key[i]=INT_MAX;
    }
    int parent[n+1];
    int mstdist=0;

    key[src]=0;

    for(int count=0;count<n;count++)
    {
    	pair<int,int> p=minkey(key,visited,n);
    	int u=p.first;
    	int mini=p.second;

    	mstdist+=mini;
    	
    	visited[u]=true;
    	for(list<pair<int,int> >::iterator it=adj[u].begin();it!=adj[u].end();it++)
    	{
    		if(visited[it->first]==false && it->second < key[it->first])
    		{
    			key[it->first]=it->second;
    			parent[it->first]=u;
    		}
    	}

    }
    cout<<mstdist<<endl;
}
 
int main()
{
    int n,m,u,v,w,s;
 	cin>>n>>m;
 	Graph g(n+1);
    
    for(int i=0;i<m;i++)
    {
    	cin>>u>>v>>w;
    	g.addEdge(u,v,w);
    }
    cin>>s;
    g.mst(s,n);
}