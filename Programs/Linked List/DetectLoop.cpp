#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    public:
    Node(){
        
    }
    Node(int val){
        data = val;
        next = NULL;
    }
    /* data */
};
// using Hashing
Node* DetectingLoop(Node* head){
    unordered_set<Node*> uset;
    Node* ptr = head;
    while(ptr != NULL){
        if(uset.find(ptr) != uset.end()){
            return ptr;
        }
        else{
            uset.insert(ptr);
        }
        ptr = ptr->next;
    }
    return NULL;
}
 // Using slow and fast pointer.
Node* detectloop(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(head == NULL && head->next == NULL){
        return NULL;
    }
    slow = slow->next;
    fast = fast->next->next;
    while(slow && fast->next){
        if(slow == fast){
            break;

        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast){
        return NULL;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main(){
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;
    // Node* res = detectloop(head);
    Node* res = DetectingLoop(head);
    if(res == NULL){
        cout<<"Loop doesn't Exist in the list";
    }
    else{
        cout<<"loop  exists at "<<res->data;
    }
    return 0;

}