#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Graph
{
    int V;
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int c);
    void miniumpenalty(int a,int b);
    void dfs(bool visited[],int v,int b,vector<int> &penalty,vector<int> &possiblepenalties);
    int min(int a,int b)
    {
        return (a<=b)?a:b;
    }
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V+1];
}
 
void Graph::addEdge(int u, int v, int c)
{
    adj[u].push_back(make_pair(v, c));
}

void Graph::dfs(bool visited[],int v,int b,vector<int> &penalty,vector<int> &possiblepenalties)
{
    visited[v]=true;
    list< pair<int, int> >::iterator it;

    if(v==b)
    {
        visited[v]=false;
        possiblepenalties.push_back(penalty[b]);
        return;
    }
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(!visited[(*it).first])
        {
            penalty[(*it).first]=((*it).second | penalty[v]);
            dfs(visited,(*it).first,b,penalty,possiblepenalties);
        }
    }
    visited[v]=false;
}

void Graph::miniumpenalty(int a,int b)
{
    set< pair<int, int> > setds;
 
    vector<int> penalty(V+1, INT_MAX);
    vector<int> possiblepenalties;
    list< pair<int, int> >::iterator it;

    for(it=adj[a].begin();it!=adj[a].end();it++)
    {
        bool visited[V+1];
        memset(visited,false,sizeof(visited));
        visited[a]=true;
        penalty[(*it).first]=((*it).second);
        dfs(visited,(*it).first,b,penalty,possiblepenalties);
    }

    // for(int i=0;i<possiblepenalties.size();i++)
    // {
    //     cout<<i<<"       "<<possiblepenalties[i]<<endl;
    // }
    if(possiblepenalties.size()<=0)
    {
        cout<<"-1"<<endl;
        return;
    }
        
    else
    {
        sort(possiblepenalties.begin(),possiblepenalties.end());
        cout<<possiblepenalties[0]<<endl;
    }
        
}
 
int main()
{
    int n,m,a,b,u,v,c;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        g.addEdge(u,v,c);
    }
    cin>>a>>b;
    g.miniumpenalty(a,b);
}