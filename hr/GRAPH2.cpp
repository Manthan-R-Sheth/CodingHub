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
	list<int> *adj;	
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void replace(int u,int r);
		void initialise();
		int countmin();
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::initialise()
{
	for(int i=1;i<100;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(i+j<=100)
			{
				addEdge(i,i+j);
			}			
			else
				continue;
		}
	}
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::replace(int u,int r)
{
	for(int i=1;i<=6;i++)
	{
		if(u-i>0)
		{
			for(list<int>::iterator it=adj[u-i].begin();it!=adj[u-i].end();it++)
			{
				if(*it==u)
				{
					adj[u-i].erase(it);
					addEdge(u-i,r);
				}
			}
		}
	}
}
int Graph::countmin()
{
	int level[101],curr,flag=1,parent[101];
	memset(level,-1,sizeof(level));
	memset(parent,0,sizeof(parent));
	int lev=0,par;
	level[1]=lev;

	while (flag) 
    {
        flag = 0;
        for (int i = 1; i <= 100; ++i) 
        {
            if (level[i] == lev) 
            {
                flag = 1;
                par = i;
                 
                // Exploring all the adjacent vertices
                for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++) 
                {
                    if (parent[*it] != 0) 
                    {
                        // A level for this is already set
                        continue;
                    }
                     
                    level[*it] = lev + 1;
                    parent[*it] = par;
                }
            }
        }
         
        ++lev;
    }
	return level[100];
}

int main()
{
	int t,laddercount,snakecount,sladder,eladder,ssnake,esnake;
	cin>>t;
	while(t--)
	{
		Graph g(100);
		g.initialise();

		cin>>laddercount;
		for(int i=0;i<laddercount;i++)
		{
			cin>>sladder>>eladder;
			g.replace(sladder,eladder);
		}
		cin>>snakecount;
		for(int i=0;i<snakecount;i++)
		{
			cin>>ssnake>>esnake;
			g.replace(ssnake,esnake);
		}
		int counts=g.countmin();
		cout<<counts<<endl;
	}
}