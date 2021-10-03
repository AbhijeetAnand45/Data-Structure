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

// Height of binary tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return min(height(root->left),height(root->right)) + 1;
}
// Diameter of a Binary Tree i.e. longest path
int CalcDiameter(Node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left)+height(root->right)+1,max(CalcDiameter(root->left),CalcDiameter(root->right)));
}
// No of nodes in tree
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
// sum of all nodes in tree
int sumNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(6);
    root->left->left= new Node(8);
    root->left->right = new Node(9);
    root->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(11);
    root->right->left->left = new Node(12);
    cout<<"Height of tree is "<<height(root);
    cout<<"\nNo. of Nodes in the tree "<<countNodes(root);
    cout<<"\nSum of all Nodes of the tree "<<sumNodes(root);
    cout<<"\nDiameter of tree is "<<CalcDiameter(root);
    return 0;

}

/*
              5
             / \
            6   7
           / \  / \
          8  9  10 11
               /
              12

*/