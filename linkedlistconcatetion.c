#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;
struct Node *Evenhead=NULL;
struct Node *oddhead=NULL;
struct Node *createNode(int data)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}
struct Node *concatenate(struct Node* head)
{
    struct Node *temp;
    head=Evenhead;
    temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=oddhead;
    return head;
}
void viewlist() //Function to view list..
{
    struct Node *t;
    struct Node *root=concatenate(head);
    if(root==NULL)
        printf("list is empty");
    else{
        t=root;
        printf("\nList is: ");
        while(t!=NULL)
        {
            printf("%d-->",t->data);
            t=t->link;
        }
    }
}

void insert(int data)
{
    struct Node *temp=createNode(data);
    struct Node *curr;
    if(data%2==0)
    {
        if(Evenhead==NULL)
        {
            Evenhead=temp;
            return;
        }
        else{
            curr=Evenhead;
            while(curr->link!=NULL)
            {
                curr=curr->link;
                
            }
            curr->link=temp;
        }

    }
    else{
        if(oddhead==NULL)
        {
            oddhead=temp;
            return;
        }
        else{
            curr=oddhead;
            while(curr->link!=NULL)
            {
                curr=curr->link;
                
            }
            curr->link=temp;
        }
    }
   
}
int main()
{
    int x;
    while(1)
    {
        int ch;
        printf("\n1. To insert data");
        printf("\n2. To view data");
        printf("\n3. To exit");
        printf("\nPlease enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
              printf("Enter the data to insert: ");
              scanf("%d",&x);
              insert(x);
              break;
            case 2:
               viewlist();
               break;
            case 3:
               exit(1);
            default:
               printf("Invalid input\n");
              
        }
    }
}