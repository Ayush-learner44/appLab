Perfect Ayush 👌 — let’s refine the cheat sheet exactly as you asked: keep the **dry run only for Max Heap**, just note the **changes for Min Heap**, and add a **time complexity section** for all key operations.  

---

# 📘 Heap Cheat Sheet (Lab 14 Q5)

---

## 🔎 1. What is a Heap?
- A **complete binary tree** stored in an array.  
- Two types:
  - **Max Heap** → parent ≥ children (largest at root).  
  - **Min Heap** → parent ≤ children (smallest at root).  
- Array mapping:
  - Parent at index `i`.  
  - Left child → `2*i + 1`.  
  - Right child → `2*i + 2`.

---

## 🔎 2. Building a Heap
- Start from the **last internal node** (`n/2 - 1`).  
- Go backwards (`i--`) so children are heapified before parents.  
- Use **heapify** to enforce heap property.

### Code Snippet (Max Heap)
```c
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
```

---

## 🔎 3. Traversals
Treat array as a binary tree:
```c
void inorder(int arr[], int n, int i) {
    if (i >= n) return;
    inorder(arr, n, 2*i+1);
    printf("%d ", arr[i]);
    inorder(arr, n, 2*i+2);
}

void preorder(int arr[], int n, int i) {
    if (i >= n) return;
    printf("%d ", arr[i]);
    preorder(arr, n, 2*i+1);
    preorder(arr, n, 2*i+2);
}

void postorder(int arr[], int n, int i) {
    if (i >= n) return;
    postorder(arr, n, 2*i+1);
    postorder(arr, n, 2*i+2);
    printf("%d ", arr[i]);
}
```

---

## 🔎 4. Dry Run (Max Heap)

Input array:
```
[50, 10, 20, 30, 5, 90, 80, 100, 85]
```

Final Max Heap array:
```
[100, 85, 90, 50, 5, 20, 80, 30, 10]
```

Tree form:
```
        100
       /   \
     85     90
    / \    / \
  50   5  20  80
 / \
30  10
```

---

## 🔎 5. Min Heap Changes
Only change the comparison in `heapify`:

```c
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyMin(arr, n, smallest);
    }
}
```

👉 Everything else (buildHeap, traversals) stays the same.

---

## 🔎 6. Time Complexity of Heap Operations

| Operation        | Time Complexity | Notes |
|------------------|-----------------|-------|
| **Build Heap**   | O(n)            | Bottom‑up heapify is linear. |
| **Heapify**      | O(log n)        | Fixes one subtree, height = log n. |
| **Insertion**    | O(log n)        | Insert at end, bubble up. |
| **Deletion (root)** | O(log n)     | Replace root with last element, heapify down. |
| **Find Max (Max Heap)** | O(1)     | Root element. |
| **Find Min (Min Heap)** | O(1)     | Root element. |
| **Search (arbitrary element)** | O(n) | Heap is not ordered like BST, must scan array. |
| **Update key**   | O(log n)        | Increase/decrease key, bubble up/down. |

---

## ⚖️ Quick Revision Points
- **Heapify** → enforces heap property at one node.  
- **BuildHeap** → bottom‑up, start at `n/2 - 1`.  
- **Max Heap vs Min Heap** → only difference is comparison (`>` vs `<`).  
- **Complexities**:  
  - Build = O(n)  
  - Insert/Delete = O(log n)  
  - Find root = O(1)  
  - Search arbitrary = O(n)  

---

