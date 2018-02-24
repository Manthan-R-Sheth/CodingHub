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

int n;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	Node* node=new Node;
	node->next=NULL;
	node->data=data;
	return node;
}

void printlist(Node* head)
{
	if(head==NULL)
	{
		cout<<"NULL"<<endl;
		return;
	}
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
}

struct Node* delmidhead(Node* head)
{
	int count=2;
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		return NULL;
	}
	Node* root=head;
	while(count!=((n/2)+1))
	{
		count++;
		head=head->next;
	}
	head->next=head->next->next;
	return root;
}

int main()
{
	int a;
	cin>>n;
	cin>>a;
	Node* head=newNode(a);
	Node* root=head;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		head->next=newNode(a);
		head=head->next;
	}
	Node* ans=delmidhead(root);
	printlist(ans);
}