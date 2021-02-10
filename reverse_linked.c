/* ABHIJEET ANAND
   ROLL: 19103001 
   LAB/EXPERIMENT: 05 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

  /*STRUCTURE OF LINKED LIST*/

struct Node
{
    int data;
    struct Node *next;
   
};
   /* INITIALISATION OF HEAD */

struct Node *head=NULL;


   /* CREATING THE NODE*/

struct Node* createNode()
{
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    return(n);

}

   /* INSERTING DATA */

struct Node* createlinkedlist()
{
    printf("Please Enter The Data with Space Seperated Integers And Enter -1 To Stop Taking Input from user:\n");
    int data;
    scanf("%d",&data);
    struct Node* temp = NULL;
    // struct Node* list = NULL;
    while(data != -1)
    {
        struct Node* current = createNode();
        current->data = data;
        
        if(head == NULL)
        {
            head = current;
            temp = current;
        }
        else
        {
            temp->next = current;
            temp = current;
        }
        scanf("%d",&data);
    }
    if(temp == NULL)
    {
        printf("No Data Entered In The List !!\n");
        return NULL;
    }
    else
    {
        temp->next = NULL;
        return head;
    }
}
 
  /*PRINT THE ELEMENT OF THE LIST*/

void printlist(struct Node *head)
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("List is Empty..");
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("  %d --> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

  /*REVERSING THE LIST*/

struct Node* reverselist(struct Node *head)
{
    struct Node *prevNode,*nextnode,*current;
    current=head;
    prevNode=NULL;
    nextnode=NULL;
    while (current!=NULL)
    {
        nextnode=current->next;
        current->next=prevNode;
        prevNode=current;
        current=nextnode;
    }
    head=prevNode;
    return head;
}

   /* MAIN FUNCTION */

int main()
{
    struct Node* list = createlinkedlist();
    printf("\nList is: \n");
    printlist(list);
    struct Node *x=reverselist(list);
    printf("\n");
    printf("\nAfter reversing list is: \n");
    printlist(x);
    printf("\n");
}
