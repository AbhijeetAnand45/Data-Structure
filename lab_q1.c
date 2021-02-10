/* NAME : ABHIJEET ANAND
   ROLL : 19103001
   SEMESTER : III   DS LAB EXAM  */

#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode *root=NULL;

struct BSTNode* createNode(int data)
{
    struct BSTNode *n = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return (n);
}
struct BSTNode *insert(struct BSTNode *root,int data)
{
    
    struct BSTNode *n=createNode(data);
    if(root==NULL)
    {
        root=n;
    }
    else if(root->data > data)
    {
        root->left=insert(root->left,data);

    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void reverse_postorder(struct BSTNode* root)
{
   
    if (root == NULL)
        return;

    
    reverse_postorder(root->right);
    reverse_postorder(root->left);
    printf("%d ", root->data);
}

int main()
{
    struct BSTNode *temp; 
    struct BSTNode *root = NULL;
    int ch,data,item,x,z;
    int n;
    
    printf("\nHow many data do you want to enter: ");
    scanf("%d",&n);
    printf("\n");
    printf("\nPlease enter the data in the tree: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&z);
        root=insert(root, z);
    }
    printf("\n");
    
    printf("\nReverse postorder traversal of the above tree is: ");
    reverse_postorder(root);

    
    return 0;
}

   // void postorder(struct BSTNode *root)
// {
//     if(root!=NULL)
//     {

//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ",root->data);
//     }
// }
// printf("postorder traversal of the above tree is: ");
    // postorder(root);
