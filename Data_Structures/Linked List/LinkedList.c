/*  CODE of SINGLY LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int loc;    //global variable..
struct node
{
    int info;
    struct node *link;
};
struct node *START=NULL;

   //creating Node
struct node* createNode()
{
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    return(n);
};


//To find length of linked list..

int findlength()
{
    int count=0;
    struct node *temp;
    temp=START;
    while(temp!=NULL)
      {
        count++;
        temp=temp->link;
      }
      return count;

}

    //inserting at beginning
void AddAtBeginning()      
{
    struct node *temp;
    temp=createNode();
    printf("Enter node data: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
        START=temp;
    else
    {
        temp->link=START;   /*right side connection*/
        START=temp;         /*left side connection*/
    }
}
void insertatEnd() /*Add at End*/
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter a number: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
        START=temp;
    else{
        t=START;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}
void insertafter()  //After a specific position
{
    struct node *temp,*p;
    int n,i=1;
    printf("Enter the location to insert element: ");
    scanf("%d",&n);
    temp=createNode();
    printf("Enter the data to insert: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    p=START;
    while(i<n)
    {
        p=p->link;
        i++;
    }
    temp->link=p->link;
    p->link=temp;
    //return START;
}

void deletefirstNode() //deleting first value
{
    struct node *r;
    if(START==NULL)
        printf("list is empty");
    else{
        r=START;
        START=START->link;
        free(r);
    }
}
void deletefromEnd()     //Deleting last value
    {
        struct node *p,*q;
        if(START == NULL)
        {
            printf("\nlist is empty");
        }
        else if(START->link == NULL)
        {
            START = NULL;
            free(START);

        }

        else
        {
            p = START;
            while(p->link != NULL)
            {
                    q = p;
                    p = p ->link;
            }
                q->link = NULL;
                free(p);

        }
    }
void deleteafter()  //deleting after a specific position..
{
    struct node *temp;
    int loc;
    printf("Enter location to delete: ");
    scanf("%d",&loc);
    if(loc>findlength())
    {
        printf("Invalid location\n");
    }
    else if(loc==1)
    {
        temp=START;
        START=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else{
        struct node *p=START,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);

    }

}
void viewlist() //Function to view list..
{
    struct node *t;
    if(START==NULL)
        printf("list is empty");
    else{
        t=START;
        printf("\nList is: ");
        while(t!=NULL)
        {
            printf("%d-->",t->info);
            t=t->link;
        }
    }
}
void createlist()
{
    printf("Please Enter The Data with Space Seperated Integers And Enter -1 To Stop Taking Input from user:\n");
    int data;
    scanf("%d",&data);
    struct node* temp = NULL;
    while(data!=-1)
    {
        struct node *n=createNode();

        n->info=data;

        if(START==NULL)
       {
        n->link=NULL;
        START=n;
        temp=n;
       }
       else
      {
          temp->link=n;
          temp=n;
       }
       scanf("%d",&data);
    }
    if(START==NULL)
    {
        printf("List is empty..please enter any No.");
        return;
    }
    else{
        temp->link=NULL;
    }
}

int main()
{
    struct node *temp;
    createlist();
    viewlist();

    while(1)
    {
        int ch;
        printf("\n1. Insert node at beginning of linked list");
        printf("\n2. Insert node at end of the list.");
        printf("\n3. Insert node at specific position.");
        printf("\n4. delete first node");
        printf("\n5. delete last node.");
        printf("\n6. delete node from specific position.");
        printf("\n7. Traverse/view the list.");
        printf("\n8. Exit.\n");

        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            AddAtBeginning();
            break;
        case 2:
            insertatEnd();
            break;
        case 3:
            insertafter();
            break;
        case 4:
            deletefirstNode();
            break;
        case 5:
            deletefromEnd();
            break;
        case 6:
            deleteafter();
            break;
        case 7:
            viewlist();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Invalid choice: ");

        }

    }
    return 0;
}

