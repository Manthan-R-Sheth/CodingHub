#include<bits/stdc++.h>
using namespace std;

struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
};

struct treenode* newNode(int data)
{
	struct treenode* node=(struct treenode*)malloc(sizeof(struct treenode));
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	return node;
}

void leaves(struct treenode* root)
{
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<endl;
	}
	else
	{
		leaves(root->right);
		leaves(root->left);
	}
}

int main()
{
	struct treenode* root=newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	leaves(root);
}
