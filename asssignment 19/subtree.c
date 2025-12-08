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

int isSameTree(node *a, node *b)
{
    if (!a && !b)
        return 1;
    if (!a || !b)
        return 0;
    if (a->data != b->data)
        return 0;
    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
int isSubTree(node *T, node *S)
{
    if (!S)
        return 1;
    if (!T)
        return 0;
    if (isSameTree(T, S))
        return 1;
    return isSubTree(T->left, S) || isSubTree(T->right, S);
}

int main()
{
    int tree[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int subtree[] = {5, 6, 7, 8};
    int subtree[] = {0, 33, 7, 11};

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

    if (isSubTree(root1, root2))
        printf("Yes");
    else
        printf("NO");

    return 0;
}
