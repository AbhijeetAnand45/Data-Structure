
/* NAME : ABHIJEET ANAND
   ROLL : 19103001
   EXPERIMENT : 14  */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

  //node declaration
struct Node { 
   int data;
   struct Node* l;
   struct Node* r;
};
struct Node *root=NULL;
   //creation of new node
struct Node * createNode(int d) { 
   struct Node *n =(struct Node*)malloc(sizeof(struct Node));
   n->data = d;
   n->l = NULL;
   n->r = NULL;
   return(n);
}

  /* Find maximum between two value */

int max(int x, int y) { 
   return (x >= y)? x: y;
}
int height(struct Node* node) {  
   if(node == NULL)
      return 0;
   return 1 + max(height(node->l), height(node->r));
}

     /* CHECK FOR AVL */

bool AVL(struct Node *root) {
   int lh;
   int rh;
   if(root == NULL)
      return 1;
   lh = height(root->l); // left height
   rh = height(root->r); // right height
   if(abs(lh-rh) <= 1 && AVL(root->l) && AVL(root->r)) return 1;
   return 0;
}
    /* INSERTION */
struct Node *insert(struct Node *ptr, int ikey )
{
        if(ptr==NULL)
        {
                ptr = createNode(ikey);
        }
        else if(ikey < ptr->data) /*Insertion in left subtree*/
                ptr->l = insert(ptr->l, ikey);
        else if(ikey > ptr->data) /*Insertion in right subtree */
                ptr->r = insert(ptr->r, ikey);
        else
                printf("Duplicate key\n");
        // return(ptr);
}

   /* MAIN FUNCTION */

int main() {
 
        int choice,key;
        struct Node *root = NULL;
 
        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2. check Avl\n");
                
                printf("3.Quit\n");
 
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
 
                switch(choice)
                {
                  case 1:
                        printf("\nEnter the key to be inserted : ");
                        scanf("%d",&key);
                        root = insert(root,key);
                        break;
                  case 2:
                        if(AVL(root))
                            printf("\nThe Tree is AVL Tree\n");
                        else
                            printf("\nThe Tree is not AVL Tree\n");
                        break; 
                  case 3:
                        exit(1);
                  default:
                        printf("Wrong choice\n");
 
                }/*End of switch */
        }/*End of while */
 
  return 0;

}