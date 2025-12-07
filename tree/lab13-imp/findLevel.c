#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    struct Node *left, *right;
} node;

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findLevel(node *root, char target, int level)
{
    if (!root)
        return -1;
    else if (root->data == (target))
        return level;
    int leftlevel = findLevel(root->left, target, level + 1);
    if (leftlevel != -1)
        return leftlevel;

    return findLevel(root->right, target, level + 1);
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

int main()
{
    node *root = createNode('*');
    root->left = createNode('5');
    root->right = createNode('+');
    root->right->left = createNode('3');
    root->right->right = createNode('4');

    inorder(root);

    char c;
    printf("\nEnter the character to find the level: ");
    scanf("%c", &c);

    printf("%d\n", findLevel(root, c, 0));
    return 0;
}
