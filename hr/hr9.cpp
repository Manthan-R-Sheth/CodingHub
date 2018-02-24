#include<map>
#include<queue>
#include<vector>
#include<algorithm>

struct Qitem{
	int hdist;
	node* currnode;
};

void LevelOrder(node * root)
{
	queue<Qitem*> nodes;
	map<int, int> hd;
	vector<int> v;
	Qitem* qitem=new Qitem;
 	if(root==NULL){
 		return;
 	}
 	qitem->hdist=0;
 	qitem->currnode=root;
 	nodes.push(qitem);
 	while(!nodes.empty()){
 		Qitem* q=nodes.front();
        nodes.pop();
 		node* curr=q->currnode;
 		int hdis=q->hdist;

		hd.insert(pair<int,int>(hdis,curr->data));
		cout<<curr->data<<" ";

 		Qitem* qitem=new Qitem;
 		if(curr->left!=NULL){
 			qitem->hdist=hdis-1;
 			qitem->currnode=curr->left;
 			nodes.push(qitem);
 		}
 		if(curr->right!=NULL){
 			qitem->hdist=hdis+1;
 			qitem->currnode=curr->right;
 			nodes.push(qitem);
 		}
 	}
}
