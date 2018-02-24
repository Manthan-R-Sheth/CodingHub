#include<iostream>
#include<list>
#include<typeinfo>
using namespace std;

class Graph{
public:
	list<int> *adj;
	Graph();
	void manipulate();
};
Graph::Graph(){
	adj=new list<int>[3];
}
void Graph::manipulate(){
	adj[1].push_back(10);
	cout<<typeid(adj).name()<<endl;
	list<int>:: iterator i;
	for(i=adj[1].begin();i!=adj[1].end();i++)
	{
		cout<<*i<<"yoyo"<<endl;
	}
}
int main()
{
	Graph lists;
	lists.manipulate();
	cout<<"Good Work"<<endl;
	return 0;
}