#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int dis[1000];
void relax(int,int);
struct Graph{
	int v,e;
	struct Edge* edge;
};

struct Edge
{
	int dest,src;
};

struct Graph* createGraph(int v,int e){ //creates graph
	struct Graph* graph=(struct Graph*)malloc( sizeof(struct Graph));
	graph->v=v;
	graph->e=e;
	graph->edge= (struct Edge*)malloc( sizeof(struct Edge));
	return graph;
}

void bfs(struct Graph* graph,int s){
	dis[s]=0;
	for(int i=0;i<graph->e;i++){
		if(graph->edge[i].src==s || graph->edge[i].dest==s){
			relax(graph->edge[i].src,graph->edge[i].dest);
		}
		else
			dis[graph->edge[i].src]=-1;
	}
	for(int i=0;i<graph->v;i++){
		if(i!=s){
			cout<<dis[i]<<" ";
		}
	}
	cout<<endl;
}
void relax(int s,int d){
	if(dis[d]>dis[s]+6)
		dis[d]=dis[s]=6;
}

int main(){
	int t,v,e,s;
	
	Graph* graph;
	cin>>t;
	while(t--){
		for(int i=0;i<1000;i++)
			dis[i]=1e8;

		cin>>v>>e;
		for(int i=0;i<e;i++){
			graph=createGraph(v,e);
			cin>>graph->edge[i].src>>graph->edge[i].dest;
		}
		cin>>s;
		bfs(graph,s);
	}
}
