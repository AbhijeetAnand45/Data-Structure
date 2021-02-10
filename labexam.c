#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;

};
struct BSTNode *root=NULL;
struct BSTNode *createnode(int data)
{
    struct BSTNode *temp;
    temp=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

      /* INSERT OPERATION */

struct BSTNode *insert(struct BSTNode *root,int data)
{
    
    struct BSTNode *n=createnode(data);
    if(root==NULL)
    {
        root=n;
    }
    else if(root->data>data)
    {
        root->left=insert(root->left,data);

    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void postorder(struct BSTNode *root)
{
    if(root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
 
 void reversepostorder(struct BSTNode *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
       
        postorder(root->right);
         postorder(root->left);
        
        
    }
}
   
int main()
{
    struct BSTNode *temp; 
    struct BSTNode *root = NULL;
    int ch,data,item,x,z;
    int n;
    
    printf("\nHow many data do you want to enter: ");
    scanf("%d",&n);
    printf("\nPlease enter the data in the tree: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&z);
        root=insert(root, z);
    }
    printf("postorder traversal of the above tree is: ");
    postorder(root);
    printf("reverse postorder traversal of the above tree is: ");
    reversepostorder(root);

}
