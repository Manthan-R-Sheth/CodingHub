#include<bits/stdc++.h>
#include<climits>
using namespace std;
class Graph
{
public:
    int V;
    vector<int> *adj;
    int *subtree_size;
    int *centroids;
 
public:
    Graph(int V);  
    void getCentroid();
    void addEdge(int u, int v);
    void getCentroid(int src);
    int getCentroid(int src, bool visited[], int n);
    void DFS(int src, bool visited[], int* n);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V+1];
    subtree_size=new int[V+1];
    memset(subtree_size, 0, sizeof(subtree_size));
    centroids=new int[V+1];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
 
void Graph::DFS(int src, bool visited[], int* n)
{
    visited[src] = true;
    *n += 1;
 
    subtree_size[src] = 1;
 
    vector<int>::iterator it;
 
    for (it = adj[src].begin(); it!=adj[src].end(); it++)
        if (!visited[*it])
        {
            DFS(*it, visited,n);
            subtree_size[src]+=subtree_size[*it];
        }
}
 
int Graph::getCentroid(int src, bool visited[], int n)
{
    bool is_centroid = true;
    visited[src] = true;
 
    int heaviest_child = 0;
 
    vector<int>::iterator it;
 
    for (it = adj[src].begin(); it!=adj[src].end(); it++)
        if (!visited[*it])
        {
            if (subtree_size[*it]>n/2)
                is_centroid=false;
 
            if (heaviest_child==0 ||
                subtree_size[*it]>subtree_size[heaviest_child])
                heaviest_child = *it;
        }
 
    if (is_centroid && n-subtree_size[src]<=n/2)
        return src;
 
    return getCentroid(heaviest_child, visited,n);
}

void Graph::getCentroid(int src)
{
    bool visited[V+1];
    memset(visited, false, sizeof(visited));
    int n=subtree_size[src];
    int centroid = getCentroid(src, visited,n); 
    centroids[src]=centroid;
}
void Graph::getCentroid()
{
    bool visited[V+1];
    memset(visited, false, sizeof(visited));
    int n=0;
    DFS(1, visited,&n); 
}

int main()
{
    int n,m,s,u;
    
    cin>>n>>m;
    Graph g(n);
    for(int i=1;i<n;i++)
    {
        cin>>u;
        g.addEdge(u,i+1);
    }
    g.getCentroid();
    for(int i=1;i<=n;i++)
    {
        g.getCentroid(i);
    }
    for(int i=0;i<m;i++)
    {
    	cin>>s;
    	cout<< g.centroids[s]<<endl;
    }
}