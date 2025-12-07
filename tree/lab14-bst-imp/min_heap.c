#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void preorder(int arr[], int n, int i)
{
    if (i >= n)
        return;
    printf("%d ", arr[i]);
    preorder(arr, n, 2 * i + 1);
    preorder(arr, n, 2 * i + 2);
}
void inorder(int arr[], int n, int i)
{
    if (i >= n)
        return;
    inorder(arr, n, 2 * i + 1);
    printf("%d ", arr[i]);
    inorder(arr, n, 2 * i + 2);
}
void postorder(int arr[], int n, int i)
{
    if (i >= n)
        return;
    postorder(arr, n, 2 * i + 1);
    postorder(arr, n, 2 * i + 2);
    printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printf("Heap (array form): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Inorder: ");
    inorder(arr, n, 0);
    printf("\n");

    printf("Preorder: ");
    preorder(arr, n, 0);
    printf("\n");

    printf("Postorder: ");
    postorder(arr, n, 0);
    printf("\n");

    return 0;
}