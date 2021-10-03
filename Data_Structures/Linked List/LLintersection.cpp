
/*

    Input:
        L1 = 1->2->3->4->6
        L2 = 2->4->6->8
    Output: 2 4 6

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    public:

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* intersection(Node* temp1,Node* temp2){
   
    Node* dummyhead = new Node(0);
    Node* head = dummyhead;


    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data == temp2->data){
            head->next = new Node(temp1->data);
            head = head->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data)
            temp1 = temp1->next;
        else
            temp2 = temp2->next;
    }
    return dummyhead->next;
}
  



int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);


    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);


    Node* head3 = intersection(head1,head2);

    while(head3 != NULL){
        cout<<head3->data<<" ";
        head3 = head3->next;
    }


    return 0;
}
