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

int isStrict(node *root)
{
    if (!root)
        return 1;
    if (!root->right && !root->left)
        return 1;
    if (!root->right || !root->left)
        return 0;
    return isStrict(root->left) && isStrict(root->right);
}
int main()
{
    // int pre[] = {'*', '5', '+', '3', '4'};
    // int in[] = {'5', '*', '3', '+', '4'};

    int pre[] = {'A', 'B', 'C'}; // Preorder: Root, Left, Right
    int in[] = {'C', 'B', 'A'};  // Inorder: Left, Root, Right

    node *root = buildTree(pre, in, 0, 2);
    postorder(root);

    if (isStrict(root))
        printf("Yes this is strict!!\n");
    else
        printf("Not strict!!\n");

    return 0;
}