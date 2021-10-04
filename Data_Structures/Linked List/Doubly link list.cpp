
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* AdtoEmpty(struct Node* head,int data)
{
    struct Node* temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct Node* addAtEnd(struct Node* head,int data)
{
    struct Node* temp, *tp;
    temp=malloc(sizeof(struct Node));
    temp->prev= NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL)
        tp=tp->next;
    tp->next=temp;
    temp->prev= tp;
    return head;
  //  printf("hk");
};
struct Node* delFirst(struct Node*  head)
{
    struct Node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
};
void print(struct Node* head)
{
    struct Node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node* addAfterPos(struct Node* head ,int data, int position)
{
    struct Node* newp=NULL;
    struct Node* temp=head;
    struct Node* temp2=NULL;
    newp=AdtoEmpty(newp,data);
    while(position !=1)
    {
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL ) //last node
    {
        temp->next =newp;
        newp->prev=temp;
    }
    else
    {
        temp2->next=newp;
        temp->prev =newp;
        newp->prev=temp;
        newp->next=temp2;
    }
};
int main()
{
    struct Node* head=NULL;
    struct Node* ptr;
    int position =1;
   // head=AdtoBeg(head,44);
    head=AdtoEmpty(head,40);
    head=addAtEnd(head,55);
    head=addAtEnd(head,60);
    printf("before deletion: \n");
    print(head);
    printf("\n");
    head =delFirst(head);
    printf("after delete :  \n");
    print(head);

    head= addAfterPos(head, 32,position);
    print(head);
    ptr=head;

    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
    return 0;
}


