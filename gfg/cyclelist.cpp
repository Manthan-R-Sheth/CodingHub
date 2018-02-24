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

struct Node
{
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next=NULL;
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

void detectloop(struct Node* head)
{
	struct Node* slow=head;
	struct Node* fast=head;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			cout<<"Loop found"<<endl;
			return;
		}

	}
	cout<<"No Loop"<<endl;
}

int main()
{
	int n,a;
	cin>>n;
	cin>>a;
	struct Node* root=newNode(a);
	struct Node* head=root;
	struct Node* head1=root;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		root->next=newNode(a);
		root=root->next;
	}
	root->next=head->next->next;
	//printlist(head1);
	detectloop(head);
}