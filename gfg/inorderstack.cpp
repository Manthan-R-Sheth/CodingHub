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
    struct node* left;
    struct node* right;
};

node* newtNode(int data)
{
	node* nodenew=(node*)malloc(sizeof(node));
	nodenew->data=data;
	nodenew->left=NULL;
	nodenew->right=NULL;
	return nodenew;
}

void inOrder(node* root)
{
	stack<node*> inorder;
	node* current=root;
	while(1)
	{
		while(current!=NULL)
		{
			inorder.push(current);
			current=current->left;
		}
		if(inorder.empty())
		{
			break;
		}
		else
		{
			node* popped=inorder.top();
			cout<<popped->data<<" ";
			inorder.pop();
			current=popped->right;
		}
	}
}

int main()
{	
	struct node *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
  root->right->left  = newtNode(6);
  root->right->right = newtNode(7); 
 
  inOrder(root);
 
}