#include <stdio.h>
#include <stdlib.h>

int preindex = 0;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

int search(int arr[], int val, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
node *buildTree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    node *root = createNode(preorder[preindex++]);

    if (start == end)
        return root;

    int rootIndex = search(inorder, root->data, start, end);

    root->left = buildTree(preorder, inorder, start, rootIndex - 1);
    root->right = buildTree(preorder, inorder, rootIndex + 1, end);
    return root;
}
void postorder(node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    int pre[] = {'*', '5', '+', '3', '4'};
    int in[] = {'5', '*', '3', '+', '4'};

    node *root = buildTree(pre, in, 0, 5);
    postorder(root);
    return 0;
}