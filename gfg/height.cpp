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

int max(int a,int b)
{
	return (a>=b)?a:b;
}

int height(struct treenode* root)
{
	if(root==NULL)
		return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	return 1+max(lh,rh);
}

int diameter(struct treenode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ldiameter=0,rdiameter=0,lh=0,rh=0;

	lh=height(root->left);
	rh=height(root->right);

	ldiameter=diameter(root->left);
	rdiameter=diameter(root->right);

	return max(lh+rh+1,max(ldiameter,rdiameter));
}

int main()
{
	struct treenode* root=newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	cout<<diameter(root)<<endl;
}
