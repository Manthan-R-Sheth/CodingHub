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

struct node
{
    int data;
    struct node* next;
};

node* newtNode(int data)
{
	node* nodenew=(node*)malloc(sizeof(node));
	nodenew->data=data;
	nodenew->next=NULL;
	return nodenew;
}

node* rev(node* root)
{
	node* prev=NULL;
	node* next;
	node* curr=root;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return root=prev;
}

int main()
{	
	struct node *root = newtNode(1);
  root->next        = newtNode(2);
  root->next->next  = newtNode(3);
  root->next->next->next  = newtNode(4);
 root->next->next->next->next  = newtNode(5);
 node* head=root;
 while(head!=NULL)
  {
  	cout<<head->data<<endl;
  	head=head->next;
  }
  node* revhead=rev(root);
  while(revhead!=NULL)
  {
  	cout<<revhead->data<<endl;
  	revhead=revhead->next;
  }
}