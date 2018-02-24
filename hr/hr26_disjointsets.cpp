#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

// a structure to represent an edge in graph
int maxi=INT_MIN,mini=INT_MAX;
struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
struct subset
{
    int parent;
    int rank;
    int height;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int g, int b)
{
    int groot = find(subsets, g);
    int broot = find(subsets, b);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[groot].rank < subsets[broot].rank)
    {
    	subsets[groot].parent = broot;
    	subsets[broot].height+=subsets[groot].height;
    	subsets[groot].height=1;
    }
        
    else 
    	if (subsets[groot].rank > subsets[broot].rank)
    	{
    		subsets[broot].parent = groot;
    		subsets[groot].height+=subsets[broot].height;
    		subsets[broot].height=1;
    	}
        
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[broot].parent = groot;
        subsets[groot].rank++;
        subsets[groot].height+=subsets[broot].height;
        subsets[broot].height=1;
    }
}
 
// The main function to check whether a given graph contains cycle or not
pair<int,int> maxmin( struct Graph* graph )
{
    int V = graph->V;
    int E = graph->E;
 
    // Allocate memory for creating V sets
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        subsets[v].height=1;
    }
 
    for(int e = 0; e < E; ++e)
    {
        int g = find(subsets, graph->edge[e].src);
        int b = find(subsets, graph->edge[e].dest);
        if(g!=b)
        {
        	Union(subsets, g, b); 
        } 
    }
    for (int v = 0; v < V; ++v)
    {
    	if(subsets[v].height>maxi)
    	{
    		maxi=subsets[v].height;
    	}
    	if(subsets[v].height<mini && subsets[v].height>1)
    	{
    		mini=subsets[v].height;
    	}
    }
    return make_pair(mini,maxi);
}
 
// Driver program to test above functions
int main()
{ 
	int n,g,b;
	cin>>n;
    struct Graph* graph = createGraph(2*n, n);
 
 	for(int i=0;i<n;i++)
 	{
 		cin>>g>>b;
 		graph->edge[i].src = g;
    	graph->edge[i].dest = b;	
 	}
 	pair<int,int> ans=maxmin(graph);
 	cout<<ans.first<<" "<<ans.second<<endl;
}