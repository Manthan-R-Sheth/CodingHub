#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

Node* Reverse(Node* head)
{
	Node* tmp=NULL;
	Node* current =head;
   while(current!=NULL){
   		tmp=current->prev;
   		current->prev=current->next;
   		current->next=tmp;
   		current=current->prev;
   }
   if(tmp!=NULL){
   	head=tmp->prev;
   }
   return head;
}
