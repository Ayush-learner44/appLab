#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;

node *root1 = NULL, *root2 = NULL;

node *createNode(int key)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *makeBT(node *root, int key)
{
    if (!root)
        return createNode(key);
    if (key < root->data)
        root->left = makeBT(root->left, key);
    else if (key > root->data)
        root->right = makeBT(root->right, key);

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

node *findlca(node *root, int a, int b)
{
    if (!root)
        return NULL;
    if (root->data > a && root->data > b)
    {
        return findlca(root->left, a, b);
    }
    else if (root->data < a && root->data < b)
    {
        return findlca(root->right, a, b);
    }
    return root;
}

void printTree(node *root, int space)
{
    if (!root)
        return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d ", root->data);
    printTree(root->left, space);
}
int main()
{
    int tree[] = {4, 2, 6, 1, 3, 5, 7, 8};

    int n = sizeof(tree) / sizeof(tree[0]);

    for (int i = 0; i < n; i++)
    {
        root1 = makeBT(root1, tree[i]);
    }

    printTree(root1, 0);
    printf("\n");

    node *temp = findlca(root1, 8, 5);
    if (temp)
    {
        printf("LCA: %d", temp->data);
    }
    else
        printf("No LCA");
    return 0;
}
