#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int key)
{
    if (!root)
        return createNode(key);
    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->data < key)
        root->right = insert(root->right, key);
    return root;
}

void search(node *root, int key)
{
    if (!root)
        printf("Empty!");
    if (root->data == key)
        printf("Key found!!\n");
    else if (key > root->data)
    {
        search(root->right, key);
    }
    else
        search(root->left, key);
}

node *minimum(node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
node *maximum(node *root)
{
    while (root && root->right)
    {
        root = root->right;
    }
    return root;
}

int findLevel(node *root, int key, int level)
{
    if (!root)
        return 0;
    if (root->data == key)
        return level;
    if (root->data > key)
    {
        int leftLevel = findLevel(root->left, key, level + 1);
        if (!leftLevel)
            return leftLevel;
    }
    return findLevel(root->right, key, level);
}

node *delete(node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            node *temp = minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Traversals
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    node *root = NULL;
    int choice, val;

    // Initial tree
    int values[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    for (int i = 0; i < 9; i++)
        root = insert(root, values[i]);

    while (1)
    {
        printf("\n--- BST Menu ---\n");
        printf("0. Find Minimum (Q4)\n");
        printf("8. Find Maximum (Q4)\n");
        printf("9. Find Level of a Node (Q3)\n");
        printf("1. Insert (Q2)\n");
        printf("2. Search (Q2)\n");
        printf("3. Delete (Q2)\n");
        printf("4. Inorder Traversal (Q1)\n");
        printf("5. Preorder Traversal (Q1)\n");
        printf("6. Postorder Traversal (Q1)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
        {
            node *min = minimum(root);
            printf("The min value is %d \n", min->data);
            break;
        }
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(root, val);

            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = delete(root, val);
            break;
        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        case 8:
        {
            node *max = maximum(root);
            printf("The max value is %d \n", max->data);
            break;
        }
        case 9:
        {
            printf("Enter value to find level: ");
            scanf("%d", &val);
            int level = findLevel(root, val, 0);
            if (level)
                printf("Level of %d is %d\n", val, level);
            else
                printf("%d not found in tree.\n", val);
            break;
        }

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}