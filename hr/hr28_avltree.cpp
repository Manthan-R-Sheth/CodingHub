#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<stack>
using namespace std;

node* newNode(int val)
{
	struct node* root=(struct node*)malloc(sizeof(node*));
	root->left=NULL;
	root->right=NULL;
	root->val=val;
	root->ht=1;
	return root;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(node* node)
{
	if(node==NULL)
		return 0;
	return (node->ht);
}

int getBalance(node* node)
{
	if (node == NULL)
        return 0;
	return (height(node->left)-height(node->right));
}

struct node* leftrotate(node* node)
{
	struct node* a=node->right;
	struct node* b= a->left;

	a->left=node;
	node->right=b;

	node->ht= max(height(node->left),height(node->right))+1;
	a->ht = max(height(a->left),height(a->right))+1;
	return a;
}

struct node* rightrotate(node* node)
{
	struct node* a=node->left;
	struct node* b= a->right;

	a->right=node;
	node->left=b;

	node->ht= max(height(node->left),height(node->right))+1;
	a->ht = max(height(a->left),height(a->right))+1;
	return a;
}

node* insert(node* root,int val)
{
   if(root==NULL)
   	return newNode(val);

   if(val< root->val)
   {
   		root->left=insert(root->left,val);
   }
   else
   {
   		root->right=insert(root->right,val);	
   }
   root-> ht= max(height(root->left),height(root->right))+1;

   int balance=getBalance(root);

   //left left rotate
   if(balance>1 && val<root->left->val)
   {
   		return rightrotate(root);
   }

   //left right rotate
   if(balance>1 && val>root->left->val)
   {
   		root->left = leftrotate(root->left);
   		return rightrotate(root);
   }

   //right left rotate
   if(balance<-1 && val<root->right->val)
   {
   		root->right=rightrotate(root->right);
   		return leftrotate(root);
   }
   //right right rotate
   if(balance<-1 && val>root->right->val)
   {
   		return leftrotate(root);
   }
	return root; 
}