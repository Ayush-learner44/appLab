#include <stdio.h>
#include <stdlib.h>

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
    int tree[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int subtree[] = {5, 6, 7, 8};

    int n = sizeof(tree) / sizeof(tree[0]);
    int m = sizeof(subtree) / sizeof(subtree[0]);

    for (int i = 0; i < n; i++)
    {
        root1 = makeBT(root1, tree[i]);
    }
    for (int i = 0; i < m; i++)
    {
        root2 = makeBT(root2, subtree[i]);
    }

    inorder(root1);
    printf("\n");
    inorder(root2);
    return 0;
}
