#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Graph
{
    int V;
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V+1];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::shortestPath(int src)
{
    set< pair<int, int> > setds;
 
    vector<int> dist(V+1, INT_MAX);
 
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INT_MAX)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    for(int i=1;i<V+1;i++)
    {
        if(dist[i]!=INT_MAX)
        {
            if(i!=src)
            {
                cout<<dist[i]<<" ";                   
            }
        }
        else
        {
            cout<<"-1"<<" ";
        }
    }
    cout<<endl;
}
 
int main()
{
    int n,k,u,v;
    cin>>n;
    Graph g(n);
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g.addEdge(u,v,1);
    }
    cin>>k;
    g.shortestPath(s);

 
}