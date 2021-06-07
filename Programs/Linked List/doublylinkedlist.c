/*NAME : ABHIJEET ANAND
  ROLL : 19103001
  EXPERIMENT/LAB : 6
  DATE : 05/10/2020 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

    /* STRUCTURE OF DOUBLY LINKED LIST */

struct Node
{
    int data;
    struct Node *prev,*next;
    
};

   /* INITIALISATION OF HEAD */

struct Node *head=NULL;

     /* CREATING NODE */

struct Node* createNode()
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    return(n);
}

      /* INSERTING AT BEGINING */

void insertAtBeg()
{
    struct Node *temp=createNode();
    printf("Enter the data to insert: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        head->prev=temp;
        temp->next=head;
        head=temp;
        
    }
}

    /* INSERTING DATA AT THE END */

void insertAtEnd()
{
    struct Node *n,*temp;
    n=createNode();
    if(head==NULL)
        printf("Overflow");
    else{
    printf("Enter the data to insert: ");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;
    if(head==NULL)
    {
        n->next=NULL;
        n->prev=NULL;
        head=n;
    }
    else
    {
       temp=head;
       while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n;
        n->prev=temp;
        n->next=NULL;

    }
    }
}

   /* INSERTING AT A SPECIFIC POSITION */

void InsertAtPosition()
{
    struct Node* temp=createNode();
    struct Node *p;
    int x,i=1;
    printf("Enter the position where you want to insert data: ");
    scanf("%d",&x);
    printf("Enter the data to insert: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    p=head;
    while(i<x)
    {
        p=p->next;
        i++;
    }
    temp->next=p->next;
    temp->prev=p;
    p->next=temp;
    if(p->next!=NULL)
      p->next->prev=temp;

} 

   /* DELETING FIRST NODE */

void deletebeg()
{
    struct Node* p;
    if(head==NULL)
    {
        printf("list is empty.");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
        p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
}
   /* DELETING LAST NODE */

void deleteAtEnd()
{
    struct Node *p;
    
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
        p=head;
        while(p->next!=NULL)
        {
         p=p->next;
        }
        p->prev->next=NULL;
        free(p);

    }  
}

   /* TO FIND LENGTH OF LIST */

int length()
{
    struct Node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
} 

  /* DELETING AT A SPECIFIC POSITION */

void deleteAtposition()
{
    struct Node *p;
    int loc;
    int i=1;
    printf("Please Enter the Location to delete: ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location");
        return;
    }
    p=head;
    while(i<loc)
    {
        p=p->next;
        i++;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
}

   /* TRAVERSING THE LIST */

void viewlist()
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("list is empty.");
    }
    else{
         temp=head;
         printf("Doubly Linked list is: ");
         while(temp!= NULL)
        {
           printf("%d<-->",temp->data);
           temp=temp->next;
        }
    }  
} 
   /* CREATING THE LIST */

void createlist()
{
    printf("Please Enter The Data with Space Seperated Integers And Enter -1 To Stop Taking Input from user:\n");
    int data;
    scanf("%d",&data);
    struct Node* temp = NULL;
    while(data!=-1)
    {
        struct Node *n=createNode();
        
        n->data=data;
        
        if(head==NULL)
       {
        n->next=NULL;
        n->prev=NULL;
        head=n;
        temp=n;
       }
       else
      {
        
          temp->next=n;
          n->prev=temp;
          temp=n;

       }
       scanf("%d",&data);
    }
    if(head==NULL)
    {
        printf("List is empty..please enter any No.");
        return;
    }
    else{
        temp->next=NULL;
    }

    }

  /* MAIN FUNCTION */

int main()
{
    struct Node *temp;
    createlist();
    viewlist();


    int ch;
    while(1)
    {
    
        printf("\n1. To Insert at beginning of list");
        printf("\n2. To Insert at End of list");
        printf("\n3. To insert at any position of list");
        printf("\n4. To dalete from beginning of list");
        printf("\n5. To delete from end of list");
        printf("\n6. To delete from any specific position of list");
        printf("\n7. To Exit.");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               insertAtBeg();
               viewlist();
               break;
            case 2:
               insertAtEnd();
               viewlist();
               break;
            case 3:
               InsertAtPosition();
               viewlist();
               break;
            case 4:
               deletebeg();
               viewlist();
               break;
            case 5:
               deleteAtEnd();
               viewlist();
               break;
            case 6:
               deleteAtposition();
               viewlist();
               break;  
            case 7:
               exit(1);
            default:
               printf("Invalid choice");

        }

    }
}
