#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    public:

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    
    /* data */
};

void levelOrder(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    cout<<"LevelOrder Traversal: ";
    levelOrder(root);
    cout<<"Inorder Traversal: ";
    inorder(root);
    return 0;
}
/*
     1
    / \
   2   3
  / \
 4  5

 */