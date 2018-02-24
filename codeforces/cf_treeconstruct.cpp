#include<list>
#include<cmath>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
#include<map>
using namespace std;

int b[100001];

struct node
{
   int data;
   node* left;
   node* right;
};

node* newNode(int item)
{
    struct node* temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* node, int data)
{
    if (node == NULL) 
        return(newNode(data));

    else
      {
        struct node* temp;  
     
        if (data <= node->data)
        {    
             temp = insert(node->left, data);
             node->left  = temp;
             if(b[data]==0)
                b[data]=node->data;
        }
        else
        {
            temp = insert(node->right, data);
            node->right = temp;
            if(b[data]==0)
                b[data]=node->data;
        }  
    }

    return node;
}

int main()
{
    int n,data;
    memset(b,0,sizeof(b));
    struct node* root=NULL;
    cin>>n;
    int a[n];

    cin>>data;
    a[0]=data;
    root=insert(root,data);

    for(int i=1;i<n;i++)
    {
        cin>>data;
        a[i]=data;
        insert(root,data);
    }

    for(int i=1;i<n;i++)
    {
        cout<<b[a[i]]<<" ";
    }
    cout<<endl;
}
