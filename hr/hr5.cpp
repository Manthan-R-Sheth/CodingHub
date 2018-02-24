Node* insert(Node* head, int data){

	Node* tmp=new Node;
	tmp=head;

	while(tmp!=NULL){
		tmp=tmp->next;
	}
	Node* tmp2= new Node;
	tmp2->data=data;
	tmp2->next=NULL;
	tmp=tmp2;
	return head;
}