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

int getbalance(node *a)
{
    return a ? (height(a->left) - height(a->right)) : 0;
}

node *createNode(int key)
{
    node *newNode = malloc(sizeof(node));
    newNode->left = newNode->right = NULL;
    newNode->data = key;
    newNode->height = 1;
    return newNode;
}

node *leftRotate(node *root)
{
    node *newroot = root->right;
    node *temp = newroot->left;

    newroot->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;

    return newroot;
}

node *rightRotate(node *root)
{
    node *newroot = root->left;
    node *temp = newroot->right;

    newroot->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}

node *insert(node *root, int key)
{
    if (!root)
        return createNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else if (root->data < key)
        root->right = insert(root->right, key);
    else
        return root;

    // update height
    root->height = 1 + max(height(root->left), height(root->right));

    // get balance;
    int balance = getbalance(root);

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
    printf("%d : balance %d \n", root->data, getbalance(root));
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