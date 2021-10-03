 /*  EXPERIMENT- 8 IMPLEMENTATION OF STACK USING LINKED LIST
     NAME: ABHIJEET ANAND
     ROLL: 19103001 
                       */
#include<stdio.h>
#include<stdlib.h>

    /* STRUCTURE OF NODE */

struct Node
{
    int data;
    struct Node *link;
    
};
    /* INITIALISATION OF TOP */
struct Node *top=NULL;

     /* CREATING NODE */
struct Node *createNode()
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    return n;
}
     /* CREATING STACK TO TAKE INPUT FROM USER*/
void createstack()
{
    
    int data;
    printf("\nPLEASE ENTER THE DATA YOU WANT TO STORE IN STACK AND PRESS -1 TO STOP TAKING INPUT: \n");
    scanf("%d ",&data);
   

    while(data!=-1)
    {
        struct Node *temp=createNode();
        temp->data=data;
        temp->link=top;
        top=temp;
        scanf("%d",&data);
    }
    
    if(top==NULL)
    {
        printf("YOU HAVE NOT ENTERED ANY DATA");
        return;
    }
}

    /* PUSHING ELEMENT INTO STACK */
void push()
{
    struct Node *temp=createNode();
    printf("PLEASE ENTER THE DATA TO PUSH INTO STACK: ");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}
    /* CHEAK IF STACK IS EMPTY */
int isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}
    /* DELETING ELEMENT FROM THE STACK */
void pop()
{
    struct Node *temp;
    if(!isempty())
    {
        temp=top;
        printf("POPPED ELEMENT IS %d",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
    else{
        printf("STACK IS EMPTY\n");
    }   
}
     
     /* TARVERSING THE ELEMENTS OF STACK */
void traverse()
{
    struct Node *temp;
    if(top==NULL)
    {
        printf("\nERROR,YOU ARE TRYING TO TRAVERSE AN EMPTY STACK");

    }
    else{
        temp=top;
        printf("\nSTACK ELEMENTS ARE: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}
   
     /* FINDING TOP ELEMENT */
void topelement()
{
    if(top==NULL)
    {
        printf("NO ELEMENT IS PRESENT IN THE STACK\n");
    }
    else{
        printf("Top element = %d",top->data);
    }
}

      /* MAIN FUNCTION */
int main()
{
    createstack();
    traverse();


    int n,ch;
    while(1)
    {
        printf("\n1. To push element into stack");
        printf("\n2. To pop/delete element from stack");
        printf("\n3. To view element of the stack");
        printf("\n4. To check stack is empty or not");
        printf("\n5. To find top element");
        printf("\n6. To exit loop\n");
        printf("\nPLEASE ENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               push();
               traverse();
               break;
            case 2:
               pop();
               traverse();
               break;
            case 3:
               traverse();
               break;
            case 4:
               n=isempty();
               if(n==1)
               {
                   printf("STACK IS EMPTY!!");
               }
               else{
                   printf("STACK IS NOT EMPTY !!");
               }
               break;
            case 5:
               topelement();
               break;
            case 6:
               exit(1);
            default:
               printf("\nINVALID CHOICE");

        }
    }
}
