  /* NAME : ABHIJEET ANAND
     ROLL : 19103001
     EXPERIMENT 13 : BINARY SEARCH TREE IMPLEMENTATION */
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

struct BSTNode *insert(struct BSTNode *root,int data){
    struct BSTNode *n=createnode(data);
    if(root==NULL){
        root=n;
    }
    else if(root->data>data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

     /* OPERATION TO FIND MINIMUM ELEMENT IN RIGHT SUBTREE */
     
struct BSTNode* findmin(struct BSTNode * root){
    while(root->left!=NULL)
        root=root->left;
    return root;
};

    /* SEARCH OPERATION */

struct BSTNode *find(struct BSTNode *root,int data){
    if(root==NULL)
        return(NULL);
    else if(data < root->data)
        return(find(root->left,data));
    else if(data > root->data)
        return(find(root->right,data));
    return root;
} 
     /* DELETION OPERATION */
struct BSTNode *deleteNode(struct BSTNode * root, int data)
{
    struct BSTNode *temp;
    if(root==NULL)
        return(root);
    else if(data<root->data)
        root->left=deleteNode(root->left,data);
    else if(data > root->data)
        root->right= deleteNode(root->right,data);
    else{
         if(root->left==NULL){
            temp=root;
            root=temp->right;
            free(temp);
        }
        else if(root->right==NULL){
            temp=root;
            root=temp->left;
            free(temp);
        }
        else{
            temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}

    /* TREE TRAVERSAL */
    
void inorder(struct BSTNode *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);

        inorder(root->right);
    }
}
void preorder(struct BSTNode *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct BSTNode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

    /* MAIN FUNCTION */

int main()
{
    struct BSTNode *temp; 
    struct BSTNode *root = NULL;
    int ch,data,item,x,z;
    int n;
    
    printf("\nHow many data do you want to enter: ");
    scanf("%d",&n);
    printf("\nPlease enter the data in the tree: ");
    
    for (int i = 0; i < n; i++){
        scanf("%d",&z);
        root=insert(root, z);
    }
    while(1)
    {
        printf("\n1. To Insert");
        printf("\n2. To Delete");
        printf("\n3. Preorder Traversal");
        printf("\n4. Inorder traversal");
        printf("\n5. postorder Traversal");
        printf("\n6. To search an element");
        printf("\n7. To Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                printf("\nEnter the data to delete: ");
                scanf("%d",&item);
                deleteNode(root,item);
                break;
            case 3:
                printf("\nPreorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("\nInorder: ");
                inorder(root);
                break;
            case 5:
                printf("\nPostorder: ");
                postorder(root);
                break;
            case 6:
                printf("\nPLEASE ENTER THE ELEMENT TO SEARCH: ");
                scanf("%d",&x);
                temp=find(root,x);
                if(temp==NULL){
                    printf("\n%d is Not found in the tree",x);
                }
                else{
                    printf("\n %d is present in the tree\n",temp->data);
                }
                break;

            case 7:
                exit(1);
            default:
                printf("\nInvalid input please enter a valid input");
        }
    }
}