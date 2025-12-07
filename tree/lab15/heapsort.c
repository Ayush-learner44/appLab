#include <stdio.h>

void heapifymin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifymin(arr, n, smallest);
    }
}

void heapifymax(int arr[], int n, int i)
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
        heapifymax(arr, n, largest);
    }
}

void buildheap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapifymin(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildheap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapifymax(arr, i, 0);
    }
}

int extractMax(int arr[], int *n)
{
    int max = arr[0];
    arr[0] = arr[*n - 1];

    (*n)--;
    heapifymax(arr, *n, 0);
    return max;
}

int kthMin(int arr[], int n, int k)
{
    int result = -1;
    buildheap(arr, n);

    for (int i = 0; i < n - k + 1; i++)
    {
        result = extractMax(arr, &n);
    }
    return result;
}

int kthmin(int arr[], int n, int k)
{
    buildheap(arr, n);
    int result = -1;
    for (int i = 0; i < k; i++)
    {
        arr[0] = arr[n - 1];
        result = arr[0];
        buildheap(arr, n - 1);
    }
    return result;
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

    printf("Heap (array form): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // heapSort(arr, n);

    // printf("Heap sorted: ");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");

    printf("The 4th min is %d\n", kthmin(arr, n, 4));

    printf("Inorder: ");
    inorder(arr, n, 0);
    printf("\n");

    return 0;
}