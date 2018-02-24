#include<map>
#include<queue>
#include<vector>
#include<algorithm>

void LevelOrder(node * root)
{
	queue<node*> nodes;
 	if(root==NULL){
 		return;
 	}
 	nodes.push(root);
 	while(!nodes.empty()){
 		node* q=nodes.front();
        nodes.pop();

		cout<<q->data<<" ";

 		if(q->left!=NULL){
 			nodes.push(q->left);
 		}
 		if(q->right!=NULL){
 			nodes.push(q->right);
 		}
 	}
}
