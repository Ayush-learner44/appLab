#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} node;

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(node *root)
{
    return root ? root->height : 0;
}
int getBalance(node *root)
{
    if (root)
        return (height(root->left) - height(root->right));
    return 0;
}

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    newNode->height = 1;

    return newNode;
}

node *leftRotate(node *root)
{
    node *newroot = root->right;
    node *temp = newroot->left;

    newroot->left = root;
    root->right = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    newroot->height = 1 + max(height(newroot->left), height(newroot->right));

    return newroot;
}

node *rightRotate(node *root)
{
    node *newRoot = root->left;
    node *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

node *insert(node *root, int key)
{
    if (!root)
        return createNode(key);

    // insertion bst;
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // new height
    root->height = 1 + max(height(root->right), height(root->left));

    // getbalance
    int balance = getBalance(root);

    // arrange the tree
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if (balance < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d : balance factor %d\n", root->data, getBalance(root));

    inorder(root->right);
}
int main()
{

    int keys[] = {40, 20, 10, 25, 30, 50, 60, 70, 65};
    int n = sizeof(keys) / sizeof(keys[0]);

    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, keys[i]);
    }

    inorder(root);
    return 0;
}