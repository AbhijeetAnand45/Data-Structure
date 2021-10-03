#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int info){
        data = info;
        next = NULL;
    }
};

Node* ReverseinKsize(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* nextPtr = NULL;

    int count = 0;

    while(curr != NULL && count < k){
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
        count++;
    }

    if(nextPtr != NULL){
        head->next = ReverseinKsize(nextPtr,k);
    }
    return prev;
}
void InsertAttail(Node* &head, int val)
{
    Node* n = new Node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
int main(){

    Node* head = NULL;
    InsertAttail(head,1);
    InsertAttail(head,2);
    InsertAttail(head,3);
    InsertAttail(head,4);

    InsertAttail(head,5);
    InsertAttail(head,6);
    InsertAttail(head,7);
    InsertAttail(head,8);

    

    Node* temp = ReverseinKsize(head,3);

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;

}