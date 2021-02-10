#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* getNode(int data)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        root = getNode(data);
    }
    else if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void Inorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        Inorder(root->left);
        printf("%d\t",root->data);
        Inorder(root->right);
    }
    return;
}

struct Node* findkthSmallest(struct Node *root, int *count)
{
    if(root == NULL)
    {
        return NULL;
    }

    struct Node *left = findkthSmallest(root->left, count);

    if(left != NULL)
    {
        return left;
    }

    *count = *count - 1;
    if(*count == 0)
    {
        return root;
    }

    return findkthSmallest(root->right,count);
}

struct Node* findkthLargest(struct Node *root, int *count)
{
    if(root == NULL)
    {
        return NULL;
    }

    struct Node *right = findkthLargest(root->right, count);

    if(right != NULL)
    {
        return right;
    }
    *count = *count - 1;
    if(*count == 0)
    {
        return root;
    }

    return findkthLargest(root->left, count);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,30);
    root = insert(root,5);
    root = insert(root,15);
    int count = 1;

    struct Node *result = findkthSmallest(root,&count);
    printf("%d\n",result->data);

    int count1 = 1;
    struct Node *kthLargest = findkthLargest(root, &count1);
    printf("%d\n",kthLargest->data);
    

}