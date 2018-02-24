//Huffman Coding
/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
#include<string>

bool isleaf(node*);

bool isleaf(node* curr){
	if(curr->left==NULL && curr->right==NULL){
		return true;
	}
	else
		return false;
}

void decode_huff(node * root,string s)
{
	node* original=root;
	string decoded="";
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			root=root->left;
		}
		else{
			root=root->right;
		}
		if(isleaf(root)){
				decoded+=(root->data);
				root=original;
			}
	}
	cout<<decoded<<" ";    
}