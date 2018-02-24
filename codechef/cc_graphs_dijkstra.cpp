//***********************************************DIJKSTRA ALGO**************************************
// Complexity is O(V^2);
//However using heaps/set improves time complexity and involves the concept of adjacency list.

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
#define V 9
int mindist(int dist[V],bool sptset[V])
{
	int mini=INT_MAX,minindex=0;
	for(int i=0;i<V;i++)
	{
		if(sptset[i]==false && dist[i]<=mini)
		{
			mini=dist[i];
			minindex=i;
		}
	}
	return minindex;
}

void printsol(int dist[V])
{
	for(int i=0;i<V;i++)
	{
		cout<<i<<"     "<<dist[i]<<endl;
	}
}

void dijkstra(int graph[V][V],int src)
{
	int dist[V];
	bool sptset[V];

	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[src]=0;
	for(int i=0;i<V;i++)
	{
		int u=mindist(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<V;v++)
		{
			if(sptset[v]==false && graph[u][v]!=0 && dist[u]!=INT_MAX && (dist[u]+graph[u][v]<dist[v]))
			{
				dist[v]=dist[u]+graph[u][v];	
			}
		}
	}
	printsol(dist);
}

int main()
{
	//adjacency matrix representation of graph is considered.
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
}