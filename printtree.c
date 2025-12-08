
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