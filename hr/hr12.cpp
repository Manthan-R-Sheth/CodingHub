/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node* newNode(int);
node* newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node * insert(node * root, int value)
{
	node* node=root;
	/* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (value < node->data)
        node->left  = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);   
 
    /* return the (unchanged) node pointer */
    return root;
}
