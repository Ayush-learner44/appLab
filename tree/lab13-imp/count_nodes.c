#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 100

typedef struct Node
{
    char data;
    struct Node *left, *right;
} node;

node *createNode(char data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *queue[Max] = {0};
int front = -1, rear = -1;

int isEmpty()
{
    if (front > rear || rear == -1)
        return 1;
    return 0;
}

void enqueue(node *data)
{
    if (rear >= (Max - 1))
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = data;
}

node *dequeue()
{
    if (front > rear || rear == -1)
        return NULL;
    return queue[front++];
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void levelOrder(node *root)
{
    if (!root)
        printf("Empty!\n");
    enqueue(root);

    node *temp;
    while (!isEmpty())
    {
        node *c = dequeue();
        printf("%c ", c->data);
        if (c->left)
            enqueue(c->left);
        if (c->right)
            enqueue(c->right);
    }
    printf("\n");
}

int countTotalNodes(node *root)
{
    if (!root)
        return 0;
    return 1 + (countTotalNodes(root->left) + countTotalNodes(root->right));
}

int externalNodes(node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return externalNodes(root->left) + externalNodes(root->right);
}

int main()
{
    node *root = createNode('*');
    root->left = createNode('5');
    root->right = createNode('+');
    root->right->left = createNode('3');
    root->right->right = createNode('4');

    inorder(root);
    printf("\n");
    levelOrder(root);

    printf("\nThe number of totalnodes: %d\n", countTotalNodes(root));
    printf("\nThe number of external nodes: %d\n", externalNodes(root));
    printf("\nThe number of internal nodes: %d\n", countTotalNodes(root) - externalNodes(root));

    return 0;
}
