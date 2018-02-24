#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

int HasCycle(Node* head)
{
	map<long, int> nodeptr;
	int cycle=0;

	while(head!=NULL){
		if(nodeptr.find(&head)!=nodeptr.end()){
			cycle=1;
			break;
		}
		else{
			nodeptr.insert(pair<long,int>(&head,1));
			head=head->next;
		}
	}
   return cycle;
}