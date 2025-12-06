#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
    int height;
} node;

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(node *a)
{
    return a ? a->height : 0;
}

int getBalance(node *n)
{
    return n ? (height(n->left) - height(n->right)) : 0;
}

node *createNode(int key)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

node *leftRotate(node *root)
{
    node *newRoot = root->right;
    node *temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    newRoot->height = max(height(newRoot->left), height(newRoot->right));
    root->height = max(height(root->left), height(root->right));

    return newRoot;
}

node *rightRotate(node *root)
{
    node *newRoot = root->left;
    node *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    newRoot->height = 1 + max(height(newRoot->right), height(newRoot->left));
    root->height = 1 + max(height(root->right), height(root->left));

    return newRoot;
}

node *insert(node *root, int key)
{
    if (!root)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // update height
    root->height = 1 + max(height(root->right), height(root->left));

    // balance factor
    int balance = getBalance(root);

    // check balance;
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int keys[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(keys) / sizeof(keys[0]);

    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, keys[i]);
    }

    printf("Inorder Traversal:\n");
    inorder(root);
    return 0;
}