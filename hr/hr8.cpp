Node* newnode(int);
Node* MergeLists(Node *headA, Node* headB)
{
	Node* merged=new Node;
	Node* head=new Node;
	head=NULL;
	bool flag=false;
	if(headA!=NULL && headB!=NULL){
		while(headA!=NULL && headB!=NULL)
		{
			if(headA->data <= headB->data){
				merged=newnode(headA->data);
				headA=headA->next;
				if(!flag){
					flag=true;
					head=merged;
				}
			}
			else{
				merged=newnode(headB->data);
				headB=headB->next;
				if(!flag){
					flag=true;
					head=merged;
				}
			}
			merged=merged->next;
		}

		if(headA==NULL && headB!=NULL){
			while(headB!=NULL){
				merged=newnode(headB->data);
				merged=merged->next;
				headB=headB->next;
			}
		} 
		else{
			while(headA!=NULL){
				merged=newnode(headA->data);
				merged=merged->next;
				headA=headA->next;
			}
		}
	}
	else{
		if(headA==NULL && headB!=NULL){
			head=headB;
		}
		else{
			if(headA!=NULL && headB==NULL){
				head=headA;
			}
		}
	}
	return head;
}

Node* newnode(int data){
	Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}