#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct Node
{
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

// Create new node
Node *newNode(char data, unsigned freq)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Compare function for qsort
int compare(const void *a, const void *b)
{
    return ((Node *)a)->freq - ((Node *)b)->freq;
}

Node *buildHuffmanTree(Node nodes[], int size)
{
    while (size > 1)
    {
        qsort(nodes, size, sizeof(Node), compare);

        Node *left = newNode(nodes[0].data, nodes[0].freq);
        left->left = nodes[0].left;
        left->right = nodes[0].right;

        Node *right = newNode(nodes[1].data, nodes[1].freq);
        right->left = nodes[1].left;
        right->right = nodes[1].right;

        Node top = {'\0', left->freq + right->freq, left, right};

        nodes[0] = top;
        nodes[1] = nodes[size - 1];
        size--;
    }
    return &nodes[0]; // FIX: return the actual root node
}

// Print Huffman Codes
void printCodes(Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    {
        printf("'%c' | ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    char str[1000];
    printf("Enter string: ");
    scanf("%[^\n]", str);

    int freqMap[256] = {0};
    for (int i = 0; str[i]; i++)
        freqMap[(unsigned char)str[i]]++;

    Node nodes[256];

    int size = 0;
    for (int i = 0; i < 256; i++)
    {
        if (freqMap[i])
        {
            nodes[size++] = *newNode((char)i, freqMap[i]);
        }
    }

    if (size == 0)
    {
        printf("Empty string!\n");
        return 0;
    }

    Node *root = buildHuffmanTree(nodes, size);
    int arr[MAX_TREE_HT];
    printCodes(root, arr, 0);

    return 0;
}
