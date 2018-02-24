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

void inorder(struct treenode* root)
{
	//Using Recursion
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);

	//Using Stack
	stack<treenode*> inordertrav;
	struct treenode* curr=root;
	bool flag=true;
	while(flag)
	{
		if(curr!=NULL)
		{
			inordertrav.push(curr);
			curr=curr->left;
		}
		else
		{
			if(!inordertrav.empty())
			{
				curr=inordertrav.top();
				inordertrav.pop();
				cout<<curr->data<<endl;
				curr=curr->right;
			}
			else
				flag=false;
		}
	}

}

int main()
{
	struct treenode* root=newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	inorder(root);
}
