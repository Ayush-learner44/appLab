#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node *insertBST(struct Node *root, int data)
{
    if (!root)
        return newNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    return root;
}

// Inorder traversal to collect sorted values
void inorder(struct Node *root, int arr[], int *idx)
{
    if (!root)
        return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->data;
    inorder(root->right, arr, idx);
}

// Postorder traversal to assign values from sorted array
void postorderAssign(struct Node *root, int arr[], int *idx)
{
    if (!root)
        return;
    postorderAssign(root->left, arr, idx);
    postorderAssign(root->right, arr, idx);
    root->data = arr[(*idx)--];
}

// Convert BST to Max Heap
void convertBSTtoMaxHeap(struct Node *root)
{
    int arr[100], idx = 0;
    inorder(root, arr, &idx); // collect sorted values
    idx--;                    // point to last element
    postorderAssign(root, arr, &idx);
}

// Preorder traversal to print Max Heap
void preorder(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    // BST from Lab 15 diagram: 4, 2, 6, 1, 3, 5, 7
    int values[] = {4, 2, 6, 1, 3, 5, 7};
    int n = sizeof(values) / sizeof(values[0]);

    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insertBST(root, values[i]);

    printf("BST Preorder: ");
    preorder(root);
    printf("\n");

    convertBSTtoMaxHeap(root);

    printf("Max Heap Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}
