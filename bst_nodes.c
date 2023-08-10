
#include<stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
 
};
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
 
static int count = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int nonleafnodes(struct node* newnode)
{
    if(newnode != NULL)
    {
        nonleafnodes(newnode->left);
        if((newnode->left != NULL) || (newnode->right != NULL))
        {
            printf("%d\t",newnode->info);
            count++;
        }
        nonleafnodes(newnode->right);
    }
    return count;
}

void main()
{
    struct node *newnode = createnode(25);
    newnode->left = createnode(15);
    newnode->right = createnode(35);
    newnode->left->left = createnode(10);
    newnode->left->right = createnode(20);
    newnode->right->left = createnode(30);
    newnode->right->right = createnode(50);
    
    printf("The number of nodes are %d\n",countnodes(newnode));
    count = 0; 
    
    printf("The non leaf nodes are \t");
    int nonleaf_nodes = nonleafnodes(newnode);
    printf("\n");
    printf("Number of non leaf nodes in first Tree are %d\n",nonleaf_nodes);
   
}
