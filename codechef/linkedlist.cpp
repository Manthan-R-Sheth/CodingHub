#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
	int info;
	struct node *next;
}*start;

class linkedlist
{
public:
	linkedlist(){start=NULL;
		cout<<"in constructor";}
	node* create(int);
};
main(){
	linkedlist sl;
	struct node *first;
	first=sl.create(5);
	cout<<first->info<<endl;
	cout<<start<<endl;
}
node* linkedlist::create(int value){
	struct node *temp;
	temp=new (struct node);
	if(temp==NULL){
		cout<<"Memory not allocated "<<endl;
        return 0;
	}
	else
    {
        temp->info = value;
        temp->next = NULL; 
        cout<<"Added a node";    
        return temp;
    }
}