Got it Ayush 👌 — here’s a **focused cheat sheet just for Kth Largest and Kth Smallest using Heaps**. This is the part you’ll want to revise quickly before viva/exam.

---

# 📘 Cheat Sheet: Kth Largest & Kth Smallest (Heaps)

---

## 🔎 1. Kth Smallest (Min Heap Method — simplest)
- **Build a Min Heap** → root is always the smallest.
- **Extract root `k` times**.
- The last extracted root = **Kth smallest**.

### Code
```c
int extractMin(int arr[], int *n) {
    int min = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapifyMin(arr, *n, 0);
    return min;
}

int kthSmallest(int arr[], int n, int k) {
    buildHeapMin(arr, n);
    int result = -1;
    for (int i = 0; i < k; i++)
        result = extractMin(arr, &n);
    return result;
}
```

👉 Example: Array `[5,10,20,30,50,80,85,90,100]`, `k=4` → **30**

---

## 🔎 2. Kth Largest (Max Heap Method — simplest)
- **Build a Max Heap** → root is always the largest.
- **Extract root `k` times**.
- The last extracted root = **Kth largest**.

### Code
```c
int extractMax(int arr[], int *n) {
    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapifyMax(arr, *n, 0);
    return max;
}

int kthLargest(int arr[], int n, int k) {
    buildHeapMax(arr, n);
    int result = -1;
    for (int i = 0; i < k; i++)
        result = extractMax(arr, &n);
    return result;
}
```

👉 Example: Array `[5,10,20,30,50,80,85,90,100]`, `k=2` → **90**

---

## 🔎 3. Alternative (Using Opposite Heap)
- **Kth smallest with Max Heap**: extract max `n - k + 1` times.  
- **Kth largest with Min Heap**: extract min `n - k + 1` times.  
- Works, but less intuitive.

---

## 🔎 4. Time Complexity
- **Build Heap**: O(n)  
- **Each extract**: O(log n)  
- **K extracts**: O(k log n)  
- Total: O(n + k log n)

---

## ⚖️ Quick Revision Points
- **Min Heap → kth smallest** (extract k times).  
- **Max Heap → kth largest** (extract k times).  
- Opposite heap requires `n - k + 1` extracts.  
- Complexity: O(n + k log n).  

---

👉 Do you want me to also add a **tiny dry run example** (like step-by-step for kth largest = 3) so you can visualize the extraction process instantly?